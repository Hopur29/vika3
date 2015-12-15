#include "addnewscientistdialog.h"
#include "ui_addnewscientistdialog.h"
#include <QMessageBox>
#include "utilities/utils.h"

AddNewScientistDialog::AddNewScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewScientistDialog)
{
    ui->setupUi(this);
    ui->set_deathYear->hide();
}

AddNewScientistDialog::~AddNewScientistDialog()
{
    delete ui;
}

void AddNewScientistDialog::on_buttonBox_accepted()
{
    QString name = ui->Set_name->text();
    QString bday = ui->set_birthYear->text();
    QString dyear = ui->set_deathYear->text();
    int sex = ui->Set_sex->currentIndex();

    if(name.isEmpty())
    {
       QMessageBox::information(this,tr("Error"), tr("Scientists must have a name."));
    }
    else if(bday.isEmpty())
    {
        QMessageBox::information(this,tr("Error"), tr("Scientists must have a birthday."));
    }   

    else if(ui->set_deathYear->isHidden())
    {
        if(sciServ.addScientist(Scientist(name.toStdString(), utils::intToSex(sex), bday.toUInt())))
        {
            ui->Set_name->setText("");
        }
        else
        {
            QMessageBox::information(this,tr("Error"), tr("We were not able to add this scientist, sorry"));
        }
    }
    else
    {
        if(sciServ.addScientist(Scientist(name.toStdString(), utils::intToSex(sex), bday.toUInt(), dyear.toUInt())))
        {
            ui->Set_name->setText("");
        }
        else
        {
            QMessageBox::information(this,tr("Error"), tr("We were not able to add this scientist, sorry"));
        }
    }
}

void AddNewScientistDialog::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        ui->set_deathYear->show();
    }
    else
    {
        ui->set_deathYear->hide();
    }
}
