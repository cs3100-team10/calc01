#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scientificwindow.h"
#include "helpdialogbasic.h"

//#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Basic Calculator");
    MemStorage mem;

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

    connect(ui->pushButton_clear,SIGNAL(released()),this,SLOT(clearPressed()));

    connect(ui->pushButton_back,SIGNAL(released()),this,SLOT(backPressed()));

    connect(ui->pushButton_sciMode,SIGNAL(released()),this,SLOT(sciModePressed()));
    connect(ui->pushButton_help,SIGNAL(released()),this,SLOT(helpPressed()));

    connect(ui->pushButton_up,SIGNAL(released()),this,SLOT(upPressed()));

    connect(ui->pushButton_down,SIGNAL(released()),this,SLOT(downPressed()));

    connect(ui->pushButton_equals,SIGNAL(released()),this,SLOT(equalsPressed()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::digitPressed() {
    QPushButton *button = (QPushButton*)sender();
    double buttonNumber = (button->text()).toDouble();
    QString labelText;

    QString buttonText = QString::number(buttonNumber,'g',15); // 15 is the current double precision

    if(ui->label_screen->text() != (QString)"0") {
        labelText = ui->label_screen->text() + button->text();
    }
    else {
        labelText = button->text();
    }

    ui->label_screen->setText(labelText);
}

void MainWindow::clearPressed() {
    ui->label_screen->setText((QString)"0");
}

void MainWindow::backPressed() {
    QString currentText = ui->label_screen->text();
    int textLength = currentText.length();
    currentText.truncate(textLength - 1);
     QString newText = currentText;

    ui->label_screen->setText(newText);
}

void MainWindow::sciModePressed() {
    scientificWindow *w = new scientificWindow();
    w->show();
    this->close();
}

void MainWindow::helpPressed() {
    helpDialogBasic *w = new helpDialogBasic();
    w->show();
    //this->close();
}

void MainWindow::upPressed() {
    QString str = mem.up();
    ui->label_screen->setText(str);
}

void MainWindow::downPressed() {
    QString str = mem.down();
    ui->label_screen->setText(str);
}

void MainWindow::decimalPressed() {
    QString labelText;
    QString decimalUnicode = QChar(0x002E);

    if(ui->label_screen->text() != (QString)"0") {
        labelText = ui->label_screen->text() + decimalUnicode;
    }
    else {
        labelText = decimalUnicode;
    }

    ui->label_screen->setText(labelText);
}

void MainWindow::equalsPressed() {
    //removes empty node values if any exist
    QString currentText = ui->label_screen->text();
    //adds to memory if not blank
    if (currentText != "") {
        QString str = mem.push(currentText);
        ui->label_screen->setText(str);
    }
}
