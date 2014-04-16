// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence 
//! @brief automatically generated boost::python code for PythonCoreAPI  

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "PythonCoreList.h"
#include "StochasticSampledParameter.pypp.h"

namespace bp = boost::python;

struct StochasticSampledParameter_wrapper : StochasticSampledParameter, bp::wrapper< StochasticSampledParameter > {

    StochasticSampledParameter_wrapper(::StochasticParameter< double > const & par, ::std::size_t nbins, double xmin, double xmax )
    : StochasticSampledParameter( boost::ref(par), nbins, xmin, xmax )
      , bp::wrapper< StochasticSampledParameter >(){
        // constructor
    
    }

    StochasticSampledParameter_wrapper(::StochasticParameter< double > const & par, ::std::size_t nbins, int nfwhm=3 )
    : StochasticSampledParameter( boost::ref(par), nbins, nfwhm )
      , bp::wrapper< StochasticSampledParameter >(){
        // constructor
    
    }

    virtual ::StochasticSampledParameter * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->StochasticSampledParameter::clone(  );
        }
    }
    
    ::StochasticSampledParameter * default_clone(  ) const  {
        return StochasticSampledParameter::clone( );
    }

    virtual double probabilityDensity( double value ) const  {
        if( bp::override func_probabilityDensity = this->get_override( "probabilityDensity" ) )
            return func_probabilityDensity( value );
        else{
            return this->StochasticSampledParameter::probabilityDensity( value );
        }
    }
    
    double default_probabilityDensity( double value ) const  {
        return StochasticSampledParameter::probabilityDensity( value );
    }

    virtual void setToRandom(  ) {
        if( bp::override func_setToRandom = this->get_override( "setToRandom" ) )
            func_setToRandom(  );
        else{
            this->StochasticSampledParameter::setToRandom(  );
        }
    }
    
    void default_setToRandom(  ) {
        StochasticSampledParameter::setToRandom( );
    }

    virtual double getFWHM(  ) const  {
        if( bp::override func_getFWHM = this->get_override( "getFWHM" ) )
            return func_getFWHM(  );
        else{
            return this->StochasticParameter< double >::getFWHM(  );
        }
    }
    
    double default_getFWHM(  ) const  {
        return StochasticParameter< double >::getFWHM( );
    }

    virtual double getRandom(  ) {
        if( bp::override func_getRandom = this->get_override( "getRandom" ) )
            return func_getRandom(  );
        else{
            return this->StochasticParameter< double >::getRandom(  );
        }
    }
    
    double default_getRandom(  ) {
        return StochasticParameter< double >::getRandom( );
    }

    virtual void setToAverage(  ) {
        if( bp::override func_setToAverage = this->get_override( "setToAverage" ) )
            func_setToAverage(  );
        else{
            this->StochasticParameter< double >::setToAverage(  );
        }
    }
    
    void default_setToAverage(  ) {
        StochasticParameter< double >::setToAverage( );
    }

};

