// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonCoreAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "PositionParticleInfo.pypp.h"

namespace bp = boost::python;

struct PositionParticleInfo_wrapper : PositionParticleInfo, bp::wrapper< PositionParticleInfo > {

    PositionParticleInfo_wrapper(::IParticle const & particle, ::kvector_t position, double abundance=0 )
    : PositionParticleInfo( boost::ref(particle), position, abundance )
      , bp::wrapper< PositionParticleInfo >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::PositionParticleInfo * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->PositionParticleInfo::clone(  );
        }
    }
    
    ::PositionParticleInfo * default_clone(  ) const  {
        return PositionParticleInfo::clone( );
    }

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else{
            return this->IParameterized::areParametersChanged(  );
        }
    }
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual void clearParameterPool(  ) {
        if( bp::override func_clearParameterPool = this->get_override( "clearParameterPool" ) )
            func_clearParameterPool(  );
        else{
            this->IParameterized::clearParameterPool(  );
        }
    }
    
    void default_clearParameterPool(  ) {
        IParameterized::clearParameterPool( );
    }

    virtual ::ParticleInfo * cloneInvertB(  ) const  {
        if( bp::override func_cloneInvertB = this->get_override( "cloneInvertB" ) )
            return func_cloneInvertB(  );
        else{
            return this->ParticleInfo::cloneInvertB(  );
        }
    }
    
    ::ParticleInfo * default_cloneInvertB(  ) const  {
        return ParticleInfo::cloneInvertB( );
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

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else{
            return this->IParameterized::createParameterTree(  );
        }
    }
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual ::ICompositeSample * getCompositeSample(  ) {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ICompositeSample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample * default_getCompositeSample(  ) {
        return ICompositeSample::getCompositeSample( );
    }

    virtual ::ICompositeSample const * getCompositeSample(  ) const  {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ICompositeSample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample const * default_getCompositeSample(  ) const  {
        return ICompositeSample::getCompositeSample( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else{
            this->IParameterized::printParameters(  );
        }
    }
    
    void default_printParameters(  ) const  {
        IParameterized::printParameters( );
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

    virtual void registerParameter( ::std::string const & name, double * parpointer ) {
        namespace bpl = boost::python;
        if( bpl::override func_registerParameter = this->get_override( "registerParameter" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_registerParameter.ptr(), name, parpointer );
        }
        else{
            IParameterized::registerParameter( name, parpointer );
        }
    }
    
    static void default_registerParameter( ::IParameterized & inst, ::std::string const & name, long unsigned int parpointer ){
        if( dynamic_cast< PositionParticleInfo_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
    }

    virtual bool setParameterValue( ::std::string const & name, double value ) {
        if( bp::override func_setParameterValue = this->get_override( "setParameterValue" ) )
            return func_setParameterValue( name, value );
        else{
            return this->IParameterized::setParameterValue( name, value );
        }
    }
    
    bool default_setParameterValue( ::std::string const & name, double value ) {
        return IParameterized::setParameterValue( name, value );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else{
            this->IParameterized::setParametersAreChanged(  );
        }
    }
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

    virtual ::std::size_t size(  ) const  {
        if( bp::override func_size = this->get_override( "size" ) )
            return func_size(  );
        else{
            return this->ICompositeSample::size(  );
        }
    }
    
    ::std::size_t default_size(  ) const  {
        return ICompositeSample::size( );
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

void register_PositionParticleInfo_class(){

    { //::PositionParticleInfo
        typedef bp::class_< PositionParticleInfo_wrapper, bp::bases< ParticleInfo >, std::auto_ptr< PositionParticleInfo_wrapper >, boost::noncopyable > PositionParticleInfo_exposer_t;
        PositionParticleInfo_exposer_t PositionParticleInfo_exposer = PositionParticleInfo_exposer_t( "PositionParticleInfo", bp::init< IParticle const &, kvector_t, bp::optional< double > >(( bp::arg("particle"), bp::arg("position"), bp::arg("abundance")=0 )) );
        bp::scope PositionParticleInfo_scope( PositionParticleInfo_exposer );
        { //::PositionParticleInfo::clone
        
            typedef ::PositionParticleInfo * ( ::PositionParticleInfo::*clone_function_type)(  ) const;
            typedef ::PositionParticleInfo * ( PositionParticleInfo_wrapper::*default_clone_function_type)(  ) const;
            
            PositionParticleInfo_exposer.def( 
                "clone"
                , clone_function_type(&::PositionParticleInfo::clone)
                , default_clone_function_type(&PositionParticleInfo_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::PositionParticleInfo::getPosition
        
            typedef ::kvector_t ( ::PositionParticleInfo::*getPosition_function_type)(  ) const;
            
            PositionParticleInfo_exposer.def( 
                "getPosition"
                , getPosition_function_type( &::PositionParticleInfo::getPosition ) );
        
        }
        { //::PositionParticleInfo::setPosition
        
            typedef void ( ::PositionParticleInfo::*setPosition_function_type)( ::kvector_t ) ;
            
            PositionParticleInfo_exposer.def( 
                "setPosition"
                , setPosition_function_type( &::PositionParticleInfo::setPosition )
                , ( bp::arg("position") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type)(  ) ;
            typedef bool ( PositionParticleInfo_wrapper::*default_areParametersChanged_function_type)(  ) ;
            
            PositionParticleInfo_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&PositionParticleInfo_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type)(  ) ;
            typedef void ( PositionParticleInfo_wrapper::*default_clearParameterPool_function_type)(  ) ;
            
            PositionParticleInfo_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&PositionParticleInfo_wrapper::default_clearParameterPool) );
        
        }
        { //::ParticleInfo::cloneInvertB
        
            typedef ::ParticleInfo * ( ::ParticleInfo::*cloneInvertB_function_type)(  ) const;
            typedef ::ParticleInfo * ( PositionParticleInfo_wrapper::*default_cloneInvertB_function_type)(  ) const;
            
            PositionParticleInfo_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ParticleInfo::cloneInvertB)
                , default_cloneInvertB_function_type(&PositionParticleInfo_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( PositionParticleInfo_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            PositionParticleInfo_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&PositionParticleInfo_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type)(  ) const;
            typedef ::ParameterPool * ( PositionParticleInfo_wrapper::*default_createParameterTree_function_type)(  ) const;
            
            PositionParticleInfo_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&PositionParticleInfo_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ICompositeSample::getCompositeSample
        
            typedef ::ICompositeSample * ( ::ICompositeSample::*getCompositeSample_function_type)(  ) ;
            typedef ::ICompositeSample * ( PositionParticleInfo_wrapper::*default_getCompositeSample_function_type)(  ) ;
            
            PositionParticleInfo_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ICompositeSample::getCompositeSample)
                , default_getCompositeSample_function_type(&PositionParticleInfo_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ICompositeSample::getCompositeSample
        
            typedef ::ICompositeSample const * ( ::ICompositeSample::*getCompositeSample_function_type)(  ) const;
            typedef ::ICompositeSample const * ( PositionParticleInfo_wrapper::*default_getCompositeSample_function_type)(  ) const;
            
            PositionParticleInfo_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ICompositeSample::getCompositeSample)
                , default_getCompositeSample_function_type(&PositionParticleInfo_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type)(  ) const;
            typedef void ( PositionParticleInfo_wrapper::*default_printParameters_function_type)(  ) const;
            
            PositionParticleInfo_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&PositionParticleInfo_wrapper::default_printParameters) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( PositionParticleInfo_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            PositionParticleInfo_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&PositionParticleInfo_wrapper::default_printSampleTree) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            PositionParticleInfo_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &PositionParticleInfo_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type)( ::std::string const &,double ) ;
            typedef bool ( PositionParticleInfo_wrapper::*default_setParameterValue_function_type)( ::std::string const &,double ) ;
            
            PositionParticleInfo_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&PositionParticleInfo_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type)(  ) ;
            typedef void ( PositionParticleInfo_wrapper::*default_setParametersAreChanged_function_type)(  ) ;
            
            PositionParticleInfo_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&PositionParticleInfo_wrapper::default_setParametersAreChanged) );
        
        }
        { //::ICompositeSample::size
        
            typedef ::std::size_t ( ::ICompositeSample::*size_function_type)(  ) const;
            typedef ::std::size_t ( PositionParticleInfo_wrapper::*default_size_function_type)(  ) const;
            
            PositionParticleInfo_exposer.def( 
                "size"
                , size_function_type(&::ICompositeSample::size)
                , default_size_function_type(&PositionParticleInfo_wrapper::default_size) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( PositionParticleInfo_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            PositionParticleInfo_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&PositionParticleInfo_wrapper::default_transferToCPP) );
        
        }
    }

}
