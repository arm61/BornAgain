//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      GUI/coregui/Models/SpecularDataItem.cpp
//! @brief     Implements class SpecularDataItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "GUI/coregui/Models/SpecularDataItem.h"
#include "GUI/coregui/Models/AxesItems.h"
#include "GUI/coregui/Models/JobItemUtils.h"
#include "GUI/coregui/Views/ImportDataWidgets/ImportDataUtils.h"
#include "GUI/coregui/utils/GUIHelpers.h"

const QString SpecularDataItem::P_TITLE = "Title";
const QString SpecularDataItem::P_XAXIS = "x-axis";
const QString SpecularDataItem::P_YAXIS = "y-axis";

SpecularDataItem::SpecularDataItem() : DataItem("SpecularData")
{
    addProperty(P_TITLE, QString())->setVisible(false);

    SessionItem* item = addGroupProperty(P_XAXIS, "BasicAxis");
    item->getItem(BasicAxisItem::P_NBINS)->setVisible(false);

    item = addGroupProperty(P_YAXIS, "AmplitudeAxis");
    item->getItem(BasicAxisItem::P_NBINS)->setVisible(false);
    item->getItem(BasicAxisItem::P_TITLE)->setVisible(true);

    item = item->getItem(AmplitudeAxisItem::P_IS_VISIBLE);
    item->setValue(true);
    item->setVisible(false);

    setXaxisTitle(SpecularDataAxesNames::x_axis_default_name);
    setYaxisTitle(SpecularDataAxesNames::y_axis_default_name);
}

void SpecularDataItem::setOutputData(OutputData<double>* data)
{
    ASSERT(data && "Assertion failed in SpecularDataItem::setOutputData: nullptr data passed");
    if (data->rank() != 1)
        throw GUIHelpers::Error(
            "Error in SpecularDataItem::setOutputData: cannot handle non-1D data");
    DataItem::setOutputData(data);

    updateAxesZoomLevel();

    emitDataChanged();
}

int SpecularDataItem::getNbins() const
{
    return xAxisItem()->binCount();
}

double SpecularDataItem::getLowerX() const
{
    return xAxisItem()->lowerBound();
}

double SpecularDataItem::getUpperX() const
{
    return xAxisItem()->upperBound();
}

double SpecularDataItem::getXmin() const
{
    const double defaultXmin(0.0);
    return m_data ? m_data->axis(0).lowerBound() : defaultXmin;
}

double SpecularDataItem::getXmax() const
{
    const double defaultXmax(1.0);
    return m_data ? m_data->axis(0).upperBound() : defaultXmax;
}

double SpecularDataItem::getLowerY() const
{
    return yAxisItem()->lowerBound();
}

double SpecularDataItem::getUpperY() const
{
    return yAxisItem()->upperBound();
}

double SpecularDataItem::getYmin() const
{
    return dataRange().first;
}

double SpecularDataItem::getYmax() const
{
    return dataRange().second;
}

bool SpecularDataItem::isLog() const
{
    return yAxisItem()->isLogScale();
}

QString SpecularDataItem::getXaxisTitle() const
{
    return xAxisItem()->title();
}

QString SpecularDataItem::getYaxisTitle() const
{
    return yAxisItem()->title();
}

void SpecularDataItem::setXaxisTitle(const QString& title)
{
    xAxisItem()->setTitle(title);
}

void SpecularDataItem::setYaxisTitle(const QString& title)
{
    yAxisItem()->setTitle(title);
}

//! set zoom range of x,y axes to axes of input data
void SpecularDataItem::setAxesRangeToData()
{
    setLowerX(getXmin());
    setUpperX(getXmax());
    setLowerY(getYmin());
    setUpperY(getYmax());
}

void SpecularDataItem::updateAxesUnits(const InstrumentItem* instrument)
{
    JobItemUtils::updateDataAxes(this, instrument);
}

std::vector<int> SpecularDataItem::shape() const
{
    return {getNbins()};
}

void SpecularDataItem::reset(ImportDataInfo data)
{
    ComboProperty combo = ComboProperty() << data.unitsLabel();
    setItemValue(SpecularDataItem::P_AXES_UNITS, combo.variant());
    getItem(SpecularDataItem::P_AXES_UNITS)->setVisible(true);

    setXaxisTitle(data.axisLabel(0));
    setYaxisTitle(data.axisLabel(1));
    setOutputData(std::move(data).intensityData().release());
    setAxesRangeToData();
}

void SpecularDataItem::setLowerX(double value)
{
    xAxisItem()->setLowerBound(value);
}

void SpecularDataItem::setUpperX(double value)
{
    xAxisItem()->setUpperBound(value);
}

void SpecularDataItem::setLowerY(double value)
{
    yAxisItem()->setLowerBound(value);
}

void SpecularDataItem::setUpperY(double value)
{
    yAxisItem()->setUpperBound(value);
}

void SpecularDataItem::setLog(bool log_flag)
{
    yAxisItem()->setLogScale(log_flag);
}

//! Sets zoom range of X,Y axes, if it was not yet defined.

void SpecularDataItem::updateAxesZoomLevel()
{
    // set zoom range of x-axis to min, max values if it was not set already
    if (getUpperX() < getLowerX()) {
        setLowerX(getXmin());
        setUpperX(getXmax());
    }

    // set zoom range of y-axis to min, max values if it was not set already
    if (getUpperY() < getLowerY()) {
        setLowerY(getYmin());
        setUpperY(getYmax());
    }

    const int nx = static_cast<int>(m_data->axis(0).size());
    xAxisItem()->setItemValue(BasicAxisItem::P_NBINS, nx);
}

//! Init ymin, ymax to match the intensity values range.
QPair<double, double> SpecularDataItem::dataRange() const
{
    const double default_min = 0.0;
    const double default_max = 1.0;
    const OutputData<double>* data = getOutputData();
    if (!data)
        return QPair<double, double>(default_min, default_max);
    double min(*std::min_element(data->begin(), data->end()));
    double max(*std::max_element(data->begin(), data->end()));

    min /= 2.0;
    min = std::numeric_limits<double>::epsilon() < min ? min : default_min;
    max *= 2.0;
    max = max > min ? max : default_max;

    return QPair<double, double>(min, max);
}

const BasicAxisItem* SpecularDataItem::xAxisItem() const
{
    return item<BasicAxisItem>(P_XAXIS);
}

BasicAxisItem* SpecularDataItem::xAxisItem()
{
    return const_cast<BasicAxisItem*>(static_cast<const SpecularDataItem*>(this)->xAxisItem());
}

const AmplitudeAxisItem* SpecularDataItem::yAxisItem() const
{
    return item<AmplitudeAxisItem>(P_YAXIS);
}

AmplitudeAxisItem* SpecularDataItem::yAxisItem()
{
    return const_cast<AmplitudeAxisItem*>(static_cast<const SpecularDataItem*>(this)->yAxisItem());
}

//! Set axes viewport to original data.

void SpecularDataItem::resetView()
{
    setAxesRangeToData();
}
