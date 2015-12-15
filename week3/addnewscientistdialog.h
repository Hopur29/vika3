#ifndef ADDNEWSCIENTISTDIALOG_H
#define ADDNEWSCIENTISTDIALOG_H
#include "services/scientistservice.h"
#include "models/scientist.h"
#include <QDialog>
#include "mainwindow.h"
#include <string>

/**
 *adds new scientists to the dialog
 */

namespace Ui {
class AddNewScientistDialog;
}

class AddNewScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewScientistDialog(QWidget *parent = 0);
    ~AddNewScientistDialog();

private slots:
    void on_buttonBox_accepted();

    void on_checkBox_toggled(bool checked);

private:
    Ui::AddNewScientistDialog *ui;
    sexType castToSex(int cast);
    ScientistService sciServ;
};

#endif // ADDNEWSCIENTISTDIALOG_H
