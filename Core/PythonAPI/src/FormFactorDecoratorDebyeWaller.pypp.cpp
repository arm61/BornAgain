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
#include "FormFactorDecoratorDebyeWaller.pypp.h"

namespace bp = boost::python;

struct FormFactorDecoratorDebyeWaller_wrapper : FormFactorDecoratorDebyeWaller, bp::wrapper< FormFactorDecoratorDebyeWaller > {

    FormFactorDecoratorDebyeWaller_wrapper(::IFormFactor const & form_factor, double dw_factor )
    : FormFactorDecoratorDebyeWaller( boost::ref(form_factor), dw_factor )
      , bp::wrapper< FormFactorDecoratorDebyeWaller >(){
        // constructor
    m_pyobj = 0;
    }

    FormFactorDecoratorDebyeWaller_wrapper(::IFormFactor const & form_factor, double dw_h_factor, double dw_r_factor )
    : FormFactorDecoratorDebyeWaller( boost::ref(form_factor), dw_h_factor, dw_r_factor )
      , bp::wrapper< FormFactorDecoratorDebyeWaller >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::FormFactorDecoratorDebyeWaller * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FormFactorDecoratorDebyeWaller::clone(  );
        }
    }
    
    ::FormFactorDecoratorDebyeWaller * default_clone(  ) const  {
        return FormFactorDecoratorDebyeWaller::clone( );
    }

    virtual ::complex_t evaluate( ::WavevectorInfo const & wavevectors ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( boost::ref(wavevectors) );
        else{
            return this->FormFactorDecoratorDebyeWaller::evaluate( boost::ref(wavevectors) );
        }
    }
    
    ::complex_t default_evaluate( ::WavevectorInfo const & wavevectors ) const  {
        return FormFactorDecoratorDebyeWaller::evaluate( boost::ref(wavevectors) );
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

    virtual double getRadius(  ) const  {
        if( bp::override func_getRadius = this->get_override( "getRadius" ) )
            return func_getRadius(  );
        else{
            return this->IFormFactorDecorator::getRadius(  );
        }
    }
    
    double default_getRadius(  ) const  {
        return IFormFactorDecorator::getRadius( );
    }

    virtual double getVolume(  ) const  {
        if( bp::override func_getVolume = this->get_override( "getVolume" ) )
            return func_getVolume(  );
        else{
            return this->IFormFactorDecorator::getVolume(  );
        }
    }
    
    double default_getVolume(  ) const  {
        return IFormFactorDecorator::getVolume( );
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

    virtual void setAmbientMaterial( ::IMaterial const & material ) {
        if( bp::override func_setAmbientMaterial = this->get_override( "setAmbientMaterial" ) )
            func_setAmbientMaterial( boost::ref(material) );
        else{
            this->IFormFactorDecorator::setAmbientMaterial( boost::ref(material) );
        }
    }
    
    void default_setAmbientMaterial( ::IMaterial const & material ) {
        IFormFactorDecorator::setAmbientMaterial( boost::ref(material) );
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

void register_FormFactorDecoratorDebyeWaller_class(){

    { //::FormFactorDecoratorDebyeWaller
        typedef bp::class_< FormFactorDecoratorDebyeWaller_wrapper, bp::bases< IFormFactorDecorator >, std::auto_ptr< FormFactorDecoratorDebyeWaller_wrapper >, boost::noncopyable > FormFactorDecoratorDebyeWaller_exposer_t;
        FormFactorDecoratorDebyeWaller_exposer_t FormFactorDecoratorDebyeWaller_exposer = FormFactorDecoratorDebyeWaller_exposer_t( "FormFactorDecoratorDebyeWaller", "Debye-Waller factors in radial and z directions.", bp::init< IFormFactor const &, double >(( bp::arg("form_factor"), bp::arg("dw_factor") ), "Isotropic Debye-Waller factor.") );
        bp::scope FormFactorDecoratorDebyeWaller_scope( FormFactorDecoratorDebyeWaller_exposer );
        FormFactorDecoratorDebyeWaller_exposer.def( bp::init< IFormFactor const &, double, double >(( bp::arg("form_factor"), bp::arg("dw_h_factor"), bp::arg("dw_r_factor") ), "Anisotropic Debye-Waller factor.") );
        { //::FormFactorDecoratorDebyeWaller::clone
        
            typedef ::FormFactorDecoratorDebyeWaller * ( ::FormFactorDecoratorDebyeWaller::*clone_function_type)(  ) const;
            typedef ::FormFactorDecoratorDebyeWaller * ( FormFactorDecoratorDebyeWaller_wrapper::*default_clone_function_type)(  ) const;
            
            FormFactorDecoratorDebyeWaller_exposer.def( 
                "clone"
                , clone_function_type(&::FormFactorDecoratorDebyeWaller::clone)
                , default_clone_function_type(&FormFactorDecoratorDebyeWaller_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FormFactorDecoratorDebyeWaller::evaluate
        
            typedef ::complex_t ( ::FormFactorDecoratorDebyeWaller::*evaluate_function_type)( ::WavevectorInfo const & ) const;
            typedef ::complex_t ( FormFactorDecoratorDebyeWaller_wrapper::*default_evaluate_function_type)( ::WavevectorInfo const & ) const;
            
            FormFactorDecoratorDebyeWaller_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::FormFactorDecoratorDebyeWaller::evaluate)
                , default_evaluate_function_type(&FormFactorDecoratorDebyeWaller_wrapper::default_evaluate)
                , ( bp::arg("wavevectors") ) );
        
        }
        { //::ISample::cloneInvertB
        
            typedef ::ISample * ( ::ISample::*cloneInvertB_function_type)(  ) const;
            typedef ::ISample * ( FormFactorDecoratorDebyeWaller_wrapper::*default_cloneInvertB_function_type)(  ) const;
            
            FormFactorDecoratorDebyeWaller_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ISample::cloneInvertB)
                , default_cloneInvertB_function_type(&FormFactorDecoratorDebyeWaller_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( FormFactorDecoratorDebyeWaller_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            FormFactorDecoratorDebyeWaller_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&FormFactorDecoratorDebyeWaller_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::ISample::getChildren
        
            typedef ::std::vector< const ISample* > ( ::ISample::*getChildren_function_type)(  ) const;
            typedef ::std::vector< const ISample* > ( FormFactorDecoratorDebyeWaller_wrapper::*default_getChildren_function_type)(  ) const;
            
            FormFactorDecoratorDebyeWaller_exposer.def( 
                "getChildren"
                , getChildren_function_type(&::ISample::getChildren)
                , default_getChildren_function_type(&FormFactorDecoratorDebyeWaller_wrapper::default_getChildren) );
        
        }
        { //::IFormFactorDecorator::getRadius
        
            typedef double ( ::IFormFactorDecorator::*getRadius_function_type)(  ) const;
            typedef double ( FormFactorDecoratorDebyeWaller_wrapper::*default_getRadius_function_type)(  ) const;
            
            FormFactorDecoratorDebyeWaller_exposer.def( 
                "getRadius"
                , getRadius_function_type(&::IFormFactorDecorator::getRadius)
                , default_getRadius_function_type(&FormFactorDecoratorDebyeWaller_wrapper::default_getRadius) );
        
        }
        { //::IFormFactorDecorator::getVolume
        
            typedef double ( ::IFormFactorDecorator::*getVolume_function_type)(  ) const;
            typedef double ( FormFactorDecoratorDebyeWaller_wrapper::*default_getVolume_function_type)(  ) const;
            
            FormFactorDecoratorDebyeWaller_exposer.def( 
                "getVolume"
                , getVolume_function_type(&::IFormFactorDecorator::getVolume)
                , default_getVolume_function_type(&FormFactorDecoratorDebyeWaller_wrapper::default_getVolume) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( FormFactorDecoratorDebyeWaller_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            FormFactorDecoratorDebyeWaller_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&FormFactorDecoratorDebyeWaller_wrapper::default_printSampleTree) );
        
        }
        { //::IFormFactorDecorator::setAmbientMaterial
        
            typedef void ( ::IFormFactorDecorator::*setAmbientMaterial_function_type)( ::IMaterial const & ) ;
            typedef void ( FormFactorDecoratorDebyeWaller_wrapper::*default_setAmbientMaterial_function_type)( ::IMaterial const & ) ;
            
            FormFactorDecoratorDebyeWaller_exposer.def( 
                "setAmbientMaterial"
                , setAmbientMaterial_function_type(&::IFormFactorDecorator::setAmbientMaterial)
                , default_setAmbientMaterial_function_type(&FormFactorDecoratorDebyeWaller_wrapper::default_setAmbientMaterial)
                , ( bp::arg("material") ) );
        
        }
        { //::ISample::size
        
            typedef ::size_t ( ::ISample::*size_function_type)(  ) const;
            typedef ::size_t ( FormFactorDecoratorDebyeWaller_wrapper::*default_size_function_type)(  ) const;
            
            FormFactorDecoratorDebyeWaller_exposer.def( 
                "size"
                , size_function_type(&::ISample::size)
                , default_size_function_type(&FormFactorDecoratorDebyeWaller_wrapper::default_size) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( FormFactorDecoratorDebyeWaller_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            FormFactorDecoratorDebyeWaller_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&FormFactorDecoratorDebyeWaller_wrapper::default_transferToCPP) );
        
        }
    }

}
