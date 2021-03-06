//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      Core/Simulation/GISASSimulation.cpp
//! @brief     Implements interface ISimulation.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "Core/Simulation/GISASSimulation.h"
#include "Core/Simulation/UnitConverterUtils.h"
#include "Sample/SampleBuilderEngine/ISampleBuilder.h"

GISASSimulation::GISASSimulation(const Beam& beam, const MultiLayer& sample,
                                 const IDetector& detector)
    : ISimulation2D(beam, sample, detector)
{
    initialize();
}

#ifndef SWIG
GISASSimulation::GISASSimulation(const Beam& beam, const IDetector& detector)
    : ISimulation2D(beam, detector)
{
    initialize();
}
#endif // SWIG

GISASSimulation::GISASSimulation()
{
    initialize();
}

GISASSimulation::GISASSimulation(const GISASSimulation& other) : ISimulation2D(other)
{
    initialize();
}

void GISASSimulation::initialize()
{
    setName("GISASSimulation");
}

void GISASSimulation::prepareSimulation()
{
    if (detector().dimension() != 2)
        throw std::runtime_error("GISASSimulation::prepareSimulation() "
                                 "-> Error. The detector was not properly configured.");
    instrument().initDetector();
    ISimulation2D::prepareSimulation();
}

SimulationResult GISASSimulation::result() const
{
    const auto converter = UnitConverterUtils::createConverterForGISAS(instrument());
    const std::unique_ptr<OutputData<double>> data(
        detector().createDetectorIntensity(m_sim_elements));
    return SimulationResult(*data, *converter);
}

void GISASSimulation::setBeamParameters(double wavelength, double alpha_i, double phi_i)
{
    if (wavelength <= 0.0)
        throw std::runtime_error(
            "ISimulation::setBeamParameters() -> Error. Incoming wavelength <= 0.");
    instrument().setBeamParameters(wavelength, alpha_i, phi_i);
}

size_t GISASSimulation::intensityMapSize() const
{
    size_t result = 0;
    detector().iterate([&result](IDetector::const_iterator) { ++result; }, true);
    return result;
}

void GISASSimulation::initSimulationElementVector()
{
    m_sim_elements = generateSimulationElements(beam());
    if (m_cache.empty())
        m_cache.resize(m_sim_elements.size(), 0.0);
}
