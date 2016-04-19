// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/utils/GUIHelpers.cpp
//! @brief     Implements GUIHelpers functions
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "GUIHelpers.h"
#include "BAVersion.h"
#include <QApplication>
#include <QFile>
#include <QRegExp>
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>

namespace GUIHelpers {

namespace {
QMap<QString, QString> initializeCharacterMap()
{
    QMap<QString, QString> result;
    result["\\"]= QString("_backslash_");
    result["/"] = QString("_slash_");
    result["\""] = QString("_quote_");
    result["<"] = QString("_lessthan_");
    result[">"] = QString("_greaterthan_");
    result["|"] = QString("_pipe_");
    result["?"] = QString("_questionmark_");
    return result;
}

const QMap<QString, QString> invalidCharacterMap = initializeCharacterMap();

}

void information(QWidget *parent, const QString &title, const QString &text, const QString &detailedText)
{
    QScopedPointer<QMessageBox> messageBox(new QMessageBox(parent));
    if (parent)
        messageBox->setWindowModality(Qt::WindowModal);
    messageBox->setWindowTitle(QString("%1 - %2")
            .arg(QApplication::applicationName()).arg(title));
    messageBox->setText(text);
    if (!detailedText.isEmpty())
        messageBox->setInformativeText(detailedText);
    messageBox->setIcon(QMessageBox::Information);
    messageBox->addButton(QMessageBox::Ok);
    messageBox->exec();
}


void warning(QWidget *parent, const QString &title, const QString &text, const QString &detailedText)
{
    QScopedPointer<QMessageBox> messageBox(new QMessageBox(parent));
    if (parent)
        messageBox->setWindowModality(Qt::WindowModal);
    messageBox->setWindowTitle(QString("%1 - %2")
            .arg(QApplication::applicationName()).arg(title));
    messageBox->setText(text);
    if (!detailedText.isEmpty())
        messageBox->setInformativeText(detailedText);
    messageBox->setIcon(QMessageBox::Warning);
    messageBox->addButton(QMessageBox::Ok);
    messageBox->exec();
}


bool question(QWidget *parent, const QString &title, const QString &text, const QString &detailedText, const QString &yesText, const QString &noText)
{
    QScopedPointer<QMessageBox> messageBox(new QMessageBox(parent));
    if (parent)
        messageBox->setWindowModality(Qt::WindowModal);
    messageBox->setWindowTitle(QString("%1 - %2")
            .arg(QApplication::applicationName()).arg(title));
    messageBox->setText(text);
    if (!detailedText.isEmpty())
        messageBox->setInformativeText(detailedText);
    messageBox->setIcon(QMessageBox::Question);
    QAbstractButton *yesButton = messageBox->addButton(yesText,
            QMessageBox::AcceptRole);
    messageBox->addButton(noText, QMessageBox::RejectRole);
    messageBox->setDefaultButton(
            qobject_cast<QPushButton*>(yesButton));
    messageBox->exec();
    return messageBox->clickedButton() == yesButton;
}


bool okToDelete(QWidget *parent, const QString &title, const QString &text, const QString &detailedText)
{
    QScopedPointer<QMessageBox> messageBox(new QMessageBox(parent));
    if (parent)
        messageBox->setWindowModality(Qt::WindowModal);
    messageBox->setIcon(QMessageBox::Question);
    messageBox->setWindowTitle(QString("%1 - %2")
            .arg(QApplication::applicationName()).arg(title));
    messageBox->setText(text);
    if (!detailedText.isEmpty())
        messageBox->setInformativeText(detailedText);
    QAbstractButton *deleteButton = messageBox->addButton(
            QObject::tr("&Delete"), QMessageBox::AcceptRole);
    messageBox->addButton(QObject::tr("Do &Not Delete"),
                          QMessageBox::RejectRole);
    messageBox->setDefaultButton(
            qobject_cast<QPushButton*>(deleteButton));
    messageBox->exec();
    return messageBox->clickedButton() == deleteButton;
}

//! returns type of variant
int getVariantType(const QVariant &variant)
{
    int result = variant.type();
    if (result == QVariant::UserType) {
        result = variant.userType();
    }
    return result;
}

QString getBornAgainVersionString()
{
    return QString::fromStdString(BornAgain::GetVersionNumber());
}

//! Returns valid file name to be saved on disk. This name is constructed from proposed_name
//! by replacing all special characters with text representation
//! \ backslash
//! / slash
//! " quote
//! < lessthan
//! > greaterthan
//! | pipe
//! ? questionmark
QString getValidFileName(const QString &proposed_name)
{
    QString result = proposed_name;
    for(QMap<QString, QString>::const_iterator it=invalidCharacterMap.begin(); it!=invalidCharacterMap.end(); ++it) {
        result.replace(it.key(), it.value());
    }
    return result;
}

//! parses version string into 3 numbers, returns true in the case of success
bool parseVersion(const QString &version, int &major_num, int &minor_num, int &patch_num)
{
    major_num = minor_num = patch_num = 0;
    bool success(true);
    QStringList nums = version.split(QStringLiteral("."));
    if(nums.size() != 3) return false;

    bool ok(false);
    major_num = nums.at(0).toInt(&ok); success &= ok;
    minor_num = nums.at(1).toInt(&ok); success &= ok;
    patch_num = nums.at(2).toInt(&ok); success &= ok;

    return success;
}


//! returns true if current BornAgain version match minimal required version
bool isVersionMatchMinimal(const QString &version, const QString &minimal_version)
{
    int ba_major(0), ba_minor(0), ba_patch(0);
    if(!parseVersion(version, ba_major, ba_minor, ba_patch))
        return false;

    int minv_major(0), minv_minor(0), minv_patch(0);
    if(!parseVersion(minimal_version, minv_major, minv_minor, minv_patch))
        return false;

    int ba = ba_major*10000 + ba_minor*100 + ba_patch;
    int minv = minv_major*10000 + minv_minor*100 + minv_patch;
    return ba >= minv;
}

} // namespace GUIHelpers
