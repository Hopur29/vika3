#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addnewscientistdialog.h"
#include "utilities/utils.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayScientists();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addScientist_clicked()
{
    AddNewScientistDialog newSci;
    newSci.setModal(true);
    newSci.exec();
}

void MainWindow::displayScientists()
{
    std::vector<Scientist> vec = sciServ.getAllScientists("name", true);
    displayScientists(vec);
}


void MainWindow::displayScientists(std::vector<Scientist> vec)
{
    ui->Scientist_table->clearContents();
    ui->Scientist_table->setRowCount(vec.size());

    for(unsigned int i = 0; i < vec.size(); i++)
    {
        Scientist currentScientist = vec.at(i);
/*
        QString name = QString::fromStdString(currentScientist.getName());
        sexType sex = currentScientist.getSex();
  */
        ui->Scientist_table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(currentScientist.getName())));
        sexType gender = currentScientist.getSex();
        ui->Scientist_table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(utils::sexToString(gender))));
        ui->Scientist_table->setItem(i, 2, new QTableWidgetItem(QString::number(currentScientist.getYearBorn())));
        ui->Scientist_table->setItem(i, 2, new QTableWidgetItem(QString::number(currentScientist.getYearDied())));
    }
    currentlyDisplayedScientist = vec;
}

void MainWindow::on_addComputer_clicked()
{
    adnewcomputerdialog newCom;
    newCom.setModal(true);
    newCom.exec();
}

void MainWindow::on_tab_tabBarClicked(int index)
{
    if(index == 0)
    {
        displayScientists();
    }
    else if(index == 1)
    {
        //displayComputers();
    }
    else if(index == 2)
    {
        //displayRelations();
    }

}
