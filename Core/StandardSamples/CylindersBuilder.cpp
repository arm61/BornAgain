// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/StandardSamples/CylindersBuilder.cpp
//! @brief     Implements classes of CylindersBuilder family.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "CylindersBuilder.h"
#include "BornAgainNamespace.h"
#include "FormFactorCylinder.h"
#include "HomogeneousMaterial.h"
#include "Layer.h"
#include "LayerInterface.h"
#include "MultiLayer.h"
#include "Particle.h"
#include "ParticleLayout.h"
#include "Units.h"

// -----------------------------------------------------------------------------
// Cylinders in DWBA
// -----------------------------------------------------------------------------
CylindersInDWBABuilder::CylindersInDWBABuilder()
    : m_height(5*Units::nanometer)
    , m_radius(5*Units::nanometer)
{
    init_parameters();
}

void CylindersInDWBABuilder::init_parameters()
{
    registerNonnegativeLength(BornAgain::Radius, &m_radius);
    registerNonnegativeLength(BornAgain::Height, &m_height);
}

ISample* CylindersInDWBABuilder::buildSample() const
{
    MultiLayer* multi_layer = new MultiLayer();

    HomogeneousMaterial air_material("Air", 0.0, 0.0);
    HomogeneousMaterial substrate_material("Substrate", 6e-6, 2e-8);
    HomogeneousMaterial particle_material("Particle", 6e-4, 2e-8);

    Layer air_layer(air_material);
    Layer substrate_layer(substrate_material);

    FormFactorCylinder ff_cylinder(m_radius, m_height);

    Particle particle(particle_material, ff_cylinder);
    ParticleLayout particle_layout(particle);

    air_layer.addLayout(particle_layout);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);

    return multi_layer;
}

// -----------------------------------------------------------------------------
// Cylinders in BA
// -----------------------------------------------------------------------------
CylindersInBABuilder::CylindersInBABuilder()
    : m_height(5*Units::nanometer)
    , m_radius(5*Units::nanometer)
{
    init_parameters();
}

void CylindersInBABuilder::init_parameters()
{
    registerNonnegativeLength(BornAgain::Radius, &m_radius);
    registerNonnegativeLength(BornAgain::Height, &m_height);
}

ISample* CylindersInBABuilder::buildSample() const
{
    MultiLayer* multi_layer = new MultiLayer();

    HomogeneousMaterial air_material("Air", 0.0, 0.0);
    HomogeneousMaterial particle_material("Particle", 6e-4, 2e-8);

    Layer air_layer(air_material);

    FormFactorCylinder ff_cylinder(m_radius, m_height);
    Particle cylinder(particle_material,ff_cylinder);

    ParticleLayout particle_layout(cylinder);

    air_layer.addLayout(particle_layout);
    multi_layer->addLayer(air_layer);

    return multi_layer;
}

// -----------------------------------------------------------------------------
// Large cylinders in DWBA
// -----------------------------------------------------------------------------
LargeCylindersInDWBABuilder::LargeCylindersInDWBABuilder()
    : m_height(1000*Units::nanometer)
    , m_radius(500*Units::nanometer)
{
    init_parameters();
}

void LargeCylindersInDWBABuilder::init_parameters()
{

    registerNonnegativeLength(BornAgain::Radius, &m_radius);
    registerNonnegativeLength(BornAgain::Height, &m_height);
}

ISample* LargeCylindersInDWBABuilder::buildSample() const
{
    MultiLayer* multi_layer = new MultiLayer();

    HomogeneousMaterial air_material("Air", 0.0, 0.0);
    HomogeneousMaterial substrate_material("Substrate", 6e-6, 2e-8);
    HomogeneousMaterial particle_material("Particle", 6e-4, 2e-8);

    Layer air_layer(air_material);
    Layer substrate_layer(substrate_material);

    FormFactorCylinder ff_cylinder(m_radius, m_height);

    Particle particle(particle_material, ff_cylinder);
    ParticleLayout particle_layout(particle);

    air_layer.addLayout(particle_layout);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);

    return multi_layer;
}
