//  ************************************************************************************************
//
//  BornAgain: simulate and fit reflection and scattering
//
//! @file      GUI/coregui/Models/IntensityDataItem.cpp
//! @brief     Implements class IntensityDataItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "GUI/coregui/Models/IntensityDataItem.h"
#include "GUI/coregui/Models/AxesItems.h"
#include "GUI/coregui/Models/JobItemUtils.h"
#include "GUI/coregui/Models/MaskItems.h"
#include "GUI/coregui/Models/ProjectionItems.h"
#include "GUI/coregui/Views/ImportDataWidgets/ImportDataUtils.h"
#include "GUI/coregui/Views/MaskWidgets/MaskUnitsConverter.h"
#include "GUI/coregui/utils/GUIHelpers.h"

namespace {
ComboProperty gradientCombo()
{
    ComboProperty result;
    result << "Grayscale"
           << "Hot"
           << "Cold"
           << "Night"
           << "Candy"
           << "Geography"
           << "Ion"
           << "Thermal"
           << "Polar"
           << "Spectrum"
           << "Jet"
           << "Hues";
    result.setValue("Jet");
    return result;
}
} // namespace

const QString x_axis_default_name = "X [nbins]";
const QString y_axis_default_name = "Y [nbins]";

const QString IntensityDataItem::P_TITLE = "Title";
const QString IntensityDataItem::P_PROJECTIONS_FLAG = "Projections";
const QString IntensityDataItem::P_IS_INTERPOLATED = "Interpolation";
const QString IntensityDataItem::P_GRADIENT = "Gradient";
const QString IntensityDataItem::P_XAXIS = "x-axis";
const QString IntensityDataItem::P_YAXIS = "y-axis";
const QString IntensityDataItem::P_ZAXIS = "color-axis";
const QString IntensityDataItem::T_MASKS = "Mask tag";
const QString IntensityDataItem::T_PROJECTIONS = "Projection tag";

IntensityDataItem::IntensityDataItem() : DataItem("IntensityData")
{
    addProperty(P_TITLE, QString())->setVisible(false);

    addProperty(P_PROJECTIONS_FLAG, false)->setVisible(false);
    addProperty(P_IS_INTERPOLATED, true);
    addProperty(P_GRADIENT, gradientCombo().variant());

    auto basicAxis = addProperty<BasicAxisItem>(P_XAXIS);
    basicAxis->getItem(BasicAxisItem::P_NBINS)->setVisible(false);

    basicAxis = addProperty<BasicAxisItem>(P_YAXIS);
    basicAxis->getItem(BasicAxisItem::P_NBINS)->setVisible(false);

    auto amplitudeAxis = addProperty<AmplitudeAxisItem>(P_ZAXIS);
    amplitudeAxis->getItem(BasicAxisItem::P_NBINS)->setVisible(false);

    setXaxisTitle(x_axis_default_name);
    setYaxisTitle(y_axis_default_name);

    registerTag(T_MASKS, 0, -1, QStringList() << "MaskContainer");
    setDefaultTag(T_MASKS);

    registerTag(T_PROJECTIONS, 0, -1, QStringList() << "ProjectionContainer");
}

void IntensityDataItem::setOutputData(OutputData<double>* data)
{
    ASSERT(data && "Assertion failed in IntensityDataItem::setOutputData: nullptr data passed");
    if (data->rank() != 2)
        throw GUIHelpers::Error(
            "Error in IntensityDataItem::setOutputData: cannot handle non-2D data");
    DataItem::setOutputData(data);

    updateAxesZoomLevel();
    updateAxesLabels();
    updateDataRange();

    emitDataChanged();
}

int IntensityDataItem::getNbinsX() const
{
    return xAxisItem()->binCount();
}

int IntensityDataItem::getNbinsY() const
{
    return yAxisItem()->binCount();
}

double IntensityDataItem::getLowerX() const
{
    return xAxisItem()->lowerBound();
}

