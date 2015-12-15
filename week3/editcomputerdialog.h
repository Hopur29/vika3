#ifndef EDITCOMPUTERDIALOG_H
#define EDITCOMPUTERDIALOG_H
#include "models/computer.h"
#include "services/computerservice.h"
#include <QDialog>

#include <QDialog>

namespace Ui {
class editcomputerdialog;
}

class editcomputerdialog : public QDialog
{
    Q_OBJECT

public:
    explicit editcomputerdialog(QWidget *parent = 0);

    ~editcomputerdialog();

    void setInstance(Computer comp);

private slots:
    void on_buttonBox_accepted();

    void on_checkBox_toggled(bool checked);

private:
    Ui::editcomputerdialog *ui;
    ComputerService compServ;
    int id;
};

#endif // EDITCOMPUTERDIALOG_H
