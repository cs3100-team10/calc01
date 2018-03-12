#ifndef SCIENTIFICWINDOW_H
#define SCIENTIFICWINDOW_H

#include <QDialog>

namespace Ui {
class scientificWindow;
}

class scientificWindow : public QDialog
{
    Q_OBJECT

public:
    explicit scientificWindow(QWidget *parent = 0);
    ~scientificWindow();

private:
    Ui::scientificWindow *ui;

private slots:
    void digitPressed();
    void clearPressed();
    void backPressed();
    void basicModePressed();
    void parFuncPressed();
    void piPressed();
    void leftParPressed();
    void rightParPressed();
    void decimalPressed();
    void sqrtPressed();
    void cbrtPressed();
    void powerPressed();
    void expPressed();
};

#endif // SCIENTIFICWINDOW_H
