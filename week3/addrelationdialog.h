#ifndef ADDRELATIONDIALOG_H
#define ADDRELATIONDIALOG_H

#include <QDialog>

namespace Ui {
class addrelationdialog;
}

class addrelationdialog : public QDialog
{
    Q_OBJECT

public:
    explicit addrelationdialog(QWidget *parent = 0);
    ~addrelationdialog();

private:
    Ui::addrelationdialog *ui;
};

#endif // ADDRELATIONDIALOG_H
