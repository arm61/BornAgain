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
#include "FormFactorPrism6.pypp.h"

namespace bp = boost::python;

struct FormFactorPrism6_wrapper : FormFactorPrism6, bp::wrapper< FormFactorPrism6 > {

    FormFactorPrism6_wrapper(double radius, double height )
    : FormFactorPrism6( radius, height )
      , bp::wrapper< FormFactorPrism6 >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::FormFactorPrism6 * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FormFactorPrism6::clone(  );
        }
    }
    
    ::FormFactorPrism6 * default_clone(  ) const  {
        return FormFactorPrism6::clone( );
    }

    virtual ::complex_t evaluate_for_q( ::cvector_t const & q ) const  {
        if( bp::override func_evaluate_for_q = this->get_override( "evaluate_for_q" ) )
            return func_evaluate_for_q( boost::ref(q) );
        else{
            return this->FormFactorPrism6::evaluate_for_q( boost::ref(q) );
        }
    }
    
    ::complex_t default_evaluate_for_q( ::cvector_t const & q ) const  {
        return FormFactorPrism6::evaluate_for_q( boost::ref(q) );
    }

    virtual double getRadius(  ) const  {
        if( bp::override func_getRadius = this->get_override( "getRadius" ) )
            return func_getRadius(  );
        else{
            return this->FormFactorPrism6::getRadius(  );
        }
    }
    
    double default_getRadius(  ) const  {
        return FormFactorPrism6::getRadius( );
    }

    virtual ::ISample * cloneInvertB(  ) const  {
        if( bp::override func_cloneInvertB = this->get_override( "cloneInvertB" ) )
            return func_cloneInvertB(  );
        else{
            return this->ISample::cloneInvertB(  );
        }
    }
    
    ::ISample * default_cloneInvertB(  ) const  {
        return ISample::cloneInvertB( );
    }

    virtual bool containsMagneticMaterial(  ) const  {
        if( bp::override func_containsMagneticMaterial = this->get_override( "containsMagneticMaterial" ) )
            return func_containsMagneticMaterial(  );
        else{
            return this->ISample::containsMagneticMaterial(  );
        }
    }
    
    bool default_containsMagneticMaterial(  ) const  {
        return ISample::containsMagneticMaterial( );
    }

    virtual ::complex_t evaluate( ::WavevectorInfo const & wavevectors ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( boost::ref(wavevectors) );
        else{
            return this->IFormFactorBorn::evaluate( boost::ref(wavevectors) );
        }
    }
    
    ::complex_t default_evaluate( ::WavevectorInfo const & wavevectors ) const  {
        return IFormFactorBorn::evaluate( boost::ref(wavevectors) );
    }

    virtual ::std::vector< const ISample* > getChildren(  ) const  {
        if( bp::override func_getChildren = this->get_override( "getChildren" ) )
            return func_getChildren(  );
        else{
            return this->ISample::getChildren(  );
        }
    }
    
    ::std::vector< const ISample* > default_getChildren(  ) const  {
        return ISample::getChildren( );
    }

    virtual double getVolume(  ) const  {
        if( bp::override func_getVolume = this->get_override( "getVolume" ) )
            return func_getVolume(  );
        else{
            return this->IFormFactor::getVolume(  );
        }
    }
    
    double default_getVolume(  ) const  {
        return IFormFactor::getVolume( );
    }

    virtual void printSampleTree(  ) {
        if( bp::override func_printSampleTree = this->get_override( "printSampleTree" ) )
            func_printSampleTree(  );
        else{
            this->ISample::printSampleTree(  );
        }
    }
    
    void default_printSampleTree(  ) {
        ISample::printSampleTree( );
    }

    virtual void setAmbientMaterial( ::IMaterial const & arg0 ) {
        if( bp::override func_setAmbientMaterial = this->get_override( "setAmbientMaterial" ) )
            func_setAmbientMaterial( boost::ref(arg0) );
        else{
            this->IFormFactor::setAmbientMaterial( boost::ref(arg0) );
        }
    }
    
    void default_setAmbientMaterial( ::IMaterial const & arg0 ) {
        IFormFactor::setAmbientMaterial( boost::ref(arg0) );
    }

    virtual ::size_t size(  ) const  {
        if( bp::override func_size = this->get_override( "size" ) )
            return func_size(  );
        else{
            return this->ISample::size(  );
        }
    }
    
    ::size_t default_size(  ) const  {
        return ISample::size( );
    }

    virtual void transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        if( bp::override func_transferToCPP = this->get_override( "transferToCPP" ) )
            func_transferToCPP(  );
        else{
            this->ICloneable::transferToCPP(  );
        }
    }
    
    void default_transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        ICloneable::transferToCPP( );
    }

    PyObject* m_pyobj;

};

