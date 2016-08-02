// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Algorithms/SimulationOptions.h
//! @brief     Declares class SimulationOptions.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef SIMULATIONOPTIONS_H
#define SIMULATIONOPTIONS_H

#include "WinDllMacros.h"
#include "ThreadInfo.h"

#include <cstddef>

//! @class SimulationOptions
//! @ingroup simulation
//! @brief Collect the different options for simulation
//! @ref SimulationOptions

class BA_CORE_API_ SimulationOptions
{
public:
    SimulationOptions();

    bool isIntegrate() const;
    size_t getMcPoints() const;

    //! @brief Enables/disables MonetCarlo integration
    //! @param flag If true, MonteCarlo integration will be used, otherwise analytical calculations
    //! @param mc_points Number of points for MonteCarlo integrator
    void setMonteCarloIntegration(bool flag = true, size_t mc_points=50);

    //! @brief Sets number of threads to use during the simulation (0 - take the default value from
    //! the hardware)
    void setNumberOfThreads(int nthreads);

    int getNumberOfThreads() const;

    //! @brief Sets number of batches to split
    void setNumberOfBatches(int nbatches);

    int getNumberOfBatches() const;

    int getCurrentBatch() const;

    //! @brief Sets the batch and thread information to be used
    void setThreadInfo(const ThreadInfo &thread_info);

    int getHardwareConcurrency() const;

private:
    bool m_mc_integration;
    size_t m_mc_points;
    ThreadInfo m_thread_info;
};


#endif /* SIMULATIONPARAMETERS_H_ */