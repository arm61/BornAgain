// ************************************************************************** //
//
//  heinzlibs:  Library collection of the Scientific Computing Group at
//              Heinz Maier-Leibnitz Zentrum (MLZ) Garching
//
//  libgeo3d:   Library for three-dimensional Euclidian geometry,
//              based on CLHEP/Geometry 1.9 of 1.4.2003,
//              forked after v 1.6 2003/10/24 21:39:45
//
//! @file       Geometry/src/Transform3D.cpp
//! @brief      implements core methods of class Transform3D.
//!
//! @homepage   http://apps.jcns.fz-juelich.de/BornAgain
//! @license    GNU General Public License v3 or higher (see COPYING)
//! @copyright  Forschungszentrum Jülich GmbH 2013
//! @authors    E. Chernyaev <Evgueni.Tcherniaev@cern.ch> 1996-2003
//! @authors    C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//!
//! Changes w.r.t. CLHEP:
//! - eliminated support for type float
//! - reworked doxygen comments
//
// ************************************************************************** //

#include <iostream>
#include <cmath>	// double std::abs()
#include <stdlib.h>	// int std::abs()
#include "Transform3D.h"

namespace Geometry {

const Transform3D Transform3D::Identity = Transform3D ();

double Transform3D::operator () (int i, int j) const
{
    if (i == 0) {
        if (j == 0) { return xx_; }
        if (j == 1) { return xy_; }
        if (j == 2) { return xz_; }
    } else if (i == 1) {
        if (j == 0) { return yx_; }
        if (j == 1) { return yy_; }
        if (j == 2) { return yz_; }
    } else if (i == 2) {
        if (j == 0) { return zx_; }
        if (j == 1) { return zy_; }
        if (j == 2) { return zz_; }
    } else if (i == 3) {
        if (j == 0) { return 0.0; }
        if (j == 1) { return 0.0; }
        if (j == 2) { return 0.0; }
    }
    std::cerr << "Transform3D subscripting: bad indeces "
              << "(" << i << "," << j << ")" << std::endl;
    return 0.0;
}

//! Concatenation of transforms. Read efficiency warning!

Transform3D Transform3D::operator*(const Transform3D & b) const
{
    return Transform3D
        (xx_*b.xx_+xy_*b.yx_+xz_*b.zx_,
         xx_*b.xy_+xy_*b.yy_+xz_*b.zy_,
         xx_*b.xz_+xy_*b.yz_+xz_*b.zz_, 
         yx_*b.xx_+yy_*b.yx_+yz_*b.zx_,
         yx_*b.xy_+yy_*b.yy_+yz_*b.zy_,
         yx_*b.xz_+yy_*b.yz_+yz_*b.zz_, 
         zx_*b.xx_+zy_*b.yx_+zz_*b.zx_,
         zx_*b.xy_+zy_*b.yy_+zz_*b.zy_,
         zx_*b.xz_+zy_*b.yz_+zz_*b.zz_ );
}

//! Returns the inverse transformation.
//!
//! @author E. Chernyaev 1996

Transform3D Transform3D::inverse() const
{
    double detxx = yy_*zz_-yz_*zy_;
    double detxy = yx_*zz_-yz_*zx_;
    double detxz = yx_*zy_-yy_*zx_;
    double det   = xx_*detxx - xy_*detxy + xz_*detxz;
    if (det == 0) {
        std::cerr << "Transform3D::inverse error: zero determinant" << std::endl;
        return Transform3D();
    }
    det = 1./det; detxx *= det; detxy *= det; detxz *= det;
    double detyx = (xy_*zz_ - xz_*zy_)*det;
    double detyy = (xx_*zz_ - xz_*zx_)*det;
    double detyz = (xx_*zy_ - xy_*zx_)*det;
    double detzx = (xy_*yz_ - xz_*yy_)*det;
    double detzy = (xx_*yz_ - xz_*yx_)*det;
    double detzz = (xx_*yy_ - xy_*yx_)*det;
    return Transform3D
            (detxx, -detyx,  detzx,
             -detxy,  detyy, -detzy,
             detxz, -detyz,  detzz );
}

//! Difference between corresponding matrix elements less than tolerance?

bool Transform3D::isNear(const Transform3D & t, double tolerance) const
{
    return ( (std::abs(xx_ - t.xx_) <= tolerance) &&
             (std::abs(xy_ - t.xy_) <= tolerance) &&
             (std::abs(xz_ - t.xz_) <= tolerance) &&
             (std::abs(yx_ - t.yx_) <= tolerance) &&
             (std::abs(yy_ - t.yy_) <= tolerance) &&
             (std::abs(yz_ - t.yz_) <= tolerance) &&
             (std::abs(zx_ - t.zx_) <= tolerance) &&
             (std::abs(zy_ - t.zy_) <= tolerance) &&
             (std::abs(zz_ - t.zz_) <= tolerance) );
}

//! Test for equality.

bool Transform3D::operator==(const Transform3D & t) const
{
    return (this == &t) ? true :
                          (xx_==t.xx_ && xy_==t.xy_ && xz_==t.xz_ &&
                           yx_==t.yx_ && yy_==t.yy_ && yz_==t.yz_ &&
                           zx_==t.zx_ && zy_==t.zy_ && zz_==t.zz_ );
}


//! Construct rotation by angle a around axis p1->p2.
//!
//! @author E. Chernyaev 1996

Rotate3D::Rotate3D(double a,
                   const Point3D<double> & p1,
                   const Point3D<double> & p2)
        : Transform3D()
{
    if (a == 0) return;

    double cx = p2.x()-p1.x(), cy = p2.y()-p1.y(), cz = p2.z()-p1.z();
    double ll = std::sqrt(cx*cx + cy*cy + cz*cz);
    if (ll == 0) {
        std::cerr << "Rotate3D: zero axis" << std::endl;
    } else {
        double cosa = std::cos(a), sina = std::sin(a);
        cx /= ll; cy /= ll; cz /= ll;

        double txx = cosa + (1-cosa)*cx*cx;
        double txy =        (1-cosa)*cx*cy - sina*cz;
        double txz =        (1-cosa)*cx*cz + sina*cy;

        double tyx =        (1-cosa)*cy*cx + sina*cz;
        double tyy = cosa + (1-cosa)*cy*cy;
        double tyz =        (1-cosa)*cy*cz - sina*cx;

        double tzx =        (1-cosa)*cz*cx - sina*cy;
        double tzy =        (1-cosa)*cz*cy + sina*cx;
        double tzz = cosa + (1-cosa)*cz*cz;

        setTransform(txx, txy, txz,
                     tyx, tyy, tyz,
                     tzx, tzy, tzz);
    }
}

}  // namespace Geometry
