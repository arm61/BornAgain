//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      GUI/coregui/Models/InstrumentItems.h
//! @brief     Defines InstrumentItems classes
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_GUI_COREGUI_MODELS_INSTRUMENTITEMS_H
#define BORNAGAIN_GUI_COREGUI_MODELS_INSTRUMENTITEMS_H

#include "GUI/coregui/Models/BeamItems.h"

class BackgroundItem;
class DataItem;
class DetectorItem;
class GroupItem;
class Instrument;
class IUnitConverter;
class MaskContainerItem;
class RealDataItem;

class BA_CORE_API_ InstrumentItem : public SessionItem {
private:
    static const QString P_IDENTIFIER;

public:
    static const QString P_BEAM;
    static const QString P_BACKGROUND;

public:
    QStringList translateList(const QStringList& list) const override;

    QString id() const;
    void setId(const QString& id);

    void setName(const QString& instrumentName);
    QString name() const;

    virtual BeamItem* beamItem() const;
    BackgroundItem* backgroundItem() const;
    GroupItem* backgroundGroup();

    virtual std::unique_ptr<Instrument> createInstrument() const = 0;
    virtual std::vector<int> shape() const = 0;
    virtual void clearMasks() {}
    virtual void importMasks(const MaskContainerItem*) {}
    virtual void updateToRealData(const RealDataItem* item) = 0;
    virtual bool alignedWith(const RealDataItem* item) const;

    //! The default user visible name when creating an instrument
    virtual QString defaultName() const = 0;

protected:
    explicit InstrumentItem(const QString& modelType);

    void initBackgroundGroup();
};

class BA_CORE_API_ SpecularInstrumentItem : public InstrumentItem {
public:
    SpecularInstrumentItem();
    ~SpecularInstrumentItem() override;

    SpecularBeamItem* beamItem() const override;

    std::unique_ptr<Instrument> createInstrument() const override;
    std::vector<int> shape() const override;
    void updateToRealData(const RealDataItem* item) override;
    bool alignedWith(const RealDataItem* item) const override;
    virtual QString defaultName() const override;

    std::unique_ptr<IUnitConverter> createUnitConverter() const;
};

class BA_CORE_API_ Instrument2DItem : public InstrumentItem {
public:
    static const QString P_DETECTOR;

    ~Instrument2DItem() override;

    DetectorItem* detectorItem() const;
    GroupItem* detectorGroup();

    void setDetectorGroup(const QString& modelType);

    void clearMasks() override;
    void importMasks(const MaskContainerItem* maskContainer) override;

    std::unique_ptr<Instrument> createInstrument() const override;

protected:
    explicit Instrument2DItem(const QString& modelType);
};

class BA_CORE_API_ GISASInstrumentItem : public Instrument2DItem {
public:
    GISASInstrumentItem();
    std::vector<int> shape() const override;
    void updateToRealData(const RealDataItem* item) override;
    virtual QString defaultName() const override;
};

class BA_CORE_API_ OffSpecularInstrumentItem : public Instrument2DItem {
public:
    static const QString P_ALPHA_AXIS;

    OffSpecularInstrumentItem();
    std::vector<int> shape() const override;
    void updateToRealData(const RealDataItem* item) override;
    virtual QString defaultName() const override;
};

#endif // BORNAGAIN_GUI_COREGUI_MODELS_INSTRUMENTITEMS_H
