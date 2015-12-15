#include "addnewrelationdialog.h"
#include "ui_addnewrelationdialog.h"

addNewRelationDialog::addNewRelationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNewRelationDialog)
{
    ui->setupUi(this);
}

addNewRelationDialog::~addNewRelationDialog()
{
    delete ui;
}

void addNewRelationDialog::on_buttonBox_accepted()
{
    QString scientist_id = ui->Scientist_id_spinbox->text();
    QString computer_id = ui->Computer_id_spinbox->text();

    linkServ.addLink(scientist_id.toStdString(),computer_id.toStdString());
}
