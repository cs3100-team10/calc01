#ifndef SCIENTIFICWINDOW_H
#define SCIENTIFICWINDOW_H

#include <QDialog>
#include "memStorage.h"
#include <string>

namespace Ui {
class scientificWindow;
}

class scientificWindow : public QDialog
{
    Q_OBJECT

public:
    explicit scientificWindow(QWidget *parent = 0);
    ~scientificWindow();
    MemStorage mem;
    string toParse;

private:
    Ui::scientificWindow *ui;

private slots:
    void digitPressed();
    void clearPressed();
    void backPressed();
    void basicModePressed();
    void helpPressed();
    void sinPressed();
    void cosPressed();
    void tanPressed();
    void asinPressed();
    void acosPressed();
    void atanPressed();
    void logPressed();
    void lnPressed();

    void piPressed();
    void leftParPressed();
    void rightParPressed();
    void decimalPressed();
    void sqrtPressed();
    void modPressed();
    void powerPressed();
    void expPressed();

    void upPressed();
    void downPressed();
    void equalsPressed();
    void on_lineEdit_returnPressed();

    void dividePressed();
    void multiplyPressed();
    void addPressed();
    void subtractPressed();

    void plusMinusPressed();
};

#endif // SCIENTIFICWINDOW_H
