// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "BasicVector3D.h"
#include "Bin.h"
#include "Crystal.h"
#include "DiffuseParticleInfo.h"
#include "FTDistributions.h"
#include "FormFactorBox.h"
#include "FormFactorCrystal.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorFullSphere.h"
#include "FormFactorGauss.h"
#include "FormFactorLorentz.h"
#include "FormFactorParallelepiped.h"
#include "FormFactorPrism3.h"
#include "FormFactorPyramid.h"
#include "FormFactorSphereGaussianRadius.h"
#include "HomogeneousMaterial.h"
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IDecoration.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IInterferenceFunction.h"
#include "IMaterial.h"
#include "IParameterized.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "ISingleton.h"
#include "Instrument.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "InterferenceFunction2DLattice.h"
#include "InterferenceFunction2DParaCrystal.h"
#include "InterferenceFunctionNone.h"
#include "IResolutionFunction2D.h"
#include "Lattice.h"
#include "Lattice2DIFParameters.h"
#include "LatticeBasis.h"
#include "Layer.h"
#include "LayerDecorator.h"
#include "LayerRoughness.h"
#include "Lattice2DIFParameters.h"
#include "MaterialManager.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "OpticalFresnel.h"
#include "ParameterPool.h"
#include "Particle.h"
#include "ParticleBuilder.h"
#include "ParticleCoreShell.h"
#include "ParticleDecoration.h"
#include "OutputData.h"
#include "OutputDataIOFactory.h"
#include "ParticleInfo.h"
#include "PositionParticleInfo.h"
#include "PythonOutputData.h"
#include "PythonPlusplusHelper.h"
#include "RealParameterWrapper.h"
#include "Simulation.h"
#include "SimulationParameters.h"
#include "IStochasticParameter.h"
#include "ResolutionFunction2DSimple.h"
#include "StochasticGaussian.h"
#include "StochasticSampledParameter.h"
#include "StochasticDoubleGate.h"
#include "Transform3D.h"
#include "Types.h"
#include "Units.h"
#include "Layer.pypp.h"

namespace bp = boost::python;

struct Layer_wrapper : Layer, bp::wrapper< Layer > {

    Layer_wrapper( )
    : Layer( )
      , bp::wrapper< Layer >(){
        // null constructor
    
    }

    Layer_wrapper(::IMaterial const * p_material, double thickness=0 )
    : Layer( boost::python::ptr(p_material), thickness )
      , bp::wrapper< Layer >(){
        // constructor
    
    }

    Layer_wrapper(::Layer const & other )
    : Layer( boost::ref(other) )
      , bp::wrapper< Layer >(){
        // copy constructor
    
    }

