#include "ISampleVisitor.h"
#include "ISample.h"
#include "ICompositeSample.h"
#include "ICompositeIterator.h"


void VisitSampleTree(const ISample &sample, ISampleVisitor &visitor)
{
    sample.accept(&visitor);
    const ICompositeSample *composite = sample.getCompositeSample();
    if(composite) {
        ICompositeIterator it = composite->createIterator();
        it.first();
        while( !it.is_done() ) {
            visitor.setLevel(it.get_level());
            ISample *child = it.get_current();
            child->accept(&visitor);
            it.next();
        }
    }
}



void ISampleVisitor::visit(const ISample *)
{
    throw NotImplementedException("ISampleVisitor::visit(const ISample *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const ICompositeSample *)
{
    throw NotImplementedException("ISampleVisitor::visit(const ICompositeSample *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const IClusteredParticles *)
{
    throw NotImplementedException("ISampleVisitor::visit(const IClusteredParticles *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const Crystal *)
{
    throw NotImplementedException("ISampleVisitor::visit(const Crystal *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const IDecoration *)
{
    throw NotImplementedException("ISampleVisitor::visit(const IDecoration *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const ParticleDecoration *)
{
    throw NotImplementedException("ISampleVisitor::visit(const ParticleDecoration *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const Layer *)
{
    throw NotImplementedException("ISampleVisitor::visit(const Layer *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const LayerInterface *)
{
    throw NotImplementedException("ISampleVisitor::visit(const LayerInterface *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const MultiLayer *)
{
    throw NotImplementedException("ISampleVisitor::visit(const MultiLayer *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const Particle *)
{
    throw NotImplementedException("ISampleVisitor::visit(const Particle *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const LatticeBasis *)
{
    throw NotImplementedException("ISampleVisitor::visit(const LatticeBasis *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const MesoCrystal *)
{
    throw NotImplementedException("ISampleVisitor::visit(const MesoCrystal *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const ParticleCoreShell *)
{
    throw NotImplementedException("ISampleVisitor::visit(const ParticleCoreShell *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const ParticleInfo *)
{
    throw NotImplementedException("ISampleVisitor::visit(const ParticleInfo *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const DiffuseParticleInfo *)
{
    throw NotImplementedException("ISampleVisitor::visit(const DiffuseParticleInfo *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const PositionParticleInfo *)
{
    throw NotImplementedException("ISampleVisitor::visit(const PositionParticleInfo *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const IFormFactor *)
{
    throw NotImplementedException("ISampleVisitor::visit(const IFormFactor *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorDWBAPol *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorDWBAPol *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorDWBAPolConstZ *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorDWBAPolConstZ *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorWeighted *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorWeighted *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const IFormFactorBorn *)
{
    throw NotImplementedException("ISampleVisitor::visit(const IFormFactorBorn *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorBox *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorBox *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorCone *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorCone *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorCone6 *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorCone6 *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorCrystal *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorCrystal *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorCylinder *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorCylinder *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorEllipsoid *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorEllipsoid *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorFullSphere *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorFullSphere *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorFullSpheroid *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorFullSpheroid *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorGauss *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorGauss *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorHemiSpheroid *)
{
    throw NotImplementedException("ISampleVisitor::visit const FormFactorHemiSpheroid *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorLorentz *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorLorentz *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorParallelepiped *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorParallelepiped *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorPrism3 *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorPrism3 *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorPrism6 *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorPrism6 *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorPyramid *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorPyramid *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorSphere *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorSphere *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorSphereGaussianRadius *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorSphereGaussianRadius *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorTetrahedron *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorTetrahedron *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const IFormFactorBornSeparable *)
{
    throw NotImplementedException("ISampleVisitor::visit(const IFormFactorBornSeparable *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const IFormFactorDecorator *)
{
    throw NotImplementedException("ISampleVisitor::visit(const IFormFactorDecorator *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorDWBA *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorDWBA *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorDWBAConstZ *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorDWBAConstZ *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorDecoratorDebyeWaller *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorDecoratorDebyeWaller *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorDecoratorFactor *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorDecoratorFactor *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorDecoratorMaterial *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorDecoratorMaterial *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorDecoratorMultiPositionFactor *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorDecoratorMultiPositionFactor *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorDecoratorPositionFactor *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorDecoratorPositionFactor *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const FormFactorDecoratorTransformation *)
{
    throw NotImplementedException("ISampleVisitor::visit(const FormFactorDecoratorTransformation *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const IInterferenceFunction *)
{
    throw NotImplementedException("ISampleVisitor::visit(const IInterferenceFunction *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const InterferenceFunction1DParaCrystal *){
    throw NotImplementedException("ISampleVisitor::visit(const InterferenceFunction1DParaCrystal *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const InterferenceFunction2DLattice *)
{
    throw NotImplementedException("ISampleVisitor::visit(const InterferenceFunction2DLattice *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const InterferenceFunction2DParaCrystal *)
{
    throw NotImplementedException("ISampleVisitor::visit(const InterferenceFunction2DParaCrystal *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const InterferenceFunctionNone *)
{
    throw NotImplementedException("ISampleVisitor::visit(const InterferenceFunctionNone *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const IRoughness *)
{
    throw NotImplementedException("ISampleVisitor::visit(const IRoughness *) -> Error. Not implemented.");
}


void ISampleVisitor::visit(const LayerRoughness *)
{
    throw NotImplementedException("ISampleVisitor::visit(const LayerRoughness *) -> Error. Not implemented.");
}


// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
bool  ISampleVisitor::visitEnter(const ICompositeSample *)
{
    m_level++;
    return false;
}

bool  ISampleVisitor::visitLeave(const ICompositeSample *)
{
    m_level--;
    return false;
}