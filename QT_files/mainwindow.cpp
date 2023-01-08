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

      
        
        vector <Book> books = sq.spis();
        for (int i = 0; i < books.size(); i++) {
            ui->tableWidget_ksiazki->insertRow(ui->tableWidget_ksiazki->rowCount());
            ui->tableWidget_ksiazki->setItem(ui->tableWidget_ksiazki->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(books[i].title)));
            ui->tableWidget_ksiazki->setItem(ui->tableWidget_ksiazki->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(books[i].autor)));
            ui->tableWidget_ksiazki->setItem(ui->tableWidget_ksiazki->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(books[i].gatunek)));
            ui->tableWidget_ksiazki->setItem(ui->tableWidget_ksiazki->rowCount() - 1, 3, new QTableWidgetItem(books[i].liczba_stron));
        }

        vector <User> users = sq.lista_uzytkownikow();
        for (int i = 0; i < users.size(); i++) {
            ui->tableWidget_uzytkownicy->insertRow(ui->tableWidget_uzytkownicy->rowCount());
            ui->tableWidget_uzytkownicy->setItem(ui->tableWidget_uzytkownicy->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(to_string(users[i].id))));
            ui->tableWidget_uzytkownicy->setItem(ui->tableWidget_uzytkownicy->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(users[i].login)));
            ui->tableWidget_uzytkownicy->setItem(ui->tableWidget_uzytkownicy->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(to_string(users[i].num_of_borrowed_books))))   ;

        }

        vector <Borrowed_books> borrowed = sq.borrowed_list();
        for (int i = 0; i < borrowed.size(); i++) {
            ui->tableWidget_wypozyczenia->insertRow(ui->tableWidget_wypozyczenia->rowCount());
            ui->tableWidget_wypozyczenia->setItem(ui->tableWidget_wypozyczenia->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(to_string(borrowed[i].id_uzytkownika))));
            ui->tableWidget_wypozyczenia->setItem(ui->tableWidget_wypozyczenia->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(to_string(borrowed[i].id_ksiazki))));
            ui->tableWidget_wypozyczenia->setItem(ui->tableWidget_wypozyczenia->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(borrowed[i].login)));
            ui->tableWidget_wypozyczenia->setItem(ui->tableWidget_wypozyczenia->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(borrowed[i].tytul)));
            ui->tableWidget_wypozyczenia->setItem(ui->tableWidget_wypozyczenia->rowCount() - 1, 4, new QTableWidgetItem(QString::fromStdString(borrowed[i].data_wypozyczenia)));
            ui->tableWidget_wypozyczenia->setItem(ui->tableWidget_wypozyczenia->rowCount() - 1, 5, new QTableWidgetItem(QString::fromStdString(borrowed[i].data_oddania)));
                 }


    
    
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


