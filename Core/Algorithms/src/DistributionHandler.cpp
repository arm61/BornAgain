// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Algorithms/src/DistributionHandler.cpp
//! @brief     Implements class DistributionHandler.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "DistributionHandler.h"

DistributionHandler::DistributionHandler()
: m_nbr_combinations(1)
{
}

DistributionHandler::~DistributionHandler()
{
}

void DistributionHandler::addParameterDistribution(
        const std::string &param_name, const IDistribution1D &distribution,
        size_t nbr_samples, double sigma_factor)
{
    if (nbr_samples > 0) {
        ParameterDistribution par_distr(param_name, distribution,
                                        nbr_samples, sigma_factor);
        m_distributions.push_back(par_distr);
        m_nbr_combinations *= nbr_samples;
        m_cached_samples.push_back(par_distr.generateSamples());
    }
}

size_t DistributionHandler::getTotalNumberOfSamples() const
{
    return m_nbr_combinations;
}

double DistributionHandler::setParameterValues(ParameterPool *p_parameter_pool,
        size_t index)
{
    if (index >= m_nbr_combinations) {
        throw Exceptions::RuntimeErrorException(
                "DistributionWeighter::setParameterValues: "
                "index must be smaller than the total number of parameter "
                "combinations");
    }
    size_t n_distr = m_distributions.size();
    double weight = 1.0;
    if (n_distr == 0) return weight;
    for (size_t param_index=n_distr-1; ; --param_index) {
        size_t remainder = index % m_distributions[param_index].getNbrSamples();
        index /= m_distributions[param_index].getNbrSamples();
        int changed = p_parameter_pool->setMatchedParametersValue(
                m_distributions[param_index].getMainParameterName(),
                m_cached_samples[param_index][remainder].value);
        if (changed != 1) {
            throw Exceptions::RuntimeErrorException(
                    "DistributionWeighter::setParameterValues: "
                    " parameter name matches nothing or more than "
                    "one parameter");
        }
        weight *= m_cached_samples[param_index][remainder].weight;
        if (param_index==0) break;
    }
    return weight;
}
