#ifndef HELPDIALOGSCI_H
#define HELPDIALOGSCI_H

#include <QDialog>

namespace Ui {
class helpDialogSci;
}

class helpDialogSci : public QDialog
{
    Q_OBJECT

public:
    explicit helpDialogSci(QWidget *parent = 0);
    ~helpDialogSci();

private:
    Ui::helpDialogSci *ui;

private slots:
    void exitPressed();
};

#endif // HELPDIALOGSCI_H
