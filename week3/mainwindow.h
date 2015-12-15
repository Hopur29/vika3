#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
#include "models/scientist.h"
#include "models/relation.h"
#include "services/scientistservice.h"
#include "addnewscientistdialog.h"
#include "adnewcomputerdialog.h"
#include "addnewrelationdialog.h"
#include "editscientistdialog.h"
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

    void on_Scientist_Edit_clicked();

    void on_SearchScientist_textChanged(const QString &arg1);

    void on_removeScientist_clicked();



    //void on_pushButton_clicked();

    void on_Computer_edit_clicked();

    void on_removeComputer_clicked();

    //void on_SearchComputer_textChanged(const QString &arg1);

    void on_SearchComputer_textChanged(const QString &arg1);

    void on_addRelation_clicked();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_Search_relation_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void displayScientists();
    void displayScientists(std::vector<Scientist> vec);
    void displayComputers();
    void displayComputers(std::vector<Computer> vec);
    void displayRelations();
    void displayRelations(std::vector<Relation> vec);
    ScientistService sciServ;
    ComputerService comServ;
    LinkService linkServ;
    std::vector<Relation> currentlyDisplayedRelation;
    std::vector<Scientist> currentlyDisplayedScientist;
    std::vector<Computer> currentlyDisplayedComputer;
};

#endif // MAINWINDOW_H
