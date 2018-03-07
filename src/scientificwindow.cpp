#include "scientificwindow.h"
#include "ui_scientificwindow.h"
#include "mainwindow.h"

//#include <QDebug>

scientificWindow::scientificWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::scientificWindow) {
    ui->setupUi(this);

    connect(ui->pushButton_0zero,SIGNAL(released()),this, SLOT(digitPressed()));
    connect(ui->pushButton_1one,SIGNAL(released()),this, SLOT(digitPressed()));
    connect(ui->pushButton_2two,SIGNAL(released()),this, SLOT(digitPressed()));
    connect(ui->pushButton_3three,SIGNAL(released()),this, SLOT(digitPressed()));
    connect(ui->pushButton_4four,SIGNAL(released()),this, SLOT(digitPressed()));
    connect(ui->pushButton_5five,SIGNAL(released()),this, SLOT(digitPressed()));
    connect(ui->pushButton_6six,SIGNAL(released()),this, SLOT(digitPressed()));
    connect(ui->pushButton_7seven,SIGNAL(released()),this, SLOT(digitPressed()));
    connect(ui->pushButton_8eight,SIGNAL(released()),this, SLOT(digitPressed()));
    connect(ui->pushButton_9nine,SIGNAL(released()),this, SLOT(digitPressed()));

    connect(ui->pushButton_sin,SIGNAL(released()),this, SLOT(parFuncPressed()));
    connect(ui->pushButton_cos,SIGNAL(released()),this, SLOT(parFuncPressed()));
    connect(ui->pushButton_tan,SIGNAL(released()),this, SLOT(parFuncPressed()));
    connect(ui->pushButton_asin,SIGNAL(released()),this, SLOT(parFuncPressed()));
    connect(ui->pushButton_acos,SIGNAL(released()),this, SLOT(parFuncPressed()));
    connect(ui->pushButton_atan,SIGNAL(released()),this, SLOT(parFuncPressed()));

    connect(ui->pushButton_clear,SIGNAL(released()),this,SLOT(clearPressed()));

    connect(ui->pushButton_back,SIGNAL(released()),this,SLOT(backPressed()));

    connect(ui->pushButton_basicMode,SIGNAL(released()),this,SLOT(basicModePressed()));

    connect(ui->radioButton_degrees,SIGNAL(pressed()),this,SLOT(degPressed()));
    connect(ui->radioButton_radians,SIGNAL(pressed()),this,SLOT(radPressed()));
}

scientificWindow::~scientificWindow() {
    delete ui;
}

void scientificWindow::digitPressed() {
    //qDebug() << "test";

    QPushButton *button = (QPushButton*)sender();

    double labelNumber = (ui->label_screen->text() + button->text()).toDouble();

    QString labelText = QString::number(labelNumber,'g',15); // 15 is the current double precision

    ui->label_screen->setText(labelText);
}

void scientificWindow::parFuncPressed() {
    QPushButton *button = (QPushButton*)sender();
    QString labelText;

    //qDebug << ui->label_screen->text();

    if(ui->label_screen->text() != (QString)"0") {
        labelText = ui->label_screen->text() + " " + button->text();
    }
    else {
        labelText = button->text();
    }

    //QString labelText = QString::number(labelNumber,'g',15); // 15 is the current double precision

    ui->label_screen->setText(labelText + "(");

}

void scientificWindow::clearPressed() {
    QString currentText = ui->label_screen->text();

    //TO DO:
    // add functionality to save what was currently on the screen before clearing it

    ui->label_screen->setText((QString)"");

}

void scientificWindow::backPressed() {
    QString currentText = ui->label_screen->text();
    int textLength = currentText.length();
    currentText.truncate(textLength - 1);
     QString newText = currentText;

    ui->label_screen->setText(newText);

}

void scientificWindow::basicModePressed() {
    MainWindow *w = new MainWindow();
    w->show();
    this->close();
}

void scientificWindow::radPressed() {
//    ui->radioButton_degrees->isDown();
}

void scientificWindow::degPressed() {
  //  ui->radioButton_radians->!(isDown());
}
