#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modlist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void applyClicked();
    void saveAsClicked();


private:
    Ui::MainWindow *ui;
    ModList modlist;
};

#endif // MAINWINDOW_H
