#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
#include "models/scientist.h"
#include "services/scientistservice.h"
#include "addnewscientistdialog.h"
#include "adnewcomputerdialog.h"
#include <QMainWindow>
#include <QTableWidget>

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

    void on_addComputer_clicked();

    void on_tab_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
    void addNewScientist();
    void displayScientists();
    void displayScientists(std::vector<Scientist> vec);
    ScientistService sciServ;
    std::vector<Scientist> currentlyDisplayedScientist;
};

#endif // MAINWINDOW_H
