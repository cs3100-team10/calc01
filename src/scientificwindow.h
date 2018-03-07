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
};

#endif // SCIENTIFICWINDOW_H
