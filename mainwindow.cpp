#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include "modlist.h"
#include "modlistmodel.h"
#include "moddependenciesdelegate.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setItemDelegateForColumn(2, new ModDependenciesDelegate);

    modlist = ModList::Load(QDir::homePath()+"/.factorio/mods/mod-list.json");
    ui->presetBox->addItem(tr("unsaved preset"));

    auto modListModel = new ModListModel(this);
    modListModel->setModList(modlist);

    ui->tableView->setModel(modListModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::applyClicked()
{
    //modlist.Save(QDir::homePath()+"/.factorio/mods/mod-list.json");
}

void MainWindow::saveAsClicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save as"), QDir::homePath(), tr("JSON Document (*.json)"));
    if (!fileName.isEmpty())
    {
        modlist.Save(fileName);
        QFileInfo fi(fileName);
        ui->presetBox->addItem(fi.completeBaseName());
        ui->presetBox->setCurrentText(fi.completeBaseName());
    }
}
