#include "MaterialModel.h"


MaterialModel::MaterialModel(QObject *parent)
    : QAbstractTableModel(parent)
    , m_name("DefaultName")
{

}


MaterialModel::~MaterialModel()
{
    qDeleteAll(m_materials);
}


int MaterialModel::rowCount(const QModelIndex & /*parent*/) const
{
    return m_materials.size();
}


int MaterialModel::columnCount(const QModelIndex & /*parent*/) const
{
    return NumberOfColumns;
}


QVariant MaterialModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row <0 && row >= m_materials.size() ) return QVariant();

    if (role == Qt::DisplayRole)
    {
        switch(index.column()) {
        case MaterialName:
            return m_materials.at(row)->getName();
        case MaterialType:
            return m_materials.at(row)->getTypeName();
        default:
            return QString("Row%1, Column%2")
            .arg(index.row() + 1)
            .arg(index.column() +1);
        }
    }


    return QVariant();

}


QVariant MaterialModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case MaterialName:
                return QString("Name");
            case MaterialType:
                return QString("Type");
            default:
                return QString();
            }
        } else if (orientation == Qt::Vertical) {
            return QString("%1").arg(section);
        }
    }
    return QVariant();
}


void MaterialModel::addMaterial(const QString &name, MaterialItem::MaterialType type)
{
    int position = m_materials.size();
    beginInsertRows(QModelIndex(), position, position);
    MaterialItem *material = new MaterialItem(name, type);
    m_materials.append(material);
    endInsertRows();

    //connect(item, SIGNAL(modified(JobItem*)), this, SLOT(onJobItemIsModified(JobItem*)));
}






