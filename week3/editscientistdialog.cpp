#include "editscientistdialog.h"
#include "ui_editscientistdialog.h"
#include "models/scientist.h"
#include "utilities/utils.h"
#include <QMessageBox>
#include <QDate>

/**
 *edits the Scientists and checks for errors
 */

EditScientistDialog::EditScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditScientistDialog)
{
    ui->setupUi(this);
    ui->Death_Year_Edit->hide();
}

EditScientistDialog::~EditScientistDialog()
{
    delete ui;
}

void EditScientistDialog::setInstance(Scientist sci)
{
    ui->Name_Edit->setText(QString::fromStdString(sci.getName()));
    ui->Birth_Year_Edit->setDate(QDate(sci.getYearBorn(), 1, 1));
    ui->comboBox->setCurrentIndex(sci.getSex());
    ui->Death_Year_Edit->setDate(QDate(sci.getYearDied(), 1, 1));
    id = sci.getId();

    if(sci.getYearDied() == 13337)
    {
        on_checkBox_toggled(false);
    }
    else
    {
        on_checkBox_toggled(true);
    }
}

void EditScientistDialog::on_buttonBox_accepted()
{
    QString name = ui->Name_Edit->text();
    QString bday = ui->Birth_Year_Edit->text();
    QString dyear = ui->Death_Year_Edit->text();
    int sex = ui->comboBox->currentIndex();

    if(name.isEmpty())
    {
        QMessageBox::information(this,tr("Error"), tr("You must specify a name"));
    }
    if(bday.isEmpty())
    {
        QMessageBox::information(this,tr("Error"), tr("You must specify birth year"));
    }

    if(ui->Death_Year_Edit->isHidden())
    {
        if(!sciServ.editScientist(Scientist(name.toStdString(), utils::intToSex(sex), bday.toUInt()), id))
        {
            QMessageBox::information(this,tr("Error"), tr("error editing"));
        }
    }
    else
    {
        if(!sciServ.editScientist(Scientist(name.toStdString(), utils::intToSex(sex), bday.toUInt(), dyear.toUInt()), id))
        {
            QMessageBox::information(this,tr("Error"), tr("error editing"));
        }
    }
}

void EditScientistDialog::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        ui->Death_Year_Edit->show();
    }
    else
    {
        ui->Death_Year_Edit->hide();
    }
}
