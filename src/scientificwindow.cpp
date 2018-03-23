#include "scientificwindow.h"
#include "ui_scientificwindow.h"
#include "mainwindow.h"         //used to allow calc to switch modes
#include "exprtk_parse.h"       //parser
#include "helpdialogsci.h"      //help dialog for scientific window
#include <sstream>              //used to append ints to string
//#include <QMessageBox>        //only used in testing
//#include <QDebug>             //only used in testing

scientificWindow::scientificWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::scientificWindow) {
    ui->setupUi(this);
    ui->radioButton_radians->setChecked(true);      //sci mode defaults to radians
    this->setWindowTitle("Scientific Calculator");

    //digit button slots & signals
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

    //trig and special function slots & signals
    connect(ui->pushButton_sin,SIGNAL(released()),this, SLOT(sinPressed()));
    connect(ui->pushButton_cos,SIGNAL(released()),this, SLOT(cosPressed()));
    connect(ui->pushButton_tan,SIGNAL(released()),this, SLOT(tanPressed()));
    connect(ui->pushButton_asin,SIGNAL(released()),this, SLOT(asinPressed()));
    connect(ui->pushButton_acos,SIGNAL(released()),this, SLOT(acosPressed()));
    connect(ui->pushButton_atan,SIGNAL(released()),this, SLOT(atanPressed()));
    connect(ui->pushButton_log,SIGNAL(released()),this, SLOT(logPressed()));
    connect(ui->pushButton_ln,SIGNAL(released()),this, SLOT(lnPressed()));
    connect(ui->pushButton_sqrt,SIGNAL(released()),this,SLOT(sqrtPressed()));
    connect(ui->pushButton_mod,SIGNAL(released()),this,SLOT(modPressed()));
    connect(ui->pushButton_power,SIGNAL(released()),this,SLOT(powerPressed()));
    connect(ui->pushButton_exp,SIGNAL(released()),this,SLOT(expPressed()));

    //mode switching/pop up window slots & signals
    connect(ui->pushButton_basicMode,SIGNAL(released()),this,SLOT(basicModePressed()));
    connect(ui->pushButton_help,SIGNAL(released()),this,SLOT(helpPressed()));

    //operation character button slots & signals
    connect(ui->pushButton_pi,SIGNAL(released()),this,SLOT(piPressed()));
    connect(ui->pushButton_parLeft,SIGNAL(released()),this,SLOT(leftParPressed()));
    connect(ui->pushButton_parRight,SIGNAL(released()),this,SLOT(rightParPressed()));
    connect(ui->pushButton_decimal,SIGNAL(released()),this,SLOT(decimalPressed()));
    connect(ui->pushButton_plusMinus,SIGNAL(released()),this, SLOT(plusMinusPressed()));

    //memory related slots & signals
    connect(ui->pushButton_up, SIGNAL(released()), this, SLOT(upPressed()));
    connect(ui->pushButton_down, SIGNAL(released()), this, SLOT(downPressed()));
    connect(ui->pushButton_equals, SIGNAL(released()), this, SLOT(equalsPressed()));
    connect(ui->pushButton_clear,SIGNAL(released()),this,SLOT(clearPressed()));
    connect(ui->pushButton_back,SIGNAL(released()),this,SLOT(backPressed()));

    //basic operation slots & signals
    connect(ui->pushButton_divide,SIGNAL(released()),this, SLOT(dividePressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this, SLOT(multiplyPressed()));
    connect(ui->pushButton_subtract,SIGNAL(released()),this, SLOT(subtractPressed()));
    connect(ui->pushButton_add,SIGNAL(released()),this, SLOT(addPressed()));
}

scientificWindow::~scientificWindow() {
    delete ui;
}

//when a digit button is pressed (0...9), append value to current display
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

//clears screen & returns to beginning of memory
void scientificWindow::clearPressed() {
    ui->lineEdit->setText((QString)"0");
    //reset to beginning of memory if in memory
    mem.returnBegin();
    ui->label_screen->setText((QString)"");
    toParse = "";
}

//remove last digit or character from screen
void scientificWindow::backPressed() {
    QString currentText = ui->lineEdit->text();
    int textLength = currentText.length();
    currentText.truncate(textLength - 1);
    QString newText = currentText;

    ui->lineEdit->setText(newText);

    toParse = toParse.substr(0,toParse.size()-1); //delete last char from parse string
}

//opens basic mode & closes scientific mode
void scientificWindow::basicModePressed() {
    MainWindow *w = new MainWindow();
    w->show();
    this->close();
}

//opens help dialog on top of scientific mode
void scientificWindow::helpPressed() {
    helpDialogSci *w = new helpDialogSci();
    w->show();
    //this->close();
}

//displays "sin(" on operation window & adds "sin(" to parsing string
void scientificWindow::sinPressed() {
    QString labelText;

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + "sin(";
    }
    else {
        labelText = "sin(";
    }
    toParse = toParse + "sin(";
    ui->lineEdit->setText(labelText);
}

//displays "cos(" on operation window & adds "cos(" to parsing string
void scientificWindow::cosPressed() {
    QString labelText;

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + "cos(";
    }
    else {
        labelText = "cos(";
    }
    toParse = toParse + "cos(";
    ui->lineEdit->setText(labelText);
}

//displays "tan(" on operation window & adds "tan(" to parsing string
void scientificWindow::tanPressed() {
    QString labelText;

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + "tan(";
    }
    else {
        labelText = "tan(";
    }
    toParse = toParse + "tan(";
    ui->lineEdit->setText(labelText);
}

