#ifndef HELPDIALOGBASIC_H
#define HELPDIALOGBASIC_H

#include <QDialog>

namespace Ui {
class helpDialogBasic;
}

class helpDialogBasic : public QDialog
{
    Q_OBJECT

public:
    explicit helpDialogBasic(QWidget *parent = 0);
    ~helpDialogBasic();

private:
    Ui::helpDialogBasic *ui;

private slots:
    void exitPressed();
};

#endif // HELPDIALOGBASIC_H
