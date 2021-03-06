//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      GUI/coregui/Models/RealDataItem.h
//! @brief     Defines class RealDataItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_GUI_COREGUI_MODELS_REALDATAITEM_H
#define BORNAGAIN_GUI_COREGUI_MODELS_REALDATAITEM_H

#include "GUI/coregui/DataLoaders/AbstractDataLoader.h"
#include "GUI/coregui/Models/SessionItem.h"
#include <QPointer>

class DataItem;
class InstrumentItem;
class InstrumentModel;
class IntensityDataItem;
class SpecularDataItem;
class MaskContainerItem;
template <class T> class OutputData;
class ImportDataInfo;
class RealDataModel;
class AbstractDataLoader;

//! The RealDataItem class represents intensity data imported from file and intended for fitting.

class BA_CORE_API_ RealDataItem : public SessionItem {

    friend class TestView;

public:
    static const QString P_INSTRUMENT_ID;

private:
    static const QString T_INTENSITY_DATA;
    static const QString P_INSTRUMENT_NAME;
    static const QString T_NATIVE_DATA;
    static const QString P_NATIVE_DATA_UNITS;

public:
    RealDataItem();

    void initAsSpecularItem();
    void initAsIntensityItem();

    //! The name which is presented to the user
    QString name() const;
    void setName(const QString& name);

    IntensityDataItem* intensityDataItem();
    const IntensityDataItem* intensityDataItem() const;

    SpecularDataItem* specularDataItem();
    const SpecularDataItem* specularDataItem() const;

    DataItem* dataItem();
    const DataItem* dataItem() const;

    DataItem* nativeData();
    const DataItem* nativeData() const;
    void initNativeData();
    QString nativeDataUnits() const;
    void setNativeDataUnits(const QString& units);
    void removeNativeData();
    bool hasNativeData() const;
    const OutputData<double>* nativeOutputData() const;
    void setNativeOutputData(OutputData<double>* data);

    void setOutputData(OutputData<double>* data);
    void setImportData(ImportDataInfo data);
    bool holdsDimensionalData() const;

    void updateToInstrument(const InstrumentItem* instrument);
    void updateToInstrument(const QString& id);
    QString instrumentId() const;
    void setInstrumentId(const QString& id);
    void clearInstrumentId();
    InstrumentItem* linkedInstrument() const;

    //! Returns the shape of underlying data item
    std::vector<int> shape() const;

    bool isIntensityData() const;
    bool isSpecularData() const;

    //! Returns mask container item
    MaskContainerItem* maskContainerItem();

    //! The name from where the native data was originally imported
    void setNativeFileName(const QString& filename);
    QString nativeFileName() const;

    virtual void writeNonSessionItemData(QXmlStreamWriter* writer) const override;
    virtual void readNonSessionItemData(QXmlStreamReader* reader) override;

    //! Takes ownership of loader
    void setDataLoader(AbstractDataLoader* loader);
    AbstractDataLoader* dataLoader() const;

private:
    void initDataItem(size_t data_rank, const QString& tag);
    void updateNonXMLDataFileNames();

    RealDataModel* realDataModel() const;
    InstrumentModel* instrumentModel() const;

    QByteArray m_importSettings;
    QString m_nativeFileName;

    std::unique_ptr<AbstractDataLoader> m_dataLoader;
};

#endif // BORNAGAIN_GUI_COREGUI_MODELS_REALDATAITEM_H
