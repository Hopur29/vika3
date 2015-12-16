#ifndef ADDNEWRELATIONDIALOG_H
#define ADDNEWRELATIONDIALOG_H
#include "services/linkservice.h"
#include "models/scientist.h"
#include "models/computer.h"
#include <QDialog>
#include "mainwindow.h"
#include <string>

#include <QDialog>

/**
 *adds relation between Scientist and Computers
 */

namespace Ui {
class addNewRelationDialog;
}

class addNewRelationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addNewRelationDialog(QWidget *parent = 0);
    ~addNewRelationDialog();

private slots:
    void on_buttonBox_accepted();


private:
    Ui::addNewRelationDialog *ui;
    LinkService linkServ;
};

#endif // ADDNEWRELATIONDIALOG_H
