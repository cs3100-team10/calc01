#include "scientificwindow.h"
#include "ui_scientificwindow.h"
#include "mainwindow.h"
#include "helpdialogsci.h"

#include <QMessageBox>

//#include <QDebug>

scientificWindow::scientificWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::scientificWindow) {
    ui->setupUi(this);
    ui->radioButton_radians->setChecked(true);
    this->setWindowTitle("Scientific Calculator");
    //this->statusBar()->setSizeGripEnabled(false);

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
    connect(ui->pushButton_log,SIGNAL(released()),this, SLOT(parFuncPressed()));
    connect(ui->pushButton_ln,SIGNAL(released()),this, SLOT(parFuncPressed()));

    connect(ui->pushButton_clear,SIGNAL(released()),this,SLOT(clearPressed()));

    connect(ui->pushButton_back,SIGNAL(released()),this,SLOT(backPressed()));

    connect(ui->pushButton_basicMode,SIGNAL(released()),this,SLOT(basicModePressed()));
    connect(ui->pushButton_help,SIGNAL(released()),this,SLOT(helpPressed()));

    connect(ui->pushButton_pi,SIGNAL(released()),this,SLOT(piPressed()));
    connect(ui->pushButton_parLeft,SIGNAL(released()),this,SLOT(leftParPressed()));
    connect(ui->pushButton_parRight,SIGNAL(released()),this,SLOT(rightParPressed()));
    connect(ui->pushButton_decimal,SIGNAL(released()),this,SLOT(decimalPressed()));
    connect(ui->pushButton_sqrt,SIGNAL(released()),this,SLOT(sqrtPressed()));
    connect(ui->pushButton_cbrt,SIGNAL(released()),this,SLOT(cbrtPressed()));
    connect(ui->pushButton_power,SIGNAL(released()),this,SLOT(powerPressed()));
    connect(ui->pushButton_exp,SIGNAL(released()),this,SLOT(expPressed()));

    connect(ui->pushButton_up, SIGNAL(released()), this, SLOT(upPressed()));
    connect(ui->pushButton_down, SIGNAL(released()), this, SLOT(downPressed()));
    connect(ui->pushButton_equals, SIGNAL(released()), this, SLOT(equalsPressed()));
}

scientificWindow::~scientificWindow() {
    delete ui;
}

void scientificWindow::digitPressed() {
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

void scientificWindow::clearPressed() {
    ui->label_screen->setText((QString)"0");
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

void scientificWindow::helpPressed() {
    helpDialogSci *w = new helpDialogSci();
    w->show();
    //this->close();
}

void scientificWindow::parFuncPressed() {
    QPushButton *button = (QPushButton*)sender();
    QString labelText;

    if(ui->label_screen->text() != (QString)"0") {
        labelText = ui->label_screen->text() + button->text();
    }
    else {
        labelText = button->text();
    }

    ui->label_screen->setText(labelText + "(");
}



void scientificWindow::piPressed() {
    QString labelText;
    QString piUnicode = QChar(0x03C0);

    if(ui->label_screen->text() != (QString)"0") {
        labelText = ui->label_screen->text() + piUnicode;
    }
    else {
        labelText = piUnicode;
    }

    ui->label_screen->setText(labelText);
}

void scientificWindow::leftParPressed() {
    QString labelText;
    QString leftParUnicode = QChar(0x0028);

    if(ui->label_screen->text() != (QString)"0") {
        labelText = ui->label_screen->text() + leftParUnicode;
    }
    else {
        labelText = leftParUnicode;
    }

    ui->label_screen->setText(labelText);
}

void scientificWindow::rightParPressed() {
    QString labelText;
    QString rightParUnicode = QChar(0x0029);

    if(ui->label_screen->text() != (QString)"0") {
        labelText = ui->label_screen->text() + rightParUnicode;
    }
    else {
        labelText = rightParUnicode;
    }

    ui->label_screen->setText(labelText);
}

void scientificWindow::decimalPressed() {
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

void scientificWindow::sqrtPressed() {
    QString labelText;
    QString sqrtUnicode = QChar(0x221A);

    if(ui->label_screen->text() != (QString)"0") {
        labelText = ui->label_screen->text() + sqrtUnicode;
    }
    else {
        labelText = sqrtUnicode;
    }

    ui->label_screen->setText(labelText);
}

void scientificWindow::cbrtPressed() {
    QString labelText;
    QString cbrtUnicode = QChar(0x221B);

    if(ui->label_screen->text() != (QString)"0") {
        labelText = ui->label_screen->text() + cbrtUnicode;
    }
    else {
        labelText = cbrtUnicode;
    }

    ui->label_screen->setText(labelText);
}

void scientificWindow::powerPressed() {
    QString labelText;
    QString powerUnicode = QChar(0x2303);

    if(ui->label_screen->text() != (QString)"0") {
        labelText = ui->label_screen->text() + powerUnicode;
    }
    else {
        labelText = powerUnicode;
    }

    ui->label_screen->setText(labelText);
}

void scientificWindow::expPressed() {
    QPushButton *button = (QPushButton*)sender();
    QString labelText;

    if(ui->label_screen->text() != (QString)"0") {
        labelText = ui->label_screen->text() + button->text();
    }
    else {
        labelText = button->text();
    }

    ui->label_screen->setText(labelText + "^(");
}

void scientificWindow::upPressed() {
    QString str = mem.up();
    ui->label_screen->setText(str);
}

void scientificWindow::downPressed() {
    QString str = mem.down();
    ui->label_screen->setText(str);
}

void scientificWindow::equalsPressed() {
    //removes empty node values if any exist
    QString currentText = ui->label_screen->text();
    //adds to memory if not blank
    if (currentText != "") {
        QString str = mem.push(currentText); // will always return empty QString
        ui->label_screen->setText(str);
    }
}


void scientificWindow::on_lineEdit_returnPressed()
{
    //pops the text into a message box, in the future the string will be sent to be parsed
    QMessageBox::information(this, "This will be parsed", ui->lineEdit->text());
}