void register_StochasticSampledParameter_class(){

    { //::StochasticSampledParameter
        typedef bp::class_< StochasticSampledParameter_wrapper, bp::bases< StochasticParameter< double > >, boost::noncopyable > StochasticSampledParameter_exposer_t;
        StochasticSampledParameter_exposer_t StochasticSampledParameter_exposer = StochasticSampledParameter_exposer_t( "StochasticSampledParameter", bp::init< StochasticParameter< double > const &, std::size_t, double, double >(( bp::arg("par"), bp::arg("nbins"), bp::arg("xmin"), bp::arg("xmax") )) );
        bp::scope StochasticSampledParameter_scope( StochasticSampledParameter_exposer );
        StochasticSampledParameter_exposer.def( bp::init< StochasticParameter< double > const &, std::size_t, bp::optional< int > >(( bp::arg("par"), bp::arg("nbins"), bp::arg("nfwhm")=(int)(3) )) );
        { //::StochasticSampledParameter::clone
        
            typedef ::StochasticSampledParameter * ( ::StochasticSampledParameter::*clone_function_type )(  ) const;
            typedef ::StochasticSampledParameter * ( StochasticSampledParameter_wrapper::*default_clone_function_type )(  ) const;
            
            StochasticSampledParameter_exposer.def( 
                "clone"
                , clone_function_type(&::StochasticSampledParameter::clone)
                , default_clone_function_type(&StochasticSampledParameter_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::StochasticSampledParameter::getBinValue
        
            typedef double ( ::StochasticSampledParameter::*getBinValue_function_type )( ::std::size_t ) const;
            
            StochasticSampledParameter_exposer.def( 
                "getBinValue"
                , getBinValue_function_type( &::StochasticSampledParameter::getBinValue )
                , ( bp::arg("ibin") ) );
        
        }
        { //::StochasticSampledParameter::getNbins
        
            typedef ::std::size_t ( ::StochasticSampledParameter::*getNbins_function_type )(  ) const;
            
            StochasticSampledParameter_exposer.def( 
                "getNbins"
                , getNbins_function_type( &::StochasticSampledParameter::getNbins ) );
        
        }
        { //::StochasticSampledParameter::getNormalizedProbability
        
            typedef double ( ::StochasticSampledParameter::*getNormalizedProbability_function_type )( ::std::size_t ) const;
            
            StochasticSampledParameter_exposer.def( 
                "getNormalizedProbability"
                , getNormalizedProbability_function_type( &::StochasticSampledParameter::getNormalizedProbability )
                , ( bp::arg("ibin") ) );
        
        }
        { //::StochasticSampledParameter::probabilityBinDensity
        
            typedef double ( ::StochasticSampledParameter::*probabilityBinDensity_function_type )( ::std::size_t ) const;
            
            StochasticSampledParameter_exposer.def( 
                "probabilityBinDensity"
                , probabilityBinDensity_function_type( &::StochasticSampledParameter::probabilityBinDensity )
                , ( bp::arg("ibin") ) );
        
        }
        { //::StochasticSampledParameter::probabilityDensity
        
            typedef double ( ::StochasticSampledParameter::*probabilityDensity_function_type )( double ) const;
            typedef double ( StochasticSampledParameter_wrapper::*default_probabilityDensity_function_type )( double ) const;
            
            StochasticSampledParameter_exposer.def( 
                "probabilityDensity"
                , probabilityDensity_function_type(&::StochasticSampledParameter::probabilityDensity)
                , default_probabilityDensity_function_type(&StochasticSampledParameter_wrapper::default_probabilityDensity)
                , ( bp::arg("value") ) );
        
        }
        { //::StochasticSampledParameter::setToRandom
        
            typedef void ( ::StochasticSampledParameter::*setToRandom_function_type )(  ) ;
            typedef void ( StochasticSampledParameter_wrapper::*default_setToRandom_function_type )(  ) ;
            
            StochasticSampledParameter_exposer.def( 
                "setToRandom"
                , setToRandom_function_type(&::StochasticSampledParameter::setToRandom)
                , default_setToRandom_function_type(&StochasticSampledParameter_wrapper::default_setToRandom) );
        
        }
        { //::StochasticParameter< double >::getFWHM
        
            typedef StochasticSampledParameter exported_class_t;
            typedef double ( exported_class_t::*getFWHM_function_type )(  ) const;
            typedef double ( StochasticSampledParameter_wrapper::*default_getFWHM_function_type )(  ) const;
            
            StochasticSampledParameter_exposer.def( 
                "getFWHM"
                , getFWHM_function_type(&::StochasticParameter< double >::getFWHM)
                , default_getFWHM_function_type(&StochasticSampledParameter_wrapper::default_getFWHM) );
        
        }
        { //::StochasticParameter< double >::getRandom
        
            typedef StochasticSampledParameter exported_class_t;
            typedef double ( exported_class_t::*getRandom_function_type )(  ) ;
            typedef double ( StochasticSampledParameter_wrapper::*default_getRandom_function_type )(  ) ;
            
            StochasticSampledParameter_exposer.def( 
                "getRandom"
                , getRandom_function_type(&::StochasticParameter< double >::getRandom)
                , default_getRandom_function_type(&StochasticSampledParameter_wrapper::default_getRandom) );
        
        }
        { //::StochasticParameter< double >::setToAverage
        
            typedef StochasticSampledParameter exported_class_t;
            typedef void ( exported_class_t::*setToAverage_function_type )(  ) ;
            typedef void ( StochasticSampledParameter_wrapper::*default_setToAverage_function_type )(  ) ;
            
            StochasticSampledParameter_exposer.def( 
                "setToAverage"
                , setToAverage_function_type(&::StochasticParameter< double >::setToAverage)
                , default_setToAverage_function_type(&StochasticSampledParameter_wrapper::default_setToAverage) );
        
        }
    }

}
