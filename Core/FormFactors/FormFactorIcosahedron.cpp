// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/FormFactorzicosahedron.cpp
//! @brief     Implements class FormFactorIcosahedron.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015-16
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FormFactorIcosahedron.h"
#include "BornAgainNamespace.h"
#include "FormFactorBox.h"
#include "MathFunctions.h"

const FormFactorPolyhedron::Topology FormFactorIcosahedron::topology = {
    // bottom:
    { {  0,  2,  1 }, false },
    // 1st row:
    { {  0,  5,  2 }, false },
    { {  2,  3,  1 }, false },
    { {  1,  4,  0 }, false },
    // 2nd row:
    { {  0,  6,  5 }, false },
    { {  2,  5,  8 }, false },
    { {  2,  8,  3 }, false },
    { {  1,  3,  7 }, false },
    { {  1,  7,  4 }, false },
    { {  0,  4,  6 }, false },
    // 3rd row:
    { {  3,  8,  9 }, false },
    { {  5, 11,  8 }, false },
    { {  5,  6, 11 }, false },
    { {  4, 10,  6 }, false },
    { {  4,  7, 10 }, false },
    { {  3,  9,  7 }, false },
    // 4th row:
    { {  8, 11,  9 }, false },
    { {  6, 10, 11 }, false },
    { {  7,  9, 10 }, false },
    // top:
    { {  9, 11, 10 }, false }
};


FormFactorIcosahedron::FormFactorIcosahedron(double edge)
    : FormFactorPolyhedron()
    , m_edge(edge)
{
    setName(BornAgain::FFIcosahedronType);
    registerParameter(BornAgain::Edge, &m_edge);
    onChange();
}

void FormFactorIcosahedron::onChange()
{
    double a = m_edge;
    setVertices( {
        {  0.5773502691896258*a,                   0*a, -0.7557613140761708*a},
        {  -0.288675134594813*a,                 0.5*a, -0.7557613140761708*a},
        {  -0.288675134594813*a,                -0.5*a, -0.7557613140761708*a},
        { -0.9341723589627158*a,                   0*a, -0.1784110448865449*a},
        {   0.467086179481358*a,  0.8090169943749475*a, -0.1784110448865449*a},
        {   0.467086179481358*a, -0.8090169943749475*a, -0.1784110448865449*a},
        {  0.9341723589627158*a,                   0*a,  0.1784110448865449*a},
        {  -0.467086179481358*a,  0.8090169943749475*a,  0.1784110448865449*a},
        {  -0.467086179481358*a, -0.8090169943749475*a,  0.1784110448865449*a},
        { -0.5773502691896258*a,                   0*a,  0.7557613140761708*a},
        {   0.288675134594813*a,                 0.5*a,  0.7557613140761708*a},
        {   0.288675134594813*a,                -0.5*a,  0.7557613140761708*a} } );
    assert_platonic();
    m_z_origin = -0.7557613140761708*a;
    m_sym_Ci = true;

    FormFactorPolyhedron::precompute();
}

FormFactorIcosahedron* FormFactorIcosahedron::clone() const
{
    return new FormFactorIcosahedron(m_edge);
}

void FormFactorIcosahedron::accept(ISampleVisitor *visitor) const
{
    visitor->visit(this);
}
