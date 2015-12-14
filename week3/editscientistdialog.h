#ifndef EDITSCIENTISTDIALOG_H
#define EDITSCIENTISTDIALOG_H
#include "models/scientist.h"
#include "services/scientistservice.h"
#include <QDialog>

namespace Ui {
class EditScientistDialog;
}

class EditScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditScientistDialog(QWidget *parent = 0);
    ~EditScientistDialog();

    void setInstance(Scientist sci);
private slots:
    void on_buttonBox_accepted();

    void on_checkBox_toggled(bool checked);

private:
    Ui::EditScientistDialog *ui;
    ScientistService sciServ;
    int id;
};

#endif // EDITSCIENTISTDIALOG_H
