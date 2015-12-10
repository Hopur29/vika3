#ifndef ADDNEWSCIENTISTDIALOG_H
#define ADDNEWSCIENTISTDIALOG_H
#include "services/scientistservice.h"
#include <QDialog>

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

private:
    Ui::AddNewScientistDialog *ui;


    ScientistService sciServ;
};

#endif // ADDNEWSCIENTISTDIALOG_H
