#include "helpdialogbasic.h"
#include "ui_helpdialogbasic.h"

helpDialogBasic::helpDialogBasic(QWidget *parent) :
    QDialog(parent), ui(new Ui::helpDialogBasic) {
    ui->setupUi(this);
    this->setWindowTitle("Basic Help Dialog");

    connect(ui->pushButton_exit,SIGNAL(released()),this,SLOT(exitPressed()));
}

//basic dialog functionality

helpDialogBasic::~helpDialogBasic() {
    delete ui;
}

void helpDialogBasic::exitPressed() {
    this->close();
}
