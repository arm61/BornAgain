// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tools/inc/AxisBin.h
//! @brief     Defines class AxisBin.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef BORNAGAIN_EIGENCORE_H
#define BORNAGAIN_EIGENCORE_H

//! This include file is introduced to deal with Eigen alignment

//! See general desciption of the alignment problem
//! http://eigen.tuxfamily.org/dox-devel/group__TopicUnalignedArrayAssert.html

//! See also issue with POSIX_ADVISORY_INFO at http://eigen.tuxfamily.org/bz/show_bug.cgi?id=554

#ifndef GCCXML_SKIP_THIS
//#ifdef _WIN32
//#define EIGEN_DONT_ALIGN_STATICALLY 1
//#define EIGEN_DONT_ALIGN 1
//#define EIGEN_DONT_VECTORIZE 1
//#define EIGEN_DISABLE_UNALIGNED_ARRAY_ASSERT 1
//#endif
#ifndef _WIN32
#include <unistd.h>
#endif
#include <Eigen/Core>
#endif


#endif //BORNAGAIN_EIGENCORE_H