//displays "asin(" on operation window & adds "asin(" to parsing string
void scientificWindow::asinPressed() {
    QString labelText;

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + "asin(";
    }
    else {
        labelText = "asin(";
    }
    toParse = toParse + "asin(";
    ui->lineEdit->setText(labelText);
}

//displays "acos(" on operation window & adds "acos(" to parsing string
void scientificWindow::acosPressed() {
    QString labelText;

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + "acos(";
    }
    else {
        labelText = "acos(";
    }
    toParse = toParse + "acos(";
    ui->lineEdit->setText(labelText);
}

//displays "atan(" on operation window & adds "atan(" to parsing string
void scientificWindow::atanPressed() {
    QString labelText;

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + "atan(";
    }
    else {
        labelText = "atan(";
    }
    toParse = toParse + "atan(";
    ui->lineEdit->setText(labelText);
}

//displays "log(" on operation window & adds "log10(" to parsing string
void scientificWindow::logPressed() {
    QString labelText;

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + "log(";
    }
    else {
        labelText = "log(";
    }
    toParse = toParse + "log10(";
    ui->lineEdit->setText(labelText);
}

//displays "ln(" on operation window & adds "log(" to parsing string
void scientificWindow::lnPressed() {
    QString labelText;

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + "ln(";
    }
    else {
        labelText = "ln(";
    }
    toParse = toParse + "log(";
    ui->lineEdit->setText(labelText);
}

//displays unicode pi on operation window & adds "pi" to parsing string
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

//displays unicode '(' on operation window & adds "(" to parsing string
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

//displays unicode '(' on operation window & adds ")" to parsing string
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

//displays unicode '.' on operation window & adds "." to parsing string
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

//displays unicode sqrt on operation window & adds "sqrt(" to parsing string
void scientificWindow::sqrtPressed() {
    QString labelText;
    QString sqrtUnicode = QChar(0x221A);

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + sqrtUnicode;
    }
    else {
        labelText = sqrtUnicode;
    }
    toParse = toParse + "sqrt(";
    ui->lineEdit->setText(labelText);
}

//displays unicode % on operation window & adds "%" to parsing string
void scientificWindow::modPressed() {
    QString labelText;
    QString modUnicode = QChar(0xFF05);

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + modUnicode;
    }
    else {
        labelText = modUnicode;
    }
    toParse = toParse + "%";
    ui->lineEdit->setText(labelText);
}

//displays unicode ^ on operation window & adds "^" to parsing string
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

//displays "e^(" on operation window & adds "exp(" to parsing string
void scientificWindow::expPressed() {
    QPushButton *button = (QPushButton*)sender();
    QString labelText;

    if(ui->lineEdit->text() != (QString)"0") {
        labelText = ui->lineEdit->text() + button->text();
    }
    else {
        labelText = button->text();
    }
    toParse = toParse + "exp(";
    ui->lineEdit->setText(labelText + "e^(");
}

//walks to previous entry in memory and displays it on screen
void scientificWindow::upPressed() {
    QString str = mem.up();
    ui->lineEdit->setText(str);
    toParse = mem.upParse();
}

//walks to next entry in memory and displays in the screen
void scientificWindow::downPressed() {
    QString str = mem.down();
    ui->lineEdit->setText(str);
    toParse = mem.downParse();
}

//calculates answer using parser, clears parse string, stores answer in memory and displays
void scientificWindow::equalsPressed() {
    //removes empty node values if any exist
    QString currentText = ui->lineEdit->text();
    QString str;
    string str1;
    //adds to memory if not blank
    if (currentText != QString("")) {
        ui->lineEdit->setText("");

        double equalsAnswer = exprtk_parse(toParse);
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
}

//works as 'equalsPressed' function when 'enter' is pressed on keyboard
void scientificWindow::on_lineEdit_returnPressed() {
    //removes empty node values if any exist
    QString currentText = ui->lineEdit->text();
    QString str;
    string str1;
    string toBeParsed = ui->lineEdit->text().toStdString();

    //adds to memory if not blank
    if (currentText != "") {
        str = mem.push(currentText);
        str1 = mem.pushParse(toBeParsed);
        ui->lineEdit->setText(str);

        double equalsAnswer = exprtk_parse(toBeParsed);
        QString buttonText = QString::number(equalsAnswer,'g',15); // 15 is the current double precision
        ui->label_screen->setText(buttonText);

        string answer;
        std::stringstream stre;
        stre << answer << equalsAnswer;
        answer = stre.str();
        //push answer into memory
        str = mem.push(buttonText);
        answer = mem.pushParse(answer);
     }
}

//displays unicode divide on operation window & adds "\" to parsing string
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

//displays unicode multiply on operation window & adds "*" to parsing string
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

//displays unicode addition on operation window & adds "+" to parsing string
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

//displays unicode minus on operation window & adds "-" to parsing string
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

//checks status of current value and negates it
void scientificWindow::plusMinusPressed() {
    QString labelText;

    labelText = ui->lineEdit->text();
    if (labelText != QString("")){
        //if already negated
        if (labelText.endsWith(")") && labelText.startsWith("-(")) {
            labelText = labelText.remove(0,2);
            int size = labelText.size();
            labelText = labelText.remove(size-1,size);

            int sizeP = toParse.size();
            //toParse = toParse.substr(2,sizeP-1);
            toParse = toParse.substr(2,sizeP-3); //Now the string cuts off the parenth at the end properly
        } else { //if not negated
            labelText = QString("-(") + labelText + QString(")");
            toParse = "-(" + toParse + ")";
        }
    }

    ui->lineEdit->setText(labelText);
}