double IntensityDataItem::getUpperX() const
{
    return xAxisItem()->upperBound();
}

double IntensityDataItem::getXmin() const
{
    const double defaultXmin(0.0);
    return m_data ? m_data->axis(0).lowerBound() : defaultXmin;
}

double IntensityDataItem::getXmax() const
{
    const double defaultXmax(1.0);
    return m_data ? m_data->axis(0).upperBound() : defaultXmax;
}

double IntensityDataItem::getLowerY() const
{
    return yAxisItem()->lowerBound();
}

double IntensityDataItem::getUpperY() const
{
    return yAxisItem()->upperBound();
}

double IntensityDataItem::getYmin() const
{
    const double defaultYmin(0.0);
    return m_data ? m_data->axis(1).lowerBound() : defaultYmin;
}

double IntensityDataItem::getYmax() const
{
    const double defaultYmax(1.0);
    return m_data ? m_data->axis(1).upperBound() : defaultYmax;
}

double IntensityDataItem::getLowerZ() const
{
    return zAxisItem()->lowerBound();
}

double IntensityDataItem::getUpperZ() const
{
    return zAxisItem()->upperBound();
}

QString IntensityDataItem::getGradient() const
{
    ComboProperty combo_property = getItemValue(P_GRADIENT).value<ComboProperty>();
    return combo_property.getValue();
}

bool IntensityDataItem::isLogz() const
{
    return zAxisItem()->isLogScale();
}

bool IntensityDataItem::isInterpolated() const
{
    return getItemValue(P_IS_INTERPOLATED).toBool();
}

QString IntensityDataItem::getXaxisTitle() const
{
    return xAxisItem()->title();
}

QString IntensityDataItem::getYaxisTitle() const
{
    return yAxisItem()->title();
}

bool IntensityDataItem::isZAxisLocked() const
{
    return getItem(P_ZAXIS)->getItemValue(AmplitudeAxisItem::P_LOCK_MIN_MAX).toBool();
}

void IntensityDataItem::setZAxisLocked(bool state)
{
    return getItem(P_ZAXIS)->setItemValue(AmplitudeAxisItem::P_LOCK_MIN_MAX, state);
}

void IntensityDataItem::setXaxisTitle(const QString& title)
{
    xAxisItem()->setTitle(title);
}

void IntensityDataItem::setYaxisTitle(const QString& title)
{
    yAxisItem()->setTitle(title);
}

//! set zoom range of x,y axes to axes of input data
void IntensityDataItem::setAxesRangeToData()
{
    setLowerX(getXmin());
    setUpperX(getXmax());
    setLowerY(getYmin());
    setUpperY(getYmax());
}

void IntensityDataItem::updateAxesUnits(const InstrumentItem* instrument)
{
    MaskUnitsConverter converter;
    converter.convertToNbins(this);

    JobItemUtils::updateDataAxes(this, instrument);

    converter.convertFromNbins(this);
}

std::vector<int> IntensityDataItem::shape() const
{
    return {getNbinsX(), getNbinsY()};
}

void IntensityDataItem::reset(ImportDataInfo data)
{
    ASSERT(data.unitsLabel() == "nbins");
    ComboProperty combo = ComboProperty() << data.unitsLabel();
    setItemValue(IntensityDataItem::P_AXES_UNITS, combo.variant());
    getItem(IntensityDataItem::P_AXES_UNITS)->setVisible(true);

    setXaxisTitle(data.axisLabel(0));
    setYaxisTitle(data.axisLabel(1));
    MaskUnitsConverter converter;
    converter.convertToNbins(this);
    setOutputData(std::move(data).intensityData().release());
    setAxesRangeToData();
    converter.convertFromNbins(this);
}

void IntensityDataItem::setLowerX(double value)
{
    xAxisItem()->setLowerBound(value);
}

void IntensityDataItem::setUpperX(double value)
{
    xAxisItem()->setUpperBound(value);
}

