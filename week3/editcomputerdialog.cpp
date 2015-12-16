#include "editcomputerdialog.h"
#include "ui_editcomputerdialog.h"
#include "models/computer.h"
#include "utilities/constants.h"
#include "utilities/utils.h"
#include <QMessageBox>
#include <QDate>

editcomputerdialog::editcomputerdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcomputerdialog)
{
    ui->setupUi(this);
    ui->dateEdit->hide();
}

editcomputerdialog::~editcomputerdialog()
{
    delete ui;
}


void editcomputerdialog::setInstance(Computer comp)
{
    ui->comp_name_edit->setText(QString::fromStdString(comp.getName()));
    ui->comp_type_edit->setCurrentIndex(comp.getType());
    ui->dateEdit->setDate(QDate(comp.getYearBuilt(), 1, 1));
    id = comp.getId();

    if(comp.getYearBuilt() == constants::YEAR_UNSELECTED_VALUE2)
       {
           on_checkBox_toggled(false);
       }
       else
       {
           on_checkBox_toggled(true);
       }

}

void editcomputerdialog::on_buttonBox_accepted()
{
    QString name = ui->comp_name_edit->text();
    int type = ui->comp_type_edit->currentIndex();
    QString byear = ui->dateEdit->text();

    if(name.isEmpty())
    {
        QMessageBox::information(this,tr("Error"), tr("You must specify a name"));
    }

    if(ui->dateEdit->isHidden())
    {
        if(!compServ.editComputer(Computer(name.toStdString(), utils::intToComputerType(type)), id))
        {
            QMessageBox::information(this,tr("Error"), tr("error editing"));
        }
    }

    else
    {
        if(!compServ.editComputer(Computer(name.toStdString(), utils::intToComputerType(type), byear.toUInt()), id))
        {
            QMessageBox::information(this,tr("Error"), tr("error editing"));
        }

    }

}

void editcomputerdialog::on_checkBox_toggled(bool checked)
{
    if(checked)
        {
            ui->dateEdit->show();
        }
        else
        {
            ui->dateEdit->hide();
        }
}


