#ifndef MODLIST_H
#define MODLIST_H
#include "mod.h"

class ModList
{
public:
    ModList();

    int size() const { return mods.size(); }
    const Mod & at(int i) const { return mods.at(i); }
    Mod & operator[](int i) { return mods[i]; }
    const Mod & operator[](int i) const { return mods[i]; }

    static ModList Load(QString filePath);
    void Save(QString filePath);
private:
    QList<Mod> mods;
};

#endif // MODLIST_H
