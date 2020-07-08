// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/TestMachinery/Benchmark.h
//! @brief     Defines Benchmark class
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_TESTS_FUNCTIONAL_TESTMACHINERY_BENCHMARK_H
#define BORNAGAIN_TESTS_FUNCTIONAL_TESTMACHINERY_BENCHMARK_H

#include "Core/Tools/OrderedMap.h"
#include "Fit/Tools/WallclockTimer.h"
#include "Wrap/WinDllMacros.h"
#include <functional>
#include <map>
#include <string>

class BA_CORE_API_ Duration
{
public:
    Duration() : m_totalTime(0) {}

    void start() { m_timer.start(); }
    void stop()
    {
        m_timer.stop();
        m_totalTime += m_timer.runTime();
    }
    double runTime() const { return m_totalTime; }

private:
    WallclockTimer m_timer;
    double m_totalTime;
};

//! Benchmark tool to measure duration of several processes.

class BA_CORE_API_ Benchmark
{
    typedef OrderedMap<std::string, Duration*> BenchmarkMap;

public:
    Benchmark() {}
    ~Benchmark();

    void start(const std::string& name);
    void stop(const std::string& name);
    double runTime(const std::string& name);
    std::string report() const;
    const BenchmarkMap& retrieveData() const { return m_data; }

    void test_method(const std::string& name, std::function<void(void)> f, int ntries);

private:
    BenchmarkMap m_data;
};

#endif // BORNAGAIN_TESTS_FUNCTIONAL_TESTMACHINERY_BENCHMARK_H