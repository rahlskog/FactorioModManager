#ifndef MOD_H
#define MOD_H
#include <QString>
#include <QStringList>
#include <QJsonObject>

class Mod
{
public:
    explicit Mod(QJsonObject obj);
    QString name() const;
    QString title() const;
    bool enabled() const;
    void setEnabled(bool enabled);
    QStringList dependens() const;

    QJsonObject save() const;

private:
    QString _name;
    bool _enabled;
    QJsonObject _modInfo;
};

#endif // MOD_H
