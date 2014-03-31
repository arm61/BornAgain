// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Algorithms/src/ChiSquaredModule.cpp
//! @brief     Implements class ChiSquaredModule.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "ChiSquaredModule.h"
#include "OutputDataFunctions.h"
#include <cassert>

//! Updates mp_simulation_data and mp_weights, returns chi^2.

double ChiSquaredModule::calculateChiSquared()
{
    if( !mp_real_data )
        throw NullPointerException("ChiSquaredModule::calculateChiSquared() -> "
                                   "Error! No real data has been set");
    if( !mp_simulation_data )
        throw NullPointerException("ChiSquaredModule::calculateChiSquared() -> "
                                   "Error! No simulated data has been set");

    if(mp_data_normalizer) {
        OutputData<double> *normalized_simulation =
            mp_data_normalizer->createNormalizedData(*mp_simulation_data);
        delete mp_simulation_data;
        mp_simulation_data = normalized_simulation;
    }

//    if( mp_intensity_function ) {
//        OutputDataFunctions::applyFunction(
//            *mp_simulation_data, mp_intensity_function);
//        OutputDataFunctions::applyFunction(
//            *mp_real_data, mp_intensity_function);
//    }

    initWeights();
    OutputData<double> *p_difference = createChi2DifferenceMap();
    OutputData<double>::const_iterator it_weights = mp_weights->begin();
    OutputData<double>::const_iterator it_diff = p_difference->begin();

    double sum = 0;
    while(it_diff != p_difference->end())
        sum += (*it_diff++)*(*it_weights++);
    delete p_difference;

    double fnorm = m_ndegree_of_freedom > 0 ?
        m_ndegree_of_freedom :
        mp_real_data->getAllocatedSize();
    return sum/fnorm;
}

double ChiSquaredModule::getResidualValue(size_t index ) const
{
    assert(mp_real_data != NULL );
    assert(mp_simulation_data != NULL);
    assert(mp_weights != NULL);
    assert(index < mp_real_data->getAllocatedSize() );
    double value_real = (*mp_real_data)[index];
    double value_simu  = (*mp_simulation_data)[index];
    double weight = (*mp_weights)[index];
    double squared_error = getSquaredFunction()->calculateSquaredError(
        value_real, value_simu);
    assert(squared_error);
    assert(weight);
    double residual = std::sqrt(weight)*(value_simu - value_real)/
        std::sqrt(squared_error);
    return residual;
}

OutputData<double>* ChiSquaredModule::createChi2DifferenceMap() const
{
    if( !mp_real_data )
        throw NullPointerException("ChiSquaredModule::calculateChiSquared() -> "
                                   "Error! No real data has been set");
    if( !mp_simulation_data )
        throw NullPointerException("ChiSquaredModule::calculateChiSquared() -> "
                                   "Error! No simulated data has been set");

    OutputData<double > *p_difference = mp_simulation_data->clone();
    p_difference->setAllTo(0.0);

    OutputData<double>::iterator it_diff = p_difference->begin();
    OutputData<double>::const_iterator it_sim = mp_simulation_data->begin();
    OutputData<double>::const_iterator it_real = mp_real_data->begin();

    while (it_diff != p_difference->end()) {
        if( (it_sim.getIndex() != it_real.getIndex()) || (it_sim.getIndex() != it_diff.getIndex()) ) {
            throw DomainErrorException("ChiSquaredModule::calculateChiSquared() -> Iterator inconsistency");
        }
        double value_simu = *it_sim++;
        double value_real = *it_real++;

        if(mp_intensity_function) {
            value_simu = mp_intensity_function->evaluate(value_simu);
            value_real = mp_intensity_function->evaluate(value_real);
        }

        double squared_difference =
            mp_squared_function->calculateSquaredDifference(
                value_real, value_simu);
        *it_diff = squared_difference;
        ++it_diff;
    }    

    return p_difference;
}



