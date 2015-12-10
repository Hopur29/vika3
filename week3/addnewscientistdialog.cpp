#include "addnewscientistdialog.h"
#include "ui_addnewscientistdialog.h"
#include "models/scientist.h"
#include <QMessageBox>
#include <QDateEdit>

AddNewScientistDialog::AddNewScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewScientistDialog)
{
    ui->setupUi(this);
}

AddNewScientistDialog::~AddNewScientistDialog()
{
    delete ui;
}

void AddNewScientistDialog::on_buttonBox_accepted()
{
    QString name = ui->Set_name->text();
    QDate bday = ui->set_birthday->date();
    sexType sex = female;
    if(name.isEmpty())
    {
        //error handling
    }

    if(sciServ.addScientist(Scientist(name.toStdString(), sex, bday.toString().toInt())))
    {
        ui->Set_name->setText("");
    }
    else
    {
        QMessageBox::information(this,tr("Error"), tr("We were not able to add this scientist, sorry"));
    }
}
