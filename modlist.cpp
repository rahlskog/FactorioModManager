#include "modlist.h"
#include <QByteArray>
#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>

ModList::ModList()
{

}

ModList ModList::Load(QString filePath)
{
    QFile modfile(filePath);
    modfile.open(QIODevice::ReadOnly);
    QByteArray filedata = modfile.readAll();
    QJsonDocument modlist(QJsonDocument::fromJson(filedata));
    QJsonObject object = modlist.object();
    QJsonArray modArray = object["mods"].toArray();

    ModList newModList;
    for (int idx = 0; idx < modArray.size(); ++idx)
    {
        QJsonObject mod = modArray[idx].toObject();
        newModList.mods.append(Mod(mod));
    }
    return newModList;
}

void ModList::Save(QString filePath)
{
    QJsonArray array;
    for (int idx = 0; idx < mods.size(); ++idx)
    {
        array.append(mods.at(idx).save());
    }
    QJsonObject object;
    object.insert("mods", array);
    QJsonDocument doc;
    doc.setObject(object);
    QByteArray filedata = doc.toJson(QJsonDocument::Indented);

    QFile targetFile(filePath);
    targetFile.open(QIODevice::Truncate|QIODevice::WriteOnly);
    targetFile.write(filedata);
}
