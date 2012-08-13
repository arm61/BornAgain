/*
 * DoubleToComplexInterpolatingFunction.cpp
 *
 *  Created on: Apr 27, 2012
 *      Author: herck
 */

#include "DoubleToComplexInterpolatingFunction.h"
#include "Exceptions.h"
#include <sstream>



DoubleToComplexInterpolatingFunction::~DoubleToComplexInterpolatingFunction()
{
}

DoubleToComplexInterpolatingFunction::DoubleToComplexInterpolatingFunction(const std::map<double, complex_t> &value_map, InterpolatingMode imode)
    : m_value_map(value_map), m_interpolating_mode(imode)
{
	m_lower_limit = (*m_value_map.begin()).first;
	m_upper_limit = (*m_value_map.rbegin()).first;
	m_low_step = (*(++m_value_map.begin())).first - m_lower_limit;
	m_high_step = m_upper_limit - (*(--m_value_map.rbegin())).first;
}

DoubleToComplexInterpolatingFunction* DoubleToComplexInterpolatingFunction::clone() const
{
    DoubleToComplexInterpolatingFunction *p_new = new DoubleToComplexInterpolatingFunction(m_value_map, m_interpolating_mode);
    return p_new;
}

complex_t DoubleToComplexInterpolatingFunction::evaluate(double value)
{
    if (value < m_lower_limit-m_low_step || value > m_upper_limit + m_high_step)
    {
        std::ostringstream os;
        os << "DoubleToComplexInterpolatingFunction::evaluate() -> Error! ";
        os << "Cannot interpolate: argument value is outside of bounds. ";
        os << " value: " << value << " m_lower_limit:" << m_lower_limit << " " << m_low_step << " m_upper_limit: " << m_upper_limit << " " << m_high_step;
        throw OutOfBoundsException(os.str());
    }
    if (value < m_lower_limit) value = m_lower_limit;
    else if (value > m_upper_limit) value = m_upper_limit;
    std::map<double, complex_t>::const_iterator found_it = m_value_map.find(value);
    if (found_it != m_value_map.end()) {
        return found_it->second;
    }
    std::map<double, complex_t>::const_iterator lower_it = m_value_map.lower_bound(value);
    --lower_it;
    std::map<double, complex_t>::const_iterator upper_it = m_value_map.upper_bound(value);

    double interpolating_factor = (value - (*lower_it).first)/((*upper_it).first-(*lower_it).first);
    if(m_interpolating_mode == Nearest) {
        if( interpolating_factor < 0.5 ) {
            return (*lower_it).second;
        } else {
            return (*upper_it).second;
        }
    } else if ( m_interpolating_mode == Linear ) {
        complex_t result_difference = (*upper_it).second - (*lower_it).second;
        return (*lower_it).second + result_difference * interpolating_factor;
    } else if (m_interpolating_mode == Polar) {
        double cabs_difference = std::abs((*upper_it).second) - std::abs((*lower_it).second);
        double cabs = std::abs((*lower_it).second) + cabs_difference * interpolating_factor;
        double carg_difference = std::arg((*upper_it).second) - std::arg((*lower_it).second);
        double carg = std::arg((*lower_it).second) + carg_difference * interpolating_factor;
        return std::polar(cabs, carg);
    } else {
        throw DomainErrorException("DoubleToComplexInterpolatingFunction::evaluate() -> Error. Unknown interpolation mode");
    }
}