void register_FormFactorPrism6_class(){

    { //::FormFactorPrism6
        typedef bp::class_< FormFactorPrism6_wrapper, bp::bases< IFormFactorBorn >, std::auto_ptr< FormFactorPrism6_wrapper >, boost::noncopyable > FormFactorPrism6_exposer_t;
        FormFactorPrism6_exposer_t FormFactorPrism6_exposer = FormFactorPrism6_exposer_t( "FormFactorPrism6", "The formfactor of a prism based on a regular hexagonal.", bp::init< double, double >(( bp::arg("radius"), bp::arg("height") ), "Prism6 constructor.\n\n:Parameters:\n  - 'radius' - of hexagonal base (different from R in IsGisaxs)\n  - 'height' - of Prism6\n") );
        bp::scope FormFactorPrism6_scope( FormFactorPrism6_exposer );
        { //::FormFactorPrism6::clone
        
            typedef ::FormFactorPrism6 * ( ::FormFactorPrism6::*clone_function_type)(  ) const;
            typedef ::FormFactorPrism6 * ( FormFactorPrism6_wrapper::*default_clone_function_type)(  ) const;
            
            FormFactorPrism6_exposer.def( 
                "clone"
                , clone_function_type(&::FormFactorPrism6::clone)
                , default_clone_function_type(&FormFactorPrism6_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FormFactorPrism6::evaluate_for_q
        
            typedef ::complex_t ( ::FormFactorPrism6::*evaluate_for_q_function_type)( ::cvector_t const & ) const;
            typedef ::complex_t ( FormFactorPrism6_wrapper::*default_evaluate_for_q_function_type)( ::cvector_t const & ) const;
            
            FormFactorPrism6_exposer.def( 
                "evaluate_for_q"
                , evaluate_for_q_function_type(&::FormFactorPrism6::evaluate_for_q)
                , default_evaluate_for_q_function_type(&FormFactorPrism6_wrapper::default_evaluate_for_q)
                , ( bp::arg("q") ) );
        
        }
        { //::FormFactorPrism6::getHeight
        
            typedef double ( ::FormFactorPrism6::*getHeight_function_type)(  ) const;
            
            FormFactorPrism6_exposer.def( 
                "getHeight"
                , getHeight_function_type( &::FormFactorPrism6::getHeight ) );
        
        }
        { //::FormFactorPrism6::getRadius
        
            typedef double ( ::FormFactorPrism6::*getRadius_function_type)(  ) const;
            typedef double ( FormFactorPrism6_wrapper::*default_getRadius_function_type)(  ) const;
            
            FormFactorPrism6_exposer.def( 
                "getRadius"
                , getRadius_function_type(&::FormFactorPrism6::getRadius)
                , default_getRadius_function_type(&FormFactorPrism6_wrapper::default_getRadius) );
        
        }
        { //::ISample::cloneInvertB
        
            typedef ::ISample * ( ::ISample::*cloneInvertB_function_type)(  ) const;
            typedef ::ISample * ( FormFactorPrism6_wrapper::*default_cloneInvertB_function_type)(  ) const;
            
            FormFactorPrism6_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ISample::cloneInvertB)
                , default_cloneInvertB_function_type(&FormFactorPrism6_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( FormFactorPrism6_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            FormFactorPrism6_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&FormFactorPrism6_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IFormFactorBorn::evaluate
        
            typedef ::complex_t ( ::IFormFactorBorn::*evaluate_function_type)( ::WavevectorInfo const & ) const;
            typedef ::complex_t ( FormFactorPrism6_wrapper::*default_evaluate_function_type)( ::WavevectorInfo const & ) const;
            
            FormFactorPrism6_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::IFormFactorBorn::evaluate)
                , default_evaluate_function_type(&FormFactorPrism6_wrapper::default_evaluate)
                , ( bp::arg("wavevectors") ) );
        
        }
        { //::ISample::getChildren
        
            typedef ::std::vector< const ISample* > ( ::ISample::*getChildren_function_type)(  ) const;
            typedef ::std::vector< const ISample* > ( FormFactorPrism6_wrapper::*default_getChildren_function_type)(  ) const;
            
            FormFactorPrism6_exposer.def( 
                "getChildren"
                , getChildren_function_type(&::ISample::getChildren)
                , default_getChildren_function_type(&FormFactorPrism6_wrapper::default_getChildren) );
        
        }
        { //::IFormFactor::getVolume
        
            typedef double ( ::IFormFactor::*getVolume_function_type)(  ) const;
            typedef double ( FormFactorPrism6_wrapper::*default_getVolume_function_type)(  ) const;
            
            FormFactorPrism6_exposer.def( 
                "getVolume"
                , getVolume_function_type(&::IFormFactor::getVolume)
                , default_getVolume_function_type(&FormFactorPrism6_wrapper::default_getVolume) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( FormFactorPrism6_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            FormFactorPrism6_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&FormFactorPrism6_wrapper::default_printSampleTree) );
        
        }
        { //::IFormFactor::setAmbientMaterial
        
            typedef void ( ::IFormFactor::*setAmbientMaterial_function_type)( ::IMaterial const & ) ;
            typedef void ( FormFactorPrism6_wrapper::*default_setAmbientMaterial_function_type)( ::IMaterial const & ) ;
            
            FormFactorPrism6_exposer.def( 
                "setAmbientMaterial"
                , setAmbientMaterial_function_type(&::IFormFactor::setAmbientMaterial)
                , default_setAmbientMaterial_function_type(&FormFactorPrism6_wrapper::default_setAmbientMaterial)
                , ( bp::arg("arg0") ) );
        
        }
        { //::ISample::size
        
            typedef ::size_t ( ::ISample::*size_function_type)(  ) const;
            typedef ::size_t ( FormFactorPrism6_wrapper::*default_size_function_type)(  ) const;
            
            FormFactorPrism6_exposer.def( 
                "size"
                , size_function_type(&::ISample::size)
                , default_size_function_type(&FormFactorPrism6_wrapper::default_size) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( FormFactorPrism6_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            FormFactorPrism6_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&FormFactorPrism6_wrapper::default_transferToCPP) );
        
        }
    }

}
