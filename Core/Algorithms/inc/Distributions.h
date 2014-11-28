// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Algorithms/inc/Distributions.h
//! @brief     Defines classes representing distributions.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef DISTRIBUTIONS_H_
#define DISTRIBUTIONS_H_

#include "IParameterized.h"
#include "ParameterSample.h"

//! @class IDistribution1D
//! @ingroup algorithms_internal
//! @brief Interface for 1 dimensional distributions
class BA_CORE_API_ IDistribution1D : public IParameterized
{
public:
    IDistribution1D() {}
    virtual ~IDistribution1D() {}

    //! clone method
    virtual IDistribution1D *clone() const {
        throw NotImplementedException("IDistribution1D cannot be cloned");
    }

    //! get the probability density for value x
    virtual double probabilityDensity(double x) const=0;

    //! get the mean of the distribution
    virtual double getMean() const=0;

    //! generate list of sampled values with their weight
    std::vector<ParameterSample> generateSamples(size_t nbr_samples,
            double sigma_factor=0.0) const;

    //! generate list of sample values
    virtual std::vector<double> generateValueList(size_t nbr_samples,
            double sigma_factor) const=0;

protected:
    //! this function is called during bad initialization of a subclass
    static void SignalBadInitialization(std::string distribution_name);

};

//! @class DistributionGate
//! @ingroup algorithms
//! @brief uniform distribution function with half width hwhm
class BA_CORE_API_ DistributionGate : public IDistribution1D
{
public:
    DistributionGate();
    DistributionGate(double mean, double hwhm);
    virtual ~DistributionGate() {}

    //! clone method
    virtual DistributionGate *clone() const {
        return new DistributionGate(m_mean, m_hwhm);
    }

    //! get the probability density for value x
    virtual double probabilityDensity(double x) const;

    //! get the mean of the distribution
    virtual double getMean() const {
        return m_mean;
    }

    //! generate list of sample values
    virtual std::vector<double> generateValueList(size_t nbr_samples,
            double sigma_factor) const;

protected:
    //! Registers some class members for later access via parameter pool
    void init_parameters();

private:
    //! check initialization
    bool checkInitialization() const;
    double m_mean;
    double m_hwhm;
};

//! @class DistributionLorentz
//! @ingroup algorithms
//! @brief Lorentz distribution with half width hwhm
class BA_CORE_API_ DistributionLorentz : public IDistribution1D
{
public:
    DistributionLorentz();
    DistributionLorentz(double mean, double hwhm);
    virtual ~DistributionLorentz() {}

    //! clone method
    virtual DistributionLorentz *clone() const {
        return new DistributionLorentz(m_mean, m_hwhm);
    }

    //! get the probability density for value x
    virtual double probabilityDensity(double x) const;

    //! get the mean of the distribution
    virtual double getMean() const {
        return m_mean;
    }

    //! generate list of sample values
    virtual std::vector<double> generateValueList(size_t nbr_samples,
            double sigma_factor) const;

protected:
    //! Registers some class members for later access via parameter pool
    void init_parameters();
private:
    //! check initialization
    bool checkInitialization() const;
    double m_mean;
    double m_hwhm;
};

//! @class DistributionGaussian
//! @ingroup algorithms
//! @brief Gaussian distribution with standard deviation std_dev
class BA_CORE_API_ DistributionGaussian: public IDistribution1D
{
public:
    DistributionGaussian();
    DistributionGaussian(double mean, double std_dev);
    virtual ~DistributionGaussian() {}

    //! clone method
    virtual DistributionGaussian *clone() const {
        return new DistributionGaussian(m_mean, m_std_dev);
    }

    //! get the probability density for value x
    virtual double probabilityDensity(double x) const;

    //! get the mean of the distribution
    virtual double getMean() const {
        return m_mean;
    }

    //! generate list of sample values
    virtual std::vector<double> generateValueList(size_t nbr_samples,
            double sigma_factor) const;

protected:
    //! Registers some class members for later access via parameter pool
    void init_parameters();
private:
    //! check initialization
    bool checkInitialization() const;
    double m_mean;
    double m_std_dev;
};

//! @class DistributionLogNormal
//! @ingroup algorithms
//! @brief Log-normal distribution
class BA_CORE_API_ DistributionLogNormal: public IDistribution1D
{
public:
    DistributionLogNormal(double scale_param);
    DistributionLogNormal(double median, double scale_param);
    virtual ~DistributionLogNormal() {}

    //! clone method
    virtual DistributionLogNormal *clone() const {
        return new DistributionLogNormal(m_median, m_scale_param);
    }

    //! get the probability density for value x
    virtual double probabilityDensity(double x) const;

    //! get the mean of the distribution
    virtual double getMean() const;

    //! generate list of sample values
    virtual std::vector<double> generateValueList(size_t nbr_samples,
            double sigma_factor) const;

protected:
    //! Registers some class members for later access via parameter pool
    void init_parameters();
private:
    //! check initialization
    bool checkInitialization() const;
    double m_median;
    double m_scale_param;
};

//! @class DistributionCosine
//! @ingroup algorithms
//! @brief Cosine distribution
class BA_CORE_API_ DistributionCosine: public IDistribution1D
{
public:
    DistributionCosine();
    DistributionCosine(double mean, double sigma);
    virtual ~DistributionCosine() {}

    //! clone method
    virtual DistributionCosine *clone() const {
        return new DistributionCosine(m_mean, m_sigma);
    }

    //! get the probability density for value x
    virtual double probabilityDensity(double x) const;

    //! get the mean of the distribution
    virtual double getMean() const {
        return m_mean;
    }

    //! generate list of sample values
    virtual std::vector<double> generateValueList(size_t nbr_samples,
            double sigma_factor) const;

protected:
    //! Registers some class members for later access via parameter pool
    void init_parameters();
private:
    //! check initialization
    bool checkInitialization() const;
    double m_mean;
    double m_sigma;
};

#endif /* DISTRIBUTIONS_H_ */