    virtual ::Layer * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->Layer::clone(  );
        }
    }
    
    ::Layer * default_clone(  ) const  {
        return Layer::clone( );
    }

    virtual ::IMaterial const * getMaterial(  ) const  {
        if( bp::override func_getMaterial = this->get_override( "getMaterial" ) )
            return func_getMaterial(  );
        else{
            return this->Layer::getMaterial(  );
        }
    }
    
    ::IMaterial const * default_getMaterial(  ) const  {
        return Layer::getMaterial( );
    }

    virtual ::complex_t getRefractiveIndex(  ) const  {
        if( bp::override func_getRefractiveIndex = this->get_override( "getRefractiveIndex" ) )
            return func_getRefractiveIndex(  );
        else{
            return this->Layer::getRefractiveIndex(  );
        }
    }
    
    ::complex_t default_getRefractiveIndex(  ) const  {
        return Layer::getRefractiveIndex( );
    }

    virtual double getThickness(  ) const  {
        if( bp::override func_getThickness = this->get_override( "getThickness" ) )
            return func_getThickness(  );
        else{
            return this->Layer::getThickness(  );
        }
    }
    
    double default_getThickness(  ) const  {
        return Layer::getThickness( );
    }

    virtual bool hasDWBASimulation(  ) const  {
        if( bp::override func_hasDWBASimulation = this->get_override( "hasDWBASimulation" ) )
            return func_hasDWBASimulation(  );
        else{
            return this->Layer::hasDWBASimulation(  );
        }
    }
    
    bool default_hasDWBASimulation(  ) const  {
        return Layer::hasDWBASimulation( );
    }

    virtual void setMaterial( ::IMaterial const * p_material ) {
        if( bp::override func_setMaterial = this->get_override( "setMaterial" ) )
            func_setMaterial( boost::python::ptr(p_material) );
        else{
            this->Layer::setMaterial( boost::python::ptr(p_material) );
        }
    }
    
    void default_setMaterial( ::IMaterial const * p_material ) {
        Layer::setMaterial( boost::python::ptr(p_material) );
    }

    virtual void setMaterial( ::IMaterial const * p_material, double thickness ) {
        if( bp::override func_setMaterial = this->get_override( "setMaterial" ) )
            func_setMaterial( boost::python::ptr(p_material), thickness );
        else{
            this->Layer::setMaterial( boost::python::ptr(p_material), thickness );
        }
    }
    
    void default_setMaterial( ::IMaterial const * p_material, double thickness ) {
        Layer::setMaterial( boost::python::ptr(p_material), thickness );
    }

    virtual void setThickness( double thickness ) {
        if( bp::override func_setThickness = this->get_override( "setThickness" ) )
            func_setThickness( thickness );
        else{
            this->Layer::setThickness( thickness );
        }
    }
    
    void default_setThickness( double thickness ) {
        Layer::setThickness( thickness );
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

    virtual void print_structure(  ) {
        if( bp::override func_print_structure = this->get_override( "print_structure" ) )
            func_print_structure(  );
        else{
            this->ISample::print_structure(  );
        }
    }
    
    void default_print_structure(  ) {
        ISample::print_structure( );
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
        if( dynamic_cast< Layer_wrapper * >( boost::addressof( inst ) ) ){
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

    virtual ::size_t size(  ) const  {
        if( bp::override func_size = this->get_override( "size" ) )
            return func_size(  );
        else{
            return this->ICompositeSample::size(  );
        }
    }
    
    ::size_t default_size(  ) const  {
        return ICompositeSample::size( );
    }

};

void register_Layer_class(){

    bp::class_< Layer_wrapper, bp::bases< ICompositeSample >, boost::noncopyable >( "Layer", bp::init< >() )    
        .def( bp::init< IMaterial const *, bp::optional< double > >(( bp::arg("p_material"), bp::arg("thickness")=0 )) )    
        .def( bp::init< Layer const & >(( bp::arg("other") )) )    
        .def( 
            "clone"
            , (::Layer * ( ::Layer::* )(  ) const)(&::Layer::clone)
            , (::Layer * ( Layer_wrapper::* )(  ) const)(&Layer_wrapper::default_clone)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "getMaterial"
            , (::IMaterial const * ( ::Layer::* )(  ) const)(&::Layer::getMaterial)
            , (::IMaterial const * ( Layer_wrapper::* )(  ) const)(&Layer_wrapper::default_getMaterial)
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "getRefractiveIndex"
            , (::complex_t ( ::Layer::* )(  ) const)(&::Layer::getRefractiveIndex)
            , (::complex_t ( Layer_wrapper::* )(  ) const)(&Layer_wrapper::default_getRefractiveIndex) )    
        .def( 
            "getThickness"
            , (double ( ::Layer::* )(  ) const)(&::Layer::getThickness)
            , (double ( Layer_wrapper::* )(  ) const)(&Layer_wrapper::default_getThickness) )    
        .def( 
            "hasDWBASimulation"
            , (bool ( ::Layer::* )(  ) const)(&::Layer::hasDWBASimulation)
            , (bool ( Layer_wrapper::* )(  ) const)(&Layer_wrapper::default_hasDWBASimulation) )    
        .def( 
            "setMaterial"
            , (void ( ::Layer::* )( ::IMaterial const * ) )(&::Layer::setMaterial)
            , (void ( Layer_wrapper::* )( ::IMaterial const * ) )(&Layer_wrapper::default_setMaterial)
            , ( bp::arg("p_material") ) )    
        .def( 
            "setMaterial"
            , (void ( ::Layer::* )( ::IMaterial const *,double ) )(&::Layer::setMaterial)
            , (void ( Layer_wrapper::* )( ::IMaterial const *,double ) )(&Layer_wrapper::default_setMaterial)
            , ( bp::arg("p_material"), bp::arg("thickness") ) )    
        .def( 
            "setThickness"
            , (void ( ::Layer::* )( double ) )(&::Layer::setThickness)
            , (void ( Layer_wrapper::* )( double ) )(&Layer_wrapper::default_setThickness)
            , ( bp::arg("thickness") ) )    
        .def( 
            "areParametersChanged"
            , (bool ( ::IParameterized::* )(  ) )(&::IParameterized::areParametersChanged)
            , (bool ( Layer_wrapper::* )(  ) )(&Layer_wrapper::default_areParametersChanged) )    
        .def( 
            "clearParameterPool"
            , (void ( ::IParameterized::* )(  ) )(&::IParameterized::clearParameterPool)
            , (void ( Layer_wrapper::* )(  ) )(&Layer_wrapper::default_clearParameterPool) )    
        .def( 
            "createParameterTree"
            , (::ParameterPool * ( ::IParameterized::* )(  ) const)(&::IParameterized::createParameterTree)
            , (::ParameterPool * ( Layer_wrapper::* )(  ) const)(&Layer_wrapper::default_createParameterTree)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "getCompositeSample"
            , (::ICompositeSample * ( ::ICompositeSample::* )(  ) )(&::ICompositeSample::getCompositeSample)
            , (::ICompositeSample * ( Layer_wrapper::* )(  ) )(&Layer_wrapper::default_getCompositeSample)
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "getCompositeSample"
            , (::ICompositeSample const * ( ::ICompositeSample::* )(  ) const)(&::ICompositeSample::getCompositeSample)
            , (::ICompositeSample const * ( Layer_wrapper::* )(  ) const)(&Layer_wrapper::default_getCompositeSample)
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "printParameters"
            , (void ( ::IParameterized::* )(  ) const)(&::IParameterized::printParameters)
            , (void ( Layer_wrapper::* )(  ) const)(&Layer_wrapper::default_printParameters) )    
        .def( 
            "print_structure"
            , (void ( ::ISample::* )(  ) )(&::ISample::print_structure)
            , (void ( Layer_wrapper::* )(  ) )(&Layer_wrapper::default_print_structure) )    
        .def( 
            "registerParameter"
            , (void (*)( ::IParameterized &,::std::string const &,long unsigned int ))( &Layer_wrapper::default_registerParameter )
            , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) )    
        .def( 
            "setParameterValue"
            , (bool ( ::IParameterized::* )( ::std::string const &,double ) )(&::IParameterized::setParameterValue)
            , (bool ( Layer_wrapper::* )( ::std::string const &,double ) )(&Layer_wrapper::default_setParameterValue)
            , ( bp::arg("name"), bp::arg("value") ) )    
        .def( 
            "setParametersAreChanged"
            , (void ( ::IParameterized::* )(  ) )(&::IParameterized::setParametersAreChanged)
            , (void ( Layer_wrapper::* )(  ) )(&Layer_wrapper::default_setParametersAreChanged) )    
        .def( 
            "size"
            , (::size_t ( ::ICompositeSample::* )(  ) const)(&::ICompositeSample::size)
            , (::size_t ( Layer_wrapper::* )(  ) const)(&Layer_wrapper::default_size) );

}
