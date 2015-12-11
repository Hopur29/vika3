#include "adnewcomputerdialog.h"
#include "ui_adnewcomputerdialog.h"
#include "models/computer.h"
#include "utilities/utils.h"
#include <QMessageBox>

adnewcomputerdialog::adnewcomputerdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adnewcomputerdialog)
{
    ui->setupUi(this);
}

adnewcomputerdialog::~adnewcomputerdialog()
{
    delete ui;
}

void adnewcomputerdialog::on_addOK_accepted()
{
    QString name = ui->Set_name->text();
    int type = ui->Set_type->currentIndex();
    QString yearBuilt = ui->Set_yearBuilt->text();

    if(name.isEmpty())
    {
        //error handling
    }

    if(yearBuilt.isEmpty())
    {
        if(comServ.addComputer(Computer(name.toStdString(), utils::intToComputerType(type))))
        {
            ui->Set_name->setText("");
        }
        else
        {
            QMessageBox::information(this,tr("Error"), tr("We were not able to add this Computer, sorry"));
        }
    }
    else
    {
        if(comServ.addComputer(Computer(name.toStdString(), utils::intToComputerType(type) ,yearBuilt.toInt() )))
        {
            ui->Set_name->setText("");
        }
        else
        {
            QMessageBox::information(this,tr("Error"), tr("We were not able to add this Computer, sorry"));
        }
    }

}


