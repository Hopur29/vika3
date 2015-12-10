#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "services/scientistservice.h"
#include "addnewscientistdialog.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addScientist_clicked();

private:
    Ui::MainWindow *ui;
    void addNewScientist();

};

#endif // MAINWINDOW_H
