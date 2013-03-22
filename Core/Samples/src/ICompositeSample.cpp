// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Samples/src/ICompositeSample.cpp
//! @brief     Implements class ICompositeSample.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke 
//
// ************************************************************************** //

#include "ICompositeSample.h"
#include "ICompositeIterator.h"
#include "Utils.h"
#include "MessageService.h"
#include <vector>
#include <sstream>
#include "Exceptions.h"

ICompositeSample *ICompositeSample::clone() const
{
    throw NotImplementedException("ICompositeSample::clone() -> Error: not implemented");
}


//! register child in the container

void ICompositeSample::registerChild(ISample *sample)
{
    if(sample) {
        m_samples.push_back(sample);
    } else {
        msglog(MSG::ERROR) << "ICompositeSample::registerChild() -> Attempt to register NULL child in this " << *this;
    }
}

//! remove registere child from the container

void ICompositeSample::deregisterChild(ISample *sample)
{
    m_samples.remove(sample);
}

//! create general iterator to walk through the tree of registered composite children

ICompositeIterator ICompositeSample::createIterator()
{
    return ICompositeIterator(this);
}
