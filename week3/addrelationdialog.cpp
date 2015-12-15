#include "addrelationdialog.h"
#include "ui_addrelationdialog.h"

addrelationdialog::addrelationdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addrelationdialog)
{
    ui->setupUi(this);
}

addrelationdialog::~addrelationdialog()
{
    delete ui;
}
