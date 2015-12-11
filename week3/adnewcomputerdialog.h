#ifndef ADNEWCOMPUTERDIALOG_H
#define ADNEWCOMPUTERDIALOG_H

#include "services/computerservice.h"
#include <QDialog>

namespace Ui {
class adnewcomputerdialog;
}

class adnewcomputerdialog : public QDialog
{
    Q_OBJECT

public:
    explicit adnewcomputerdialog(QWidget *parent = 0);
    ~adnewcomputerdialog();

private slots:
    void on_addOK_accepted();

private:
    Ui::adnewcomputerdialog *ui;

    computerType castToType(int cast);

    ComputerService comServ;
};

#endif // ADNEWCOMPUTERDIALOG_H
