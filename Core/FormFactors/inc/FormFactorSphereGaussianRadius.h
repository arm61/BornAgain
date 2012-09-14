#ifndef FORMFACTORSPHEREGAUSSIANRADIUS_H_
#define FORMFACTORSPHEREGAUSSIANRADIUS_H_
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   FormFactorSphereGaussianRadius.h
//! @brief  Definition of mean form factor for sphere with a Gaussian radius distribution
//! @author Scientific Computing Group at FRM II
//! @date   Sep 13, 2012

class FormFactorSphereGaussianRadius : public IFormFactorBorn
{
public:
    FormFactorSphereGaussianRadius(double mean, double sigma);
    virtual FormFactorSphereGaussianRadius *clone() const;
    virtual ~FormFactorSphereGaussianRadius();

    virtual int getNumberOfStochasticParameters() const;
protected:
    virtual complex_t evaluate_for_q(const cvector_t &q) const;
private:
    double calculateMeanR3() const;
    double m_mean; //!< This is the mean radius
    double m_sigma;
    double m_mean_r3; //!< This is the radius that gives the mean volume
    IFormFactor *p_ff_sphere;
    cvector_t m_zero_vector;
};

inline FormFactorSphereGaussianRadius::FormFactorSphereGaussianRadius(double mean, double sigma)
: m_mean(mean)
, m_sigma(sigma)
, m_mean_r3(0.0)
, p_ff_sphere(0)
, m_zero_vector(0.0, 0.0, 0.0)
{
    m_mean_r3 = calculateMeanR3();
    p_ff_sphere = new FormFactorFullSphere(m_mean_r3);
}

inline FormFactorSphereGaussianRadius* FormFactorSphereGaussianRadius::clone() const
{
    return new FormFactorSphereGaussianRadius(m_mean, m_sigma);
}

inline FormFactorSphereGaussianRadius::~FormFactorSphereGaussianRadius()
{
    delete p_ff_sphere;
}
inline int FormFactorSphereGaussianRadius::getNumberOfStochasticParameters() const
{
    return 2;
}

inline complex_t FormFactorSphereGaussianRadius::evaluate_for_q(const cvector_t &q) const
{
    double q2 = std::norm(q.x()) + std::norm(q.y()) + std::norm(q.z());
    double dw = std::exp(-q2*m_sigma*m_sigma/2.0);
    return dw*p_ff_sphere->evaluate(q, m_zero_vector, 0.0, 0.0);
}

inline double FormFactorSphereGaussianRadius::calculateMeanR3() const
{
    return std::pow(m_mean*(m_mean*m_mean+3.0*m_sigma*m_sigma),1.0/3.0);
}

#endif /* FORMFACTORSPHEREGAUSSIANRADIUS_H_ */