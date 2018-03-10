#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scientificwindow.h"

//#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    //connect(ui->pushButton_decimal,SIGNAL(released()),this, SLOT(digitPressed()));

    connect(ui->pushButton_clear,SIGNAL(released()),this,SLOT(clearPressed()));

    connect(ui->pushButton_back,SIGNAL(released()),this,SLOT(backPressed()));

    connect(ui->pushButton_sciMode,SIGNAL(released()),this,SLOT(sciModePressed()));

    connect(ui->pushButton_up,SIGNAL(released()),this,SLOT(upPressed()));

    connect(ui->pushButton_down,SIGNAL(released()),this,SLOT(downPressed()));

    connect(ui->pushButton_equals,SIGNAL(released()),this,SLOT(equalsPressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitPressed() {
    //qDebug() << "test";

    QPushButton *button = (QPushButton*)sender();

    double labelNumber = (ui->label_screen->text() + button->text()).toDouble();

    QString labelText = QString::number(labelNumber,'g',15); // 15 is the current double precision

    ui->label_screen->setText(labelText);
}

void MainWindow::clearPressed() {
    QString currentText = ui->label_screen->text();

    //TO DO:
    // add functionality to save what was currently on the screen before clearing it

    ui->label_screen->setText((QString)"");

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

void MainWindow::upPressed() {
    //check if end of the list
    mem.it--;
    ui->label_screen->setText((QString)*mem.it);
}

void MainWindow::downPressed() {
    //check if end of te list

    mem.it++;
    ui->label_screen->setText((QString)*mem.it);
    //how to go back to being able to input values???
}

void MainWindow::equalsPressed() {
    QString currentText = ui->label_screen->text();
    //if memory is empty add blank memory spot
    /*if (mem.memory.size() < 1) {
        QString emptyText = (QString)"";
        mem.memory.push_back(emptyText);
    }*/
    //adds to memory
    mem.memory.push_back(currentText);
    mem.it = mem.memory.end();
    //mem.updateIterators();
    ui->label_screen->setText((QString)"");
}
