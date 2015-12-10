#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addnewscientistdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
