// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Shapes/SlicedFormFactorList.cpp
//! @brief     Defines class SlicedFormFactorList.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2017
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   J. Burle, J. M. Fisher, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //


#include "SlicedFormFactorList.h"
#include "IParticle.h"
#include "MultiLayer.h"
#include "Rotations.h"

namespace {
size_t LayerIndexBottom(const IParticle& particle, const MultiLayer& multilayer,
                        size_t ref_layer_index);
size_t LayerIndexTop(const IParticle& particle, const MultiLayer& multilayer,
                        size_t ref_layer_index);
}

void SlicedFormFactorList::addParticle(const IParticle& particle,
                                       const MultiLayer& multilayer, size_t ref_layer_index)
{
    size_t layer_index = LayerIndexBottom(particle, multilayer, ref_layer_index);
    m_ff_list.emplace_back(std::unique_ptr<IFormFactor>(particle.createFormFactor()), layer_index);
}

size_t SlicedFormFactorList::size() const
{
    return m_ff_list.size();
}

std::pair<const IFormFactor*, size_t> SlicedFormFactorList::operator[](size_t index) const
{
    if (index >= size())
        throw std::out_of_range("SlicedFormFactorList::operator[] error: "
                                "index out of range");
    return { m_ff_list[index].first.get(), m_ff_list[index].second };
}

SlicedFormFactorList CreateSlicedFormFactors(const IParticle& particle,
                                             const MultiLayer& multilayer, size_t ref_layer_index)
{
    SlicedFormFactorList result;
    auto particles = particle.decompose();
    for (auto p_particle : particles) {
        result.addParticle(*p_particle, multilayer, ref_layer_index);
    }
    return result;
}

namespace {
size_t LayerIndexBottom(const IParticle& particle, const MultiLayer& multilayer,
                        size_t ref_layer_index)
{
    std::unique_ptr<IFormFactor> P_ff(particle.createFormFactor());
    std::unique_ptr<IRotation> P_rot(IRotation::createIdentity());
    double position_offset = multilayer.getLayerTopZ(ref_layer_index);
    double zmin = P_ff->bottomZ(*P_rot) + position_offset;
    return multilayer.bottomZToLayerIndex(zmin);
}

size_t LayerIndexTop(const IParticle& particle, const MultiLayer& multilayer,
                     size_t ref_layer_index)
{
    std::unique_ptr<IFormFactor> P_ff(particle.createFormFactor());
    std::unique_ptr<IRotation> P_rot(IRotation::createIdentity());
    double position_offset = multilayer.getLayerTopZ(ref_layer_index);
    double zmin = P_ff->topZ(*P_rot) + position_offset;
    return multilayer.topZToLayerIndex(zmin);
}
}

