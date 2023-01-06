#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString log = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();

    QMessageBox::information(this,"Podane informacje","Wprowadzono login: "+log+" oraz hasło: "+pass);
    hide();
    LibDialog = new libDialog(this);
    LibDialog->show();


}



void MainWindow::on_pushButton_2_clicked()
{
    hide();
    addaccount = new AddAccount(this);
    addaccount->show();
}

