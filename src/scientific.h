#ifndef SCIENTIFIC_H
#define SCIENTIFIC_H

#include <QMainWindow>

namespace Ui {
class Scientific;
}

class Scientific : public QMainWindow {
    Q_OBJECT

public:
    Scientific(QWidget *parent = 0);
    ~Scientific();

private:
    Ui::Scientific *ui;

//private slots:

};

#endif // SCIENTIFIC_H
