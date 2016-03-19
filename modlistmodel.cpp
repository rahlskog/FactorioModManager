#include "modlistmodel.h"

ModListModel::ModListModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

void ModListModel::setModList(ModList modList)
{
    _modList = modList;
}

int ModListModel::rowCount(const QModelIndex &parent) const
{
    return _modList.size();
}

int ModListModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant ModListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        if (section == 0)
        {
            return tr("Enabled");
        }
        if (section == 1)
        {
            return tr("Mod");
        }
        if (section == 2)
        {
            return tr("Dependencies");
        }
    }
    return QVariant();
}

Qt::ItemFlags ModListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }

    if (index.column() == 0)
    {
        return QAbstractItemModel::flags(index) | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
    }
    return QAbstractItemModel::flags(index);
}

QVariant ModListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole)
    {
        if (index.column() == 0)
        {
            return _modList.at(index.row()).enabled();
        }
        else if (index.column() == 1)
        {
            return _modList.at(index.row()).name();
        }
        else if (index.column() == 2)
        {
            return _modList.at(index.row()).dependens();
        }
    }
    if (role == Qt::ToolTipRole)
    {
        if (index.column() == 1)
        {
            return _modList.at(index.row()).title();
        }
    }

    if (role == Qt::CheckStateRole)
    {
        if (index.column() == 0)
        {
            return _modList.at(index.row()).enabled() ? Qt::Checked : Qt::Unchecked;
        }
    }

    return QVariant();
}

bool ModListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
    {
        return false;
    }
    if (role == Qt::CheckStateRole)
    {
        _modList[index.row()].setEnabled((Qt::CheckState)value.toInt() == Qt::Checked);
        emit dataChanged(index, index);
        return true;
    }
    return false;
}
