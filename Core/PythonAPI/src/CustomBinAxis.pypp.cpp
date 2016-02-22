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
#include "CustomBinAxis.pypp.h"

namespace bp = boost::python;

struct CustomBinAxis_wrapper : CustomBinAxis, bp::wrapper< CustomBinAxis > {

    CustomBinAxis_wrapper(::std::string const & name, ::std::size_t nbins, double start, double end )
    : CustomBinAxis( name, nbins, start, end )
      , bp::wrapper< CustomBinAxis >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::CustomBinAxis * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->CustomBinAxis::clone(  );
        }
    }
    
    ::CustomBinAxis * default_clone(  ) const  {
        return CustomBinAxis::clone( );
    }

    virtual ::CustomBinAxis * createClippedAxis( double left, double right ) const  {
        if( bp::override func_createClippedAxis = this->get_override( "createClippedAxis" ) )
            return func_createClippedAxis( left, right );
        else{
            return this->CustomBinAxis::createClippedAxis( left, right );
        }
    }
    
    ::CustomBinAxis * default_createClippedAxis( double left, double right ) const  {
        return CustomBinAxis::createClippedAxis( left, right );
    }

    virtual ::Bin1D getBin( ::std::size_t index ) const  {
        if( bp::override func_getBin = this->get_override( "getBin" ) )
            return func_getBin( index );
        else{
            return this->CustomBinAxis::getBin( index );
        }
    }
    
    ::Bin1D default_getBin( ::std::size_t index ) const  {
        return CustomBinAxis::getBin( index );
    }

    virtual ::std::vector< double > getBinCenters(  ) const  {
        if( bp::override func_getBinCenters = this->get_override( "getBinCenters" ) )
            return func_getBinCenters(  );
        else{
            return this->CustomBinAxis::getBinCenters(  );
        }
    }
    
    ::std::vector< double > default_getBinCenters(  ) const  {
        return CustomBinAxis::getBinCenters( );
    }

    virtual bool contains( double value ) const  {
        if( bp::override func_contains = this->get_override( "contains" ) )
            return func_contains( value );
        else{
            return this->IAxis::contains( value );
        }
    }
    
    bool default_contains( double value ) const  {
        return IAxis::contains( value );
    }

    virtual ::IAxis * createDoubleBinSize(  ) const  {
        if( bp::override func_createDoubleBinSize = this->get_override( "createDoubleBinSize" ) )
            return func_createDoubleBinSize(  );
        else{
            return this->IAxis::createDoubleBinSize(  );
        }
    }
    
    ::IAxis * default_createDoubleBinSize(  ) const  {
        return IAxis::createDoubleBinSize( );
    }

    virtual ::size_t findClosestIndex( double value ) const  {
        if( bp::override func_findClosestIndex = this->get_override( "findClosestIndex" ) )
            return func_findClosestIndex( value );
        else{
            return this->VariableBinAxis::findClosestIndex( value );
        }
    }
    
    ::size_t default_findClosestIndex( double value ) const  {
        return VariableBinAxis::findClosestIndex( value );
    }

    virtual ::std::vector< double > getBinBoundaries(  ) const  {
        if( bp::override func_getBinBoundaries = this->get_override( "getBinBoundaries" ) )
            return func_getBinBoundaries(  );
        else{
            return this->VariableBinAxis::getBinBoundaries(  );
        }
    }
    
    ::std::vector< double > default_getBinBoundaries(  ) const  {
        return VariableBinAxis::getBinBoundaries( );
    }

    virtual double getBinCenter( ::size_t index ) const  {
        if( bp::override func_getBinCenter = this->get_override( "getBinCenter" ) )
            return func_getBinCenter( index );
        else{
            return this->VariableBinAxis::getBinCenter( index );
        }
    }
    
    double default_getBinCenter( ::size_t index ) const  {
        return VariableBinAxis::getBinCenter( index );
    }

    virtual double getMax(  ) const  {
        if( bp::override func_getMax = this->get_override( "getMax" ) )
            return func_getMax(  );
        else{
            return this->VariableBinAxis::getMax(  );
        }
    }
    
    double default_getMax(  ) const  {
        return VariableBinAxis::getMax( );
    }

    virtual double getMin(  ) const  {
        if( bp::override func_getMin = this->get_override( "getMin" ) )
            return func_getMin(  );
        else{
            return this->VariableBinAxis::getMin(  );
        }
    }
    
    double default_getMin(  ) const  {
        return VariableBinAxis::getMin( );
    }

    virtual ::size_t getSize(  ) const  {
        if( bp::override func_getSize = this->get_override( "getSize" ) )
            return func_getSize(  );
        else{
            return this->VariableBinAxis::getSize(  );
        }
    }
    
    ::size_t default_getSize(  ) const  {
        return VariableBinAxis::getSize( );
    }

    PyObject* m_pyobj;

};

