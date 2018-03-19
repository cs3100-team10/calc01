#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "memStorage.h"
#include "string.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    MemStorage mem;
    String toParse;

private:
    Ui::MainWindow *ui;

private slots:
    void digitPressed();
    void clearPressed();
    void backPressed();
    void sciModePressed();
    void helpPressed();
    void upPressed();
    void downPressed();
    void decimalPressed();
    void equalsPressed();
    void on_lineEdit_returnPressed();
    void dividePressed();
    void multiplyPressed();
    void addPressed();
    void subtractPressed();
};

#endif // MAINWINDOW_H
