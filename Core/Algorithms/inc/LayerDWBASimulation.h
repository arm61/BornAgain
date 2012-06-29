#ifndef LAYERDWBASIMULATION_H_
#define LAYERDWBASIMULATION_H_
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   LayerDWBASimulation.h
//! @brief  Definition of LayerDWBASimulation class
//! @author Scientific Computing Group at FRM II
//! @date   Jun 25, 2012

#include "DWBASimulation.h"
#include "IDoubleToComplexFunction.h"

class LayerDWBASimulation : public DWBASimulation
{
public:
    LayerDWBASimulation();
    virtual ~LayerDWBASimulation();

    void setKzFunction(const IDoubleToComplexFunction &kz_function);
    void setTFunction(const IDoubleToComplexFunction &T_function);
    void setRFunction(const IDoubleToComplexFunction &R_function);

    void setKzTAndRFunctions(const IDoubleToComplexFunction &kz_function,
            const IDoubleToComplexFunction &T_function,
            const IDoubleToComplexFunction &R_function);

protected:
    IDoubleToComplexFunction *mp_kz_function;
    IDoubleToComplexFunction *mp_T_function;
    IDoubleToComplexFunction *mp_R_function;
};


#endif /* LAYERDWBASIMULATION_H_ */