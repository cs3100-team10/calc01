#include "helpdialogsci.h"
#include "ui_helpdialogsci.h"

helpDialogSci::helpDialogSci(QWidget *parent) :
    QDialog(parent), ui(new Ui::helpDialogSci) {
    ui->setupUi(this);
    this->setWindowTitle("Scientific Help Dialog");

    connect(ui->pushButton_exit,SIGNAL(released()),this,SLOT(exitPressed()));
}

//basic dialog functionality

helpDialogSci::~helpDialogSci() {
    delete ui;
}

void helpDialogSci::exitPressed() {
    this->close();
}