void IntensityDataItem::setLowerY(double value)
{
    yAxisItem()->setLowerBound(value);
}

void IntensityDataItem::setUpperY(double value)
{
    yAxisItem()->setUpperBound(value);
}

void IntensityDataItem::setLowerAndUpperZ(double zmin, double zmax)
{
    if (getLowerZ() != zmin)
        setLowerZ(zmin);

    if (getUpperZ() != zmax)
        setUpperZ(zmax);
}

void IntensityDataItem::setLowerZ(double zmin)
{
    zAxisItem()->setLowerBound(zmin);
}

void IntensityDataItem::setUpperZ(double zmax)
{
    zAxisItem()->setUpperBound(zmax);
}

void IntensityDataItem::setLogz(bool logz)
{
    zAxisItem()->setLogScale(logz);
}

void IntensityDataItem::setInterpolated(bool interp)
{
    setItemValue(P_IS_INTERPOLATED, interp);
}

//! Sets zoom range of X,Y axes, if it was not yet defined.

void IntensityDataItem::updateAxesZoomLevel()
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
    xAxisItem()->setBinCount(nx);
    const int ny = static_cast<int>(m_data->axis(1).size());
    yAxisItem()->setBinCount(ny);
}

//! Init axes labels, if it was not done already.

void IntensityDataItem::updateAxesLabels()
{
    if (getXaxisTitle().isEmpty())
        setXaxisTitle(QString::fromStdString(m_data->axis(0).getName()));

    if (getYaxisTitle().isEmpty())
        setYaxisTitle(QString::fromStdString(m_data->axis(1).getName()));
}

//! Sets min,max values for z-axis, if axes is not locked, and ranges are not yet set.

void IntensityDataItem::updateDataRange()
{
    if (isZAxisLocked())
        return;

    computeDataRange();
}

void IntensityDataItem::computeDataRange()
{
    QPair<double, double> minmax = dataRange();
    setLowerAndUpperZ(minmax.first, minmax.second);
}

//! Init zmin, zmax to match the intensity values range.
QPair<double, double> IntensityDataItem::dataRange() const
{
    const OutputData<double>* data = getOutputData();
    double min(*std::min_element(data->begin(), data->end()));
    double max(*std::max_element(data->begin(), data->end()));
    if (isLogz()) {
        if (max > 10000) {
            min = 1.0;
            max = max * 1.1;
        } else {
            min = max / 10000;
            max = max * 1.1;
        }
    } else {
        max = max * 1.1;
    }

    return QPair<double, double>(min, max);
}

const BasicAxisItem* IntensityDataItem::xAxisItem() const
{
    return item<BasicAxisItem>(P_XAXIS);
}

BasicAxisItem* IntensityDataItem::xAxisItem()
{
    return item<BasicAxisItem>(P_XAXIS);
}

const BasicAxisItem* IntensityDataItem::yAxisItem() const
{
    return item<BasicAxisItem>(P_YAXIS);
}

BasicAxisItem* IntensityDataItem::yAxisItem()
{
    return item<BasicAxisItem>(P_YAXIS);
}

const AmplitudeAxisItem* IntensityDataItem::zAxisItem() const
{
    return item<AmplitudeAxisItem>(P_ZAXIS);
}

AmplitudeAxisItem* IntensityDataItem::zAxisItem()
{
    return item<AmplitudeAxisItem>(P_ZAXIS);
}

//! Set axes viewport to original data.

void IntensityDataItem::resetView()
{
    if (!m_data)
        return;

    setAxesRangeToData();
    if (!isZAxisLocked())
        computeDataRange();
}

MaskContainerItem* IntensityDataItem::maskContainerItem()
{
    return dynamic_cast<MaskContainerItem*>(getItem(IntensityDataItem::T_MASKS));
}

ProjectionContainerItem* IntensityDataItem::projectionContainerItem()
{
    return dynamic_cast<ProjectionContainerItem*>(getItem(IntensityDataItem::T_PROJECTIONS));
}
