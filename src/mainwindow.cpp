#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scientificwindow.h"
#include "helpdialogbasic.h"
#include "exprtk_parse.h"
#include <sstream>

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Basic Calculator");
    MemStorage mem;

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

    //mode switching/pop up window slots & signals
    connect(ui->pushButton_sciMode,SIGNAL(released()),this,SLOT(sciModePressed()));
    connect(ui->pushButton_help,SIGNAL(released()),this,SLOT(helpPressed()));

    //memory related slots & signals
    connect(ui->pushButton_up,SIGNAL(released()),this,SLOT(upPressed()));
    connect(ui->pushButton_down,SIGNAL(released()),this,SLOT(downPressed()));
    connect(ui->pushButton_clear,SIGNAL(released()),this,SLOT(clearPressed()));
    connect(ui->pushButton_back,SIGNAL(released()),this,SLOT(backPressed()));
    connect(ui->pushButton_equals,SIGNAL(released()),this,SLOT(equalsPressed()));

    //basic operation slots & signals
    connect(ui->pushButton_divide,SIGNAL(released()),this, SLOT(dividePressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this, SLOT(multiplyPressed()));
    connect(ui->pushButton_subtract,SIGNAL(released()),this, SLOT(subtractPressed()));
    connect(ui->pushButton_add,SIGNAL(released()),this, SLOT(addPressed()));

    //operation character button slots & signals
    connect(ui->pushButton_decimal,SIGNAL(released()),this, SLOT(decimalPressed()));
}

MainWindow::~MainWindow() {
    delete ui;
}

//when a digit button is pressed (0...9), append value to current display
void MainWindow::digitPressed() {
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

    //If you un-comment the line below, memory stops working correctly
    //ui->label_screen->setText(labelText);
    std::stringstream buttonVal;
    buttonVal << toParse << buttonNumber;
    toParse = buttonVal.str();

    ui->lineEdit->setText(labelText);
}

//clears screen & returns to beginning of memory
void MainWindow::clearPressed() {
    ui->lineEdit->setText((QString)"0");
    //reset to beginning of memory if in memory
    mem.returnBegin();
    ui->label_screen->setText((QString)"");
    toParse = "";
}

//remove last digit or character from screen
void MainWindow::backPressed() {
    QString currentText = ui->lineEdit->text();
    int textLength = currentText.length();
    currentText.truncate(textLength - 1);
    QString newText = currentText;

    ui->lineEdit->setText(newText);

    toParse = toParse.substr(0,toParse.size()-1); //delete last char from parse string
}

//opens sci mode & closes basic mode
void MainWindow::sciModePressed() {
    scientificWindow *w = new scientificWindow();
    w->show();
    this->close();
}

//opens help dialog on top of basic mode
void MainWindow::helpPressed() {
    helpDialogBasic *w = new helpDialogBasic();
    w->show();
    //this->close();
}

//walks to previous entry in memory and displays it on screen
void MainWindow::upPressed() {
    QString str = mem.up();
    toParse = mem.upParse();
    ui->lineEdit->setText(str);
}

//walks to next entry in memory and displays in the screen
void MainWindow::downPressed() {
    QString str = mem.down();
    toParse = mem.downParse();
    ui->lineEdit->setText(str);
}

//displays unicode '.' on operation window & adds "." to parsing string
void MainWindow::decimalPressed() {
    QString labelText;
    QString decimalUnicode = QChar(0x002E);

    if(ui->lineEdit->text() != (QString)"") {
        labelText = ui->lineEdit->text() + decimalUnicode;
    }
    else {
        labelText = QString("0") + decimalUnicode;
    }
    toParse = toParse + ".";
    ui->lineEdit->setText(labelText);
}

//calculates answer using parser, clears parse string, stores answer in memory and displays
void MainWindow::equalsPressed() {
    //removes empty node values if any exist
    QString currentText = ui->lineEdit->text();
    QString str;
    string str1;
    //adds to memory if not blank
    if (currentText != QString("")) {
        ui->lineEdit->setText("");

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
}

//works as 'equalsPressed' function when 'enter' is pressed on keyboard
void MainWindow::on_lineEdit_returnPressed() {
    //removes empty node values if any exist
    QString currentText = ui->lineEdit->text();
    QString str;
    string str1;
    string toBeParsed = ui->lineEdit->text().toStdString();

    //adds to memory if not blank
    if (currentText != QString("")) {
        ui->lineEdit->setText("");

        //pops the text into a message box, in the future the string will be sent to be parsed
        //QMessageBox::information(this, "This will be parsed", ui->lineEdit->text());

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
void MainWindow::dividePressed() {
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
void MainWindow::multiplyPressed() {
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
void MainWindow::addPressed() {
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
void MainWindow::subtractPressed() {
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
