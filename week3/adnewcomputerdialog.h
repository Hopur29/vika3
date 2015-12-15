#ifndef ADNEWCOMPUTERDIALOG_H
#define ADNEWCOMPUTERDIALOG_H

#include "services/computerservice.h"
#include "mainwindow.h"
#include <QDialog>

/**
 *adds new computers to the dialog
 */

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

    void on_pushButton_clicked();

private:
    Ui::adnewcomputerdialog *ui;

    computerType castToType(int cast);

    ComputerService comServ;
};

#endif // ADNEWCOMPUTERDIALOG_H
