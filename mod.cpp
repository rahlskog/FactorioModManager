#include "mod.h"
#include <QDir>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonArray>
#include <string>
#include <sstream>
#include <fstream>
#include <Poco/Zip/Zip.h>
#include <Poco/Zip/ZipArchive.h>
#include <Poco/Zip/ZipStream.h>
#include <Poco/StreamCopier.h>

using Poco::Zip::ZipArchive;
using Poco::Zip::ZipInputStream;

QJsonObject loadModInfo(QString modname)
{
    QDir modsdir(QDir::homePath()+"/.factorio/mods/");
    QStringList filter(modname+"*");
    QFileInfoList files = modsdir.entryInfoList(filter);
    if (files.count() != 1)
    {
        return QJsonObject();
    }

    std::string filename = files.at(0).absoluteFilePath().toStdString();
    std::string basename = files.at(0).completeBaseName().toStdString();

    if (!QFile::exists(filename.c_str()))
    {
        return QJsonObject();
    }
    std::ifstream zipfile(filename, std::ios::binary);
    ZipArchive arch(zipfile);
    ZipArchive::FileHeaders::const_iterator it = arch.findHeader(basename+"/info.json");
    if (it == arch.headerEnd())
    {
        return QJsonObject();
    }
    ZipInputStream zipin (zipfile, it->second);
    std::ostringstream out(std::ios::binary);
    Poco::StreamCopier::copyStream(zipin, out);

    QByteArray filedata = QByteArray::fromStdString(out.str());
    return QJsonDocument::fromJson(filedata).object();
}

Mod::Mod(QJsonObject object)
{
    _name = object["name"].toString();
    _enabled = object["enabled"].toString() == "true";

    _modInfo = loadModInfo(_name);
}

QString Mod::name() const
{
    return _name;
}

QString Mod::title() const
{
    if (_modInfo.isEmpty())
    {
        return _name;
    }
    return _modInfo["title"].toString();
}

bool Mod::enabled() const
{
    return _enabled;
}

void Mod::setEnabled(bool enabled)
{
    _enabled = enabled;
}

QStringList Mod::dependens() const
{
    if (_modInfo.isEmpty())
    {
        return QStringList("");
    }
    QJsonArray deps = _modInfo["dependencies"].toArray();
    QStringList ret;
    for (int idx = 0; idx < deps.size(); ++idx)
    {
        ret << deps.at(idx).toString();
    }
    return ret;
}

QJsonObject Mod::save() const
{
    QJsonObject o;
    o.insert("name", _name);
    o.insert("enabled", _enabled ? "true":"false");
    return o;
}


