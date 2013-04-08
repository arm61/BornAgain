// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence 
//! @brief automatically generated boost::python code for PythonCoreAPI  

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "PythonFitList.h"
#include "SquaredFunctionWhichOnlyWorks.pypp.h"

namespace bp = boost::python;

struct SquaredFunctionWhichOnlyWorks_wrapper : SquaredFunctionWhichOnlyWorks, bp::wrapper< SquaredFunctionWhichOnlyWorks > {

    SquaredFunctionWhichOnlyWorks_wrapper(SquaredFunctionWhichOnlyWorks const & arg )
    : SquaredFunctionWhichOnlyWorks( arg )
      , bp::wrapper< SquaredFunctionWhichOnlyWorks >(){
        // copy constructor
        
    }

    SquaredFunctionWhichOnlyWorks_wrapper( )
    : SquaredFunctionWhichOnlyWorks( )
      , bp::wrapper< SquaredFunctionWhichOnlyWorks >(){
        // null constructor
    
    }

    virtual double calculateSquaredDifference( double real_value, double simulated_value ) const  {
        if( bp::override func_calculateSquaredDifference = this->get_override( "calculateSquaredDifference" ) )
            return func_calculateSquaredDifference( real_value, simulated_value );
        else{
            return this->SquaredFunctionWhichOnlyWorks::calculateSquaredDifference( real_value, simulated_value );
        }
    }
    
    double default_calculateSquaredDifference( double real_value, double simulated_value ) const  {
        return SquaredFunctionWhichOnlyWorks::calculateSquaredDifference( real_value, simulated_value );
    }

    virtual ::SquaredFunctionWhichOnlyWorks * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->SquaredFunctionWhichOnlyWorks::clone(  );
        }
    }
    
    ::SquaredFunctionWhichOnlyWorks * default_clone(  ) const  {
        return SquaredFunctionWhichOnlyWorks::clone( );
    }

    virtual double calculateSquaredError( double real_value, double simulated_value=0.0 ) const  {
        if( bp::override func_calculateSquaredError = this->get_override( "calculateSquaredError" ) )
            return func_calculateSquaredError( real_value, simulated_value );
        else{
            return this->ISquaredFunction::calculateSquaredError( real_value, simulated_value );
        }
    }
    
    double default_calculateSquaredError( double real_value, double simulated_value=0.0 ) const  {
        return ISquaredFunction::calculateSquaredError( real_value, simulated_value );
    }

};

void register_SquaredFunctionWhichOnlyWorks_class(){

    { //::SquaredFunctionWhichOnlyWorks
        typedef bp::class_< SquaredFunctionWhichOnlyWorks_wrapper, bp::bases< ISquaredFunction > > SquaredFunctionWhichOnlyWorks_exposer_t;
        SquaredFunctionWhichOnlyWorks_exposer_t SquaredFunctionWhichOnlyWorks_exposer = SquaredFunctionWhichOnlyWorks_exposer_t( "SquaredFunctionWhichOnlyWorks", bp::init< >() );
        bp::scope SquaredFunctionWhichOnlyWorks_scope( SquaredFunctionWhichOnlyWorks_exposer );
        { //::SquaredFunctionWhichOnlyWorks::calculateSquaredDifference
        
            typedef double ( ::SquaredFunctionWhichOnlyWorks::*calculateSquaredDifference_function_type )( double,double ) const;
            typedef double ( SquaredFunctionWhichOnlyWorks_wrapper::*default_calculateSquaredDifference_function_type )( double,double ) const;
            
            SquaredFunctionWhichOnlyWorks_exposer.def( 
                "calculateSquaredDifference"
                , calculateSquaredDifference_function_type(&::SquaredFunctionWhichOnlyWorks::calculateSquaredDifference)
                , default_calculateSquaredDifference_function_type(&SquaredFunctionWhichOnlyWorks_wrapper::default_calculateSquaredDifference)
                , ( bp::arg("real_value"), bp::arg("simulated_value") ) );
        
        }
        { //::SquaredFunctionWhichOnlyWorks::clone
        
            typedef ::SquaredFunctionWhichOnlyWorks * ( ::SquaredFunctionWhichOnlyWorks::*clone_function_type )(  ) const;
            typedef ::SquaredFunctionWhichOnlyWorks * ( SquaredFunctionWhichOnlyWorks_wrapper::*default_clone_function_type )(  ) const;
            
            SquaredFunctionWhichOnlyWorks_exposer.def( 
                "clone"
                , clone_function_type(&::SquaredFunctionWhichOnlyWorks::clone)
                , default_clone_function_type(&SquaredFunctionWhichOnlyWorks_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ISquaredFunction::calculateSquaredError
        
            typedef double ( ::ISquaredFunction::*calculateSquaredError_function_type )( double,double ) const;
            typedef double ( SquaredFunctionWhichOnlyWorks_wrapper::*default_calculateSquaredError_function_type )( double,double ) const;
            
            SquaredFunctionWhichOnlyWorks_exposer.def( 
                "calculateSquaredError"
                , calculateSquaredError_function_type(&::ISquaredFunction::calculateSquaredError)
                , default_calculateSquaredError_function_type(&SquaredFunctionWhichOnlyWorks_wrapper::default_calculateSquaredError)
                , ( bp::arg("real_value"), bp::arg("simulated_value")=0.0 ) );
        
        }
    }

}