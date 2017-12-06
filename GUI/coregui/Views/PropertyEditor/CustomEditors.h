// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/PropertyEditor/CustomEditors.h
//! @brief     Defines CustomEditors classes
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef CUSTOMEDITORS_H
#define CUSTOMEDITORS_H

#include "WinDllMacros.h"
#include <QWidget>
#include <QVariant>

class QLabel;
class LostFocusFilter;
class QComboBox;

//! Base class for all custom variants editors.

class BA_CORE_API_ CustomEditor : public QWidget
{
    Q_OBJECT
public:
    explicit CustomEditor(QWidget* parent = nullptr) : QWidget(parent) {}

    QVariant editorData() { return m_data; }

public slots:
    void setData(const QVariant& data);

signals:
    //! Signal emit then user changed the data through the editor
    void dataChanged(const QVariant& data);

protected:
    virtual void initEditor();
    void setDataIntern(const QVariant& data);
    QVariant m_data;
};

//! Editor for ExternalProperty variant.

class BA_CORE_API_ ExternalPropertyEditor : public CustomEditor
{
    Q_OBJECT
public:
    explicit ExternalPropertyEditor(QWidget* parent = nullptr);

    void setExternalDialogType(const QString& dialogType);

private slots:
    void buttonClicked();

protected:
    void initEditor();

private:
    QLabel* m_textLabel;
    QLabel* m_pixmapLabel;
    LostFocusFilter* m_focusFilter;
    QString m_extDialogType; //!< Type of the dialog which will be created on button click
};

//! Editor for ComboProperty variant.

class BA_CORE_API_ ComboPropertyEditor : public CustomEditor
{
    Q_OBJECT
public:
    explicit ComboPropertyEditor(QWidget *parent = nullptr);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

protected slots:
    virtual void onIndexChanged(int index);

protected:
    void initEditor();
    virtual QStringList internLabels();
    virtual int internIndex();
    void setConnected(bool isConnected);

    QComboBox* m_box;
    class WheelEventEater* m_wheel_event_filter;
};

//! Editor for ScientificDoubleProperty variant.

class BA_CORE_API_ ScientificDoublePropertyEditor : public CustomEditor
{
    Q_OBJECT
public:
    ScientificDoublePropertyEditor(QWidget *parent = nullptr);

private slots:
    void onEditingFinished();

protected:
    void initEditor();

private:
    class QLineEdit* m_lineEdit;
    class QDoubleValidator* m_validator;
};

//! Editor for boolean.

class QCheckBox;

class BA_CORE_API_ BoolEditor : public CustomEditor
{
    Q_OBJECT
public:
    BoolEditor(QWidget* parent = nullptr);

private slots:
    void onCheckBoxChange(bool value);

protected:
    void initEditor();

private:
    QCheckBox *m_checkBox;
};

#endif  //  CUSTOMEDITORS_H
