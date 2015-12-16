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
    //The form for adding new scientist is not opened unless pushButton add is pressed.

    void on_checkBox_toggled(bool checked);
    /*If this checkBox is toggled, then it indicates that the computer scientist
    is dead and the field Death_Year is neccessary. Otherwise that field gets null value*/

private:
    Ui::AddNewScientistDialog *ui;
    sexType castToSex(int cast);
    ScientistService sciServ;
};

#endif // ADDNEWSCIENTISTDIALOG_H
