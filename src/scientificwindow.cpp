#include "scientificwindow.h"
#include "ui_scientificwindow.h"
#include <sstream>
#include "mainwindow.h"
#include "exprtk_parse.h"
#include "helpdialogsci.h"

#include <QMessageBox>

scientificWindow::scientificWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::scientificWindow) {
    ui->setupUi(this);
    ui->radioButton_radians->setChecked(true);
    this->setWindowTitle("Scientific Calculator");

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

    connect(ui->pushButton_divide,SIGNAL(released()),this, SLOT(dividePressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this, SLOT(multiplyPressed()));
    connect(ui->pushButton_subtract,SIGNAL(released()),this, SLOT(subtractPressed()));
    connect(ui->pushButton_add,SIGNAL(released()),this, SLOT(addPressed()));

    connect(ui->pushButton_plusMinus,SIGNAL(released()),this, SLOT(plusMinusPressed()));
}

scientificWindow::~scientificWindow() {
    delete ui;
}

void scientificWindow::digitPressed() {
    QPushButton *button = (QPushButton*)sender();
    double buttonNumber = (button->text()).toDouble();
    QString labelText;

    QString buttonText = QString::number(buttonNumber,'g',15); // 15 is the current double precision

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + button->text();
    }
    else {
        labelText = button->text();
    }
    std::stringstream buttonVal;
    buttonVal << toParse << buttonNumber;
    toParse = buttonVal.str();

    ui->lineEdit->setText(labelText);
}

void scientificWindow::clearPressed() {
    ui->lineEdit->setText((QString)"0");
    //reset to beginning of memory if in memory
    mem.returnBegin();
    ui->label_screen->setText((QString)"");
    toParse = "";
}

void scientificWindow::backPressed() {
    QString currentText = ui->lineEdit->text();
    int textLength = currentText.length();
    currentText.truncate(textLength - 1);
    QString newText = currentText;

    ui->lineEdit->setText(newText);

    toParse = toParse.substr(0,toParse.size()-1); //delete last char from parse string
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

void scientificWindow::parFuncPressed() { // might need work
    QPushButton *button = (QPushButton*)sender();
    QString labelText;

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + button->text();
    }
    else {
        labelText = button->text();
    }

    //toParse = toParse + button->text().toStdString(); // work??
    ui->lineEdit->setText(labelText + "(");
}

void scientificWindow::piPressed() {
    QString labelText;
    QString piUnicode = QChar(0x03C0);

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + piUnicode;
    }
    else {
        labelText = piUnicode;
    }
    toParse = toParse + "pi";
    ui->lineEdit->setText(labelText);
}

void scientificWindow::leftParPressed() {
    QString labelText;
    QString leftParUnicode = QChar(0x0028);

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + leftParUnicode;
    }
    else {
        labelText = leftParUnicode;
    }
    toParse = toParse + "(";
    ui->lineEdit->setText(labelText);
}

void scientificWindow::rightParPressed() {
    QString labelText;
    QString rightParUnicode = QChar(0x0029);

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + rightParUnicode;
    }
    else {
        labelText = rightParUnicode;
    }
    toParse = toParse + ")";
    ui->lineEdit->setText(labelText);
}

void scientificWindow::decimalPressed() {
    QString labelText;
    QString decimalUnicode = QChar(0x002E);

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + decimalUnicode;
    }
    else {
        labelText = decimalUnicode;
    }
    toParse = toParse + ".";
    ui->lineEdit->setText(labelText);
}

void scientificWindow::sqrtPressed() {
    QString labelText;
    QString sqrtUnicode = QChar(0x221A);

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + sqrtUnicode;
    }
    else {
        labelText = sqrtUnicode;
    }
    toParse = toParse + "sqrt"; //should be 'sqrt(' ?
    ui->lineEdit->setText(labelText);
}

void scientificWindow::cbrtPressed() {
    QString labelText;
    QString cbrtUnicode = QChar(0x221B);

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + cbrtUnicode;
    }
    else {
        labelText = cbrtUnicode;
    }
    toParse = toParse + "cbrt"; //different?
    ui->lineEdit->setText(labelText);
}

void scientificWindow::powerPressed() {
    QString labelText;
    QString powerUnicode = QChar(0x2303);

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + powerUnicode;
    }
    else {
        labelText = powerUnicode;
    }
    toParse = toParse + "^";
    ui->lineEdit->setText(labelText);
}

