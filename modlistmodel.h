#ifndef MODLISTMODEL_H
#define MODLISTMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <modlist.h>

class ModListModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ModListModel(QObject *parent = 0);
    void setModList(ModList modList);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

private:
    ModList _modList;
};

#endif // MODLISTMODEL_H
