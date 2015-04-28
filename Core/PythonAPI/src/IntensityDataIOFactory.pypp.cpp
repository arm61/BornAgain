// This file has been generated by Py++.

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Automatically generated boost::python code for BornAgain Python bindings
//! @brief     Automatically generated boost::python code for BornAgain Python bindings
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Juelich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonCoreList.h"
#include "IntensityDataIOFactory.pypp.h"

namespace bp = boost::python;

void register_IntensityDataIOFactory_class(){

    { //::IntensityDataIOFactory
        typedef bp::class_< IntensityDataIOFactory > IntensityDataIOFactory_exposer_t;
        IntensityDataIOFactory_exposer_t IntensityDataIOFactory_exposer = IntensityDataIOFactory_exposer_t( "IntensityDataIOFactory" );
        bp::scope IntensityDataIOFactory_scope( IntensityDataIOFactory_exposer );
        { //::IntensityDataIOFactory::readIntensityData
        
            typedef ::OutputData< double > * ( *readIntensityData_function_type )( ::std::string const & );
            
            IntensityDataIOFactory_exposer.def( 
                "readIntensityData"
                , readIntensityData_function_type( &::IntensityDataIOFactory::readIntensityData )
                , ( bp::arg("file_name") )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IntensityDataIOFactory::writeIntensityData
        
            typedef void ( *writeIntensityData_function_type )( ::OutputData< double > const &,::std::string const & );
            
            IntensityDataIOFactory_exposer.def( 
                "writeIntensityData"
                , writeIntensityData_function_type( &::IntensityDataIOFactory::writeIntensityData )
                , ( bp::arg("data"), bp::arg("file_name") ) );
        
        }
        IntensityDataIOFactory_exposer.staticmethod( "readIntensityData" );
        IntensityDataIOFactory_exposer.staticmethod( "writeIntensityData" );
    }

}