void scientificWindow::expPressed() {
    QPushButton *button = (QPushButton*)sender();
    QString labelText;

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + button->text();
    }
    else {
        labelText = button->text();
    }

    ui->lineEdit->setText(labelText + "^(");
}

void scientificWindow::upPressed() {
    QString str = mem.up();
    ui->lineEdit->setText(str);
    toParse = mem.upParse();
}

void scientificWindow::downPressed() {
    QString str = mem.down();
    ui->lineEdit->setText(str);
    toParse = mem.downParse();
}

void scientificWindow::equalsPressed() {
    //removes empty node values if any exist
    QString currentText = ui->lineEdit->text();
    //adds to memory if not blank
    if (currentText != "") {
        QString str = mem.push(currentText); // will always return empty QString
        ui->lineEdit->setText(str);
    }

    double equalsAnswer = exprtk_parse(toParse); //.toLocal8Bit().constData()); // .toLocal8Bit().constData()
    //.toStdString();

    QString buttonText = QString::number(equalsAnswer,'g',15); // 15 is the current double precision
    ui->label_screen->setText(buttonText);
    toParse = "";
    string answer;
    std::stringstream stre;
    stre << answer << equalsAnswer;
    answer = stre.str();
    //push answer into memory
    str = mem.push(buttonText);
    answer = mem.pushParse(answer);
}

void scientificWindow::on_lineEdit_returnPressed()
{
    //pops the text into a message box, in the future the string will be sent to be parsed
    QMessageBox::information(this, "This will be parsed", ui->lineEdit->text());
}

void scientificWindow::dividePressed() {
    QString labelText;
    QString divideUnicode = QString("÷");

    if(ui->lineEdit->text() != (QString)"") {
        labelText = ui->lineEdit->text() + divideUnicode;
    }
    else {
        //pull from memory at last location
        QString lastMem = mem.recentMem();
        labelText = lastMem + divideUnicode;
        toParse = mem.recentMemParse();
    }
    toParse = toParse + "/";
    ui->lineEdit->setText(labelText);
}

void scientificWindow::multiplyPressed() {
    QString labelText;
    QString multiplyUnicode = QChar(0x002A);

    if(ui->lineEdit->text() != (QString)"") {
        labelText = ui->lineEdit->text() + multiplyUnicode;
    }
    else {
        //pull from memory at last location
        QString lastMem = mem.recentMem();
        labelText = lastMem + multiplyUnicode;
        toParse = mem.recentMemParse();
    }
    toParse = toParse + "*";
    ui->lineEdit->setText(labelText);
}

void scientificWindow::addPressed() {
    QString labelText;
    QString addUnicode = QChar(0x002B);

    if(ui->lineEdit->text() != (QString)"") {
        labelText = ui->lineEdit->text() + addUnicode;
    }
    else {
        //pull from memory at last location
        QString lastMem = mem.recentMem();
        labelText = lastMem + addUnicode;
        toParse = mem.recentMemParse();
    }
    toParse = toParse + "+";
    ui->lineEdit->setText(labelText);
}

void scientificWindow::subtractPressed() {
    QString labelText;
    QString subtractUnicode = QChar(0x002D);

    if(ui->lineEdit->text() != (QString)"") {
        labelText = ui->lineEdit->text() + subtractUnicode;
    }
    else {
        //pull from memory at last location
        QString lastMem = mem.recentMem();
        labelText = lastMem + subtractUnicode;
        toParse = mem.recentMemParse();
    }
    toParse = toParse + "-";
    ui->lineEdit->setText(labelText);
}

void scientificWindow::plusMinusPressed() {
    QString labelText;

    labelText = ui->lineEdit->text();

    //if already negated
    if (labelText.endsWith(")") && labelText.startsWith("-(")) {
        labelText = labelText.remove(0,2);
        int size = labelText.size();
        labelText = labelText.remove(size-1,size);

        int sizeP = toParse.size();
        toParse = toParse.substr(2,sizeP-1);
    } else { //if not negated
        labelText = QString("-(") + labelText + QString(")");
        toParse = "-(" + toParse + ")";
    }

    ui->lineEdit->setText(labelText);
}
