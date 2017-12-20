// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/HardParticle/FormFactorCylinder.h
//! @brief     Defines class FormFactorCylinder.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef FORMFACTORCYLINDER_H
#define FORMFACTORCYLINDER_H

#include "IFormFactorBorn.h"

//! A circular cylinder.
//! @ingroup hardParticle

class BA_CORE_API_ FormFactorCylinder : public IFormFactorBorn
{
public:
    FormFactorCylinder(double radius, double height);

    FormFactorCylinder* clone() const override final {
        return new FormFactorCylinder(m_radius, m_height); }
    void accept(INodeVisitor* visitor) const override final { visitor->visit(this); }

    double getHeight() const { return m_height; }
    double getRadius() const { return m_radius; }

    double radialExtension() const override final { return m_radius; }

    complex_t evaluate_for_q(cvector_t q) const override final;

protected:
    IFormFactor* sliceFormFactor(ZLimits limits, const IRotation& rot,
                                 kvector_t translation) const override final;

    void onChange() override final;

private:
    double m_radius;
    double m_height;
};

#endif // FORMFACTORCYLINDER_H
