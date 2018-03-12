#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "memStorage.cpp"
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;

private slots:
    void digitPressed();
    void clearPressed();
    void backPressed();
    void sciModePressed();
    void upPressed();
    void downPressed();
    void decimalPressed();
    void equalsPressed();
};

#endif // MAINWINDOW_H
