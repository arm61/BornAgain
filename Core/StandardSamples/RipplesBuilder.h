// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/StandardSamples/RipplesBuilder.h
//! @brief     Declares classes to build various ripples.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef RIPPLESBUILDER_H
#define RIPPLESBUILDER_H

#include "ISampleBuilder.h"

//! @class CosineRippleBuilder
//! @ingroup standard_samples
//! @brief Builds sample: cosine ripple within the 1D-paracrystal model

class BA_CORE_API_ CosineRippleBuilder : public ISampleBuilder
{
public:
    CosineRippleBuilder();
    ISample *buildSample() const;

protected:
    void init_parameters();

private:
    double m_w; //width
    double m_h; //heigth
    double m_l; //length

    double m_interf_distance;
    double m_interf_width;
};


//! @class TriangularRippleBuilder
//! @ingroup standard_samples
//! @brief Builds sample: triangular ripple within the 1D-paracrystal model
//! (from PRB 85, 235415, 2012)

class BA_CORE_API_ TriangularRippleBuilder : public ISampleBuilder
{
public:
    TriangularRippleBuilder();
    ISample *buildSample() const;

protected:
    void init_parameters();

private:
    double m_w; //width
    double m_h; //heigth
    double m_l; //length
    double m_d; //asymetry
    double m_interf_distance;
    double m_interf_width;
};

#endif // RIPPLESBUILDER_H