#include "LayerDecoratorDWBASimulation.h"
#include "LayerDecorator.h"
#include "DWBAFormFactorConstZ.h"
#include "FormFactorDecoratorFactor.h"

LayerDecoratorDWBASimulation::LayerDecoratorDWBASimulation(
        const LayerDecorator *p_layer_decorator)
{
    mp_layer_decorator = p_layer_decorator->clone();
}

LayerDecoratorDWBASimulation::~LayerDecoratorDWBASimulation()
{
    delete mp_layer_decorator;
}

void LayerDecoratorDWBASimulation::run()
{
    m_dwba_intensity.resetIndex();
    double lambda = 2.0*M_PI/m_ki.mag();
    complex_t k_iz = -mp_kz_function->evaluate(-m_alpha_i);
    const NanoParticleDecoration *p_decoration = mp_layer_decorator->getDecoration();
    complex_t n_layer = mp_layer_decorator->getRefractiveIndex();
    size_t number_of_particles = p_decoration->getNumberOfParticles();
    std::vector<IFormFactor *> form_factors;
    for (size_t particle_index=0; particle_index<number_of_particles; ++particle_index) {
        NanoParticle *p_particle = p_decoration->getNanoParticle(particle_index)->clone();
        double depth = p_decoration->getDepthOfNanoParticle(particle_index);
        p_particle->setAmbientRefractiveIndex(n_layer);
        complex_t wavevector_scattering_factor = M_PI/lambda/lambda;
        DWBAFormFactorConstZ dwba_z(p_particle->createFormFactor(), depth);
        dwba_z.setReflectionFunction(*mp_R_function);
        dwba_z.setTransmissionFunction(*mp_T_function);
        FormFactorDecoratorFactor *p_ff = new FormFactorDecoratorFactor(dwba_z.clone(), wavevector_scattering_factor);
        form_factors.push_back(p_ff);
    }
    IInterferenceFunctionStrategy *p_strategy = p_decoration->createStrategy(form_factors);
    for (size_t i=0; i<form_factors.size(); ++i) {
        delete form_factors[i];
    }

    while (m_dwba_intensity.hasNext())
    {
        double phi_f = m_dwba_intensity.getCurrentValueOfAxis<double>("phi_f");
        double alpha_f = m_dwba_intensity.getCurrentValueOfAxis<double>("alpha_f");
        kvector_t k_f;
        complex_t k_fz = mp_kz_function->evaluate(alpha_f);
        k_f.setLambdaAlphaPhi(lambda, alpha_f, phi_f);
        m_dwba_intensity.next() = p_strategy->evaluateForComplexkz(m_ki, k_f, k_iz, k_fz);
    }
    delete p_strategy;
}

