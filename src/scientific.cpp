#include "scientific.h"
#include "ui_scientific.h"

//#include <QDebug>

Scientific::Scientific(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Scientific)
{
    ui->setupUi(this);
}

Scientific::~Scientific()
{
    delete ui;
}