void register_CustomBinAxis_class(){

    { //::CustomBinAxis
        typedef bp::class_< CustomBinAxis_wrapper, bp::bases< VariableBinAxis >, std::auto_ptr< CustomBinAxis_wrapper >, boost::noncopyable > CustomBinAxis_exposer_t;
        CustomBinAxis_exposer_t CustomBinAxis_exposer = CustomBinAxis_exposer_t( "CustomBinAxis", "Axis with fixed bin size in sin(angle) space used for numerical comparison with IsGisaxs.", bp::init< std::string const &, std::size_t, double, double >(( bp::arg("name"), bp::arg("nbins"), bp::arg("start"), bp::arg("end") ), "CustomBinAxis constructor.\n\n:Parameters:\n  - 'name' - Axis name\n  - 'nbins' - number of bins\n  - 'start' - center of first bin (IsGisaxs convention)\n  - 'end' - center of last bin (IsGisaxs convention)\n") );
        bp::scope CustomBinAxis_scope( CustomBinAxis_exposer );
        { //::CustomBinAxis::clone
        
            typedef ::CustomBinAxis * ( ::CustomBinAxis::*clone_function_type)(  ) const;
            typedef ::CustomBinAxis * ( CustomBinAxis_wrapper::*default_clone_function_type)(  ) const;
            
            CustomBinAxis_exposer.def( 
                "clone"
                , clone_function_type(&::CustomBinAxis::clone)
                , default_clone_function_type(&CustomBinAxis_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::CustomBinAxis::createClippedAxis
        
            typedef ::CustomBinAxis * ( ::CustomBinAxis::*createClippedAxis_function_type)( double,double ) const;
            typedef ::CustomBinAxis * ( CustomBinAxis_wrapper::*default_createClippedAxis_function_type)( double,double ) const;
            
            CustomBinAxis_exposer.def( 
                "createClippedAxis"
                , createClippedAxis_function_type(&::CustomBinAxis::createClippedAxis)
                , default_createClippedAxis_function_type(&CustomBinAxis_wrapper::default_createClippedAxis)
                , ( bp::arg("left"), bp::arg("right") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::CustomBinAxis::getBin
        
            typedef ::Bin1D ( ::CustomBinAxis::*getBin_function_type)( ::std::size_t ) const;
            typedef ::Bin1D ( CustomBinAxis_wrapper::*default_getBin_function_type)( ::std::size_t ) const;
            
            CustomBinAxis_exposer.def( 
                "getBin"
                , getBin_function_type(&::CustomBinAxis::getBin)
                , default_getBin_function_type(&CustomBinAxis_wrapper::default_getBin)
                , ( bp::arg("index") ) );
        
        }
        { //::CustomBinAxis::getBinCenters
        
            typedef ::std::vector< double > ( ::CustomBinAxis::*getBinCenters_function_type)(  ) const;
            typedef ::std::vector< double > ( CustomBinAxis_wrapper::*default_getBinCenters_function_type)(  ) const;
            
            CustomBinAxis_exposer.def( 
                "getBinCenters"
                , getBinCenters_function_type(&::CustomBinAxis::getBinCenters)
                , default_getBinCenters_function_type(&CustomBinAxis_wrapper::default_getBinCenters) );
        
        }
        { //::IAxis::contains
        
            typedef bool ( ::IAxis::*contains_function_type)( double ) const;
            typedef bool ( CustomBinAxis_wrapper::*default_contains_function_type)( double ) const;
            
            CustomBinAxis_exposer.def( 
                "contains"
                , contains_function_type(&::IAxis::contains)
                , default_contains_function_type(&CustomBinAxis_wrapper::default_contains)
                , ( bp::arg("value") ) );
        
        }
        { //::IAxis::createDoubleBinSize
        
            typedef ::IAxis * ( ::IAxis::*createDoubleBinSize_function_type)(  ) const;
            typedef ::IAxis * ( CustomBinAxis_wrapper::*default_createDoubleBinSize_function_type)(  ) const;
            
            CustomBinAxis_exposer.def( 
                "createDoubleBinSize"
                , createDoubleBinSize_function_type(&::IAxis::createDoubleBinSize)
                , default_createDoubleBinSize_function_type(&CustomBinAxis_wrapper::default_createDoubleBinSize)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::VariableBinAxis::findClosestIndex
        
            typedef ::size_t ( ::VariableBinAxis::*findClosestIndex_function_type)( double ) const;
            typedef ::size_t ( CustomBinAxis_wrapper::*default_findClosestIndex_function_type)( double ) const;
            
            CustomBinAxis_exposer.def( 
                "findClosestIndex"
                , findClosestIndex_function_type(&::VariableBinAxis::findClosestIndex)
                , default_findClosestIndex_function_type(&CustomBinAxis_wrapper::default_findClosestIndex)
                , ( bp::arg("value") ) );
        
        }
        { //::VariableBinAxis::getBinBoundaries
        
            typedef ::std::vector< double > ( ::VariableBinAxis::*getBinBoundaries_function_type)(  ) const;
            typedef ::std::vector< double > ( CustomBinAxis_wrapper::*default_getBinBoundaries_function_type)(  ) const;
            
            CustomBinAxis_exposer.def( 
                "getBinBoundaries"
                , getBinBoundaries_function_type(&::VariableBinAxis::getBinBoundaries)
                , default_getBinBoundaries_function_type(&CustomBinAxis_wrapper::default_getBinBoundaries) );
        
        }
        { //::VariableBinAxis::getBinCenter
        
            typedef double ( ::VariableBinAxis::*getBinCenter_function_type)( ::size_t ) const;
            typedef double ( CustomBinAxis_wrapper::*default_getBinCenter_function_type)( ::size_t ) const;
            
            CustomBinAxis_exposer.def( 
                "getBinCenter"
                , getBinCenter_function_type(&::VariableBinAxis::getBinCenter)
                , default_getBinCenter_function_type(&CustomBinAxis_wrapper::default_getBinCenter)
                , ( bp::arg("index") ) );
        
        }
        { //::VariableBinAxis::getMax
        
            typedef double ( ::VariableBinAxis::*getMax_function_type)(  ) const;
            typedef double ( CustomBinAxis_wrapper::*default_getMax_function_type)(  ) const;
            
            CustomBinAxis_exposer.def( 
                "getMax"
                , getMax_function_type(&::VariableBinAxis::getMax)
                , default_getMax_function_type(&CustomBinAxis_wrapper::default_getMax) );
        
        }
        { //::VariableBinAxis::getMin
        
            typedef double ( ::VariableBinAxis::*getMin_function_type)(  ) const;
            typedef double ( CustomBinAxis_wrapper::*default_getMin_function_type)(  ) const;
            
            CustomBinAxis_exposer.def( 
                "getMin"
                , getMin_function_type(&::VariableBinAxis::getMin)
                , default_getMin_function_type(&CustomBinAxis_wrapper::default_getMin) );
        
        }
        { //::VariableBinAxis::getSize
        
            typedef ::size_t ( ::VariableBinAxis::*getSize_function_type)(  ) const;
            typedef ::size_t ( CustomBinAxis_wrapper::*default_getSize_function_type)(  ) const;
            
            CustomBinAxis_exposer.def( 
                "getSize"
                , getSize_function_type(&::VariableBinAxis::getSize)
                , default_getSize_function_type(&CustomBinAxis_wrapper::default_getSize) );
        
        }
    }

}
