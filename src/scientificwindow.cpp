#include "scientificwindow.h"
#include "ui_scientificwindow.h"

scientificWindow::scientificWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scientificWindow)
{
    ui->setupUi(this);
}

scientificWindow::~scientificWindow()
{
    delete ui;
}
