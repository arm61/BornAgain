// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Computation/RoughMultiLayerComputation.h
//! @brief     Defines class RoughMultiLayerComputation.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef ROUGHMULTILAYERCOMPUTATION_H
#define ROUGHMULTILAYERCOMPUTATION_H

#include "Complex.h"
#include "IComputationTerm.h"
#include <vector>

class DelayedProgressCounter;
class ProgressHandler;
class SimulationElement;

//! Computes the diffuse reflection from the rough interfaces of a multilayer.
//! Used by DWBAComputation.
//! @ingroup algorithms_internal

class RoughMultiLayerComputation final : public IComputationTerm
{
public:
    RoughMultiLayerComputation(const MultiLayer* p_multi_layer,
                               const IFresnelMap* p_fresnel_map);

    void setProgressHandler(ProgressHandler* p_progress) override;

    void operator()(SimulationElement& elem) const override;

private:
    double evaluate(const SimulationElement& sim_element) const;
    complex_t get_refractive_term(size_t ilayer, double wavelength) const;
    complex_t get_sum8terms(size_t ilayer, const SimulationElement& sim_element) const;
    std::unique_ptr<DelayedProgressCounter> mP_progress_counter;
};

#endif // ROUGHMULTILAYERCOMPUTATION_H
