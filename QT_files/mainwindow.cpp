#include "mainwindow.h"
#include "ui_mainwindow.h"


// 2- main
// 1- rejestracja
// 0 -menu


Mysql_connector sq;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Biblioteka");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_zaloguj_clicked()
{

    QString log = ui->lineEdit_login->text();
    QString pass = ui->lineEdit_haslo->text();

    int id = sq.login(log.toStdString(), pass.toStdString());

    if (id == -2)
        QMessageBox::information(this, "Błąd", "Podano błedne hasło");
    if (id == -1)
        QMessageBox::information(this, "Błąd", "Podano błedne dane");
    if (id >= 0) {
        QMessageBox::information(this, "", "Zalogowano pomyslnie");
        ui->stackedWidget->widget(0)->hide();
        ui->stackedWidget->widget(1)->hide();
        ui->stackedWidget->widget(2)->show();
    }
    // QMessageBox::information(this,"Podane informacje","Wprowadzono login: "+log+" oraz hasło: "+pass);
}


void MainWindow::on_pushButton_zarejestruj_clicked()
{
    ui->stackedWidget->widget(0)->hide();
    ui->stackedWidget->widget(2)->hide();
    ui->stackedWidget->widget(1)->show();
}

void MainWindow::on_pushButton_zaloz_clicked()
{

    QString log = ui->lineEdit_login_2->text();
    QString haslo = ui->lineEdit_haslo_2->text();

    if (log.length() == 0 || haslo.length() == 0) {
        QMessageBox::information(this, "Blad", "Wypelnij puste pole!");
        return;
    }


    int done = sq.create_account(log.toStdString(), haslo.toStdString());
   
    if (done == 1) {
        QMessageBox::information(this, "Sukces", "Pomyslnie zalozono konto");
        ui->stackedWidget->widget(2)->hide();
        ui->stackedWidget->widget(1)->hide();
        ui->stackedWidget->widget(0)->show();
    }
    else if(done == -1){
        QMessageBox::information(this, "BLAD", "Zajety login");
    }
  
   
}
void MainWindow::on_pushButton_anuluj_clicked() {
    ui->stackedWidget->widget(2)->hide();
    ui->stackedWidget->widget(1)->hide();
    ui->stackedWidget->widget(0)->show();
}



void MainWindow::on_pushButton_wyloguj_clicked()
{
    ui->stackedWidget->widget(2)->hide();
    ui->stackedWidget->widget(1)->hide();
    ui->stackedWidget->widget(0)->show();
}

void MainWindow::on_pushButton_sprawdz_clicked()
{
    
}


