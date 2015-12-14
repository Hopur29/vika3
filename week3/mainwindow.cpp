#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addnewscientistdialog.h"
#include "utilities/utils.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    on_tab_tabBarClicked(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addScientist_clicked()
{
    AddNewScientistDialog newSci;
    newSci.setModal(true);
    int result = newSci.exec();

    if(result == 1)
    {
        displayScientists();
    }
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

        ui->Scientist_table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(currentScientist.getName())));
        sexType gender = currentScientist.getSex();
        ui->Scientist_table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(utils::sexToString(gender))));
        ui->Scientist_table->setItem(i, 2, new QTableWidgetItem(QString::number(currentScientist.getYearBorn())));

        if(currentScientist.getYearDied() == 13337)
        {
            ui->Scientist_table->setItem(i, 3, new QTableWidgetItem("Alive"));
        }
        else
        {
            ui->Scientist_table->setItem(i, 3, new QTableWidgetItem(QString::number(currentScientist.getYearDied())));

        }

        ui->Scientist_table->setItem(i, 4, new QTableWidgetItem(QString::number(currentScientist.getId())));
    }
    currentlyDisplayedScientist = vec;
}

void MainWindow::on_addComputer_clicked()
{
    adnewcomputerdialog newCom;
    newCom.setModal(true);
    int result = newCom.exec();

    if(result == 1)
    {
        //displayComputers();
    }
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

void MainWindow::on_Scientist_Edit_clicked()
{
    int currentlySelectedScientistIndex = ui->Scientist_table->currentIndex().row();
    Scientist currentlySelectedScientist = currentlyDisplayedScientist.at(currentlySelectedScientistIndex);

    EditScientistDialog edit;
    edit.setInstance(currentlySelectedScientist);
    edit.setModal(true);
    int result = edit.exec();

    if(result == 1)
    {
        displayScientists();
    }
}

void MainWindow::on_SearchScientist_textChanged(const QString &arg1)
{
    std::string userInput = arg1.toStdString();

    std::vector<Scientist> sci = sciServ.searchForScientists(userInput);
    displayScientists(sci);
}

void MainWindow::on_removeScientist_clicked()
{
    int currentlySelectedScientistIndex = ui->Scientist_table->currentIndex().row();

    Scientist sci = currentlyDisplayedScientist.at(currentlySelectedScientistIndex);

    if(sciServ.removeScientist(sci))
    {
        displayScientists();
    }
    else
    {
        QMessageBox::information(this,tr("Error"), tr("We were not able to remove this scientist, sorry"));
    }
}
