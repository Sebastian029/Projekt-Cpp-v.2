#include "mainwindow.h"
#include "ui_mainwindow.h"
Mysql_connector sq;

// 2- main
// 1- rejestracja
// 0 -menu



void MainWindow::init_users() {
    ui->tableWidget_uzytkownicy->setRowCount(0);
    vector <User> users = sq.lista_uzytkownikow();
    for (int i = 0; i < users.size(); i++) {
        ui->tableWidget_uzytkownicy->insertRow(ui->tableWidget_uzytkownicy->rowCount());
        ui->tableWidget_uzytkownicy->setItem(ui->tableWidget_uzytkownicy->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(to_string(users[i].id))));
        ui->tableWidget_uzytkownicy->setItem(ui->tableWidget_uzytkownicy->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(users[i].login)));
        ui->tableWidget_uzytkownicy->setItem(ui->tableWidget_uzytkownicy->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(to_string(users[i].num_of_borrowed_books))));
        ui->tableWidget_uzytkownicy->setItem(ui->tableWidget_uzytkownicy->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(to_string(users[i].nr_telefonu))));
        ui->tableWidget_uzytkownicy->setItem(ui->tableWidget_uzytkownicy->rowCount() - 1, 4, new QTableWidgetItem(QString::fromStdString(users[i].email)));

    }
 
}

void MainWindow::init_books() {
    ui->tableWidget_ksiazki_2->setRowCount(0);
    ui->tableWidget_modyfikacja->setRowCount(0);
    vector <Book> books = sq.spis();
    for (int i = 0; i < books.size(); i++) {
 
        ui->tableWidget_ksiazki_2->insertRow(ui->tableWidget_ksiazki_2->rowCount());
        ui->tableWidget_ksiazki_2->setItem(ui->tableWidget_ksiazki_2->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(to_string(books[i].id))));
        ui->tableWidget_ksiazki_2->setItem(ui->tableWidget_ksiazki_2->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(books[i].title)));
        ui->tableWidget_ksiazki_2->setItem(ui->tableWidget_ksiazki_2->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(books[i].autor)));
        ui->tableWidget_ksiazki_2->setItem(ui->tableWidget_ksiazki_2->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(books[i].gatunek)));
        ui->tableWidget_ksiazki_2->setItem(ui->tableWidget_ksiazki_2->rowCount() - 1, 4, new QTableWidgetItem(QString::fromStdString(to_string(books[i].liczba_stron))));


        ui->tableWidget_modyfikacja->insertRow(ui->tableWidget_modyfikacja->rowCount());
        ui->tableWidget_modyfikacja->setItem(ui->tableWidget_modyfikacja->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(to_string(books[i].id))));
        ui->tableWidget_modyfikacja->setItem(ui->tableWidget_modyfikacja->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(books[i].title)));
        ui->tableWidget_modyfikacja->setItem(ui->tableWidget_modyfikacja->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(books[i].autor)));
        ui->tableWidget_modyfikacja->setItem(ui->tableWidget_modyfikacja->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(books[i].gatunek)));
        ui->tableWidget_modyfikacja->setItem(ui->tableWidget_modyfikacja->rowCount() - 1, 4, new QTableWidgetItem(QString::fromStdString(to_string(books[i].liczba_stron))));
        ui->tableWidget_modyfikacja->setItem(ui->tableWidget_modyfikacja->rowCount() - 1, 5, new QTableWidgetItem(QString::fromStdString(books[i].data_wydania)));
    }

    

    ui->tableWidget_ksiazki_user->setRowCount(0);
    ui->tableWidget_ksiazki_3->setRowCount(0);
    vector <Book> books_user = sq.spis_user();
    for (int i = 0; i < books_user.size(); i++) {

        ui->tableWidget_ksiazki_user->insertRow(ui->tableWidget_ksiazki_user->rowCount());
        ui->tableWidget_ksiazki_user->setItem(ui->tableWidget_ksiazki_user->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(books_user[i].title)));
        ui->tableWidget_ksiazki_user->setItem(ui->tableWidget_ksiazki_user->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(books_user[i].autor)));
        ui->tableWidget_ksiazki_user->setItem(ui->tableWidget_ksiazki_user->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(books_user[i].gatunek)));
        ui->tableWidget_ksiazki_user->setItem(ui->tableWidget_ksiazki_user->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(to_string(books_user[i].liczba_stron))));
        ui->tableWidget_ksiazki_user->setItem(ui->tableWidget_ksiazki_user->rowCount() - 1, 4, new QTableWidgetItem(QString::fromStdString(to_string(books_user[i].count))));


        ui->tableWidget_ksiazki_3->insertRow(ui->tableWidget_ksiazki_3->rowCount());
        ui->tableWidget_ksiazki_3->setItem(ui->tableWidget_ksiazki_3->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(books_user[i].title)));
        ui->tableWidget_ksiazki_3->setItem(ui->tableWidget_ksiazki_3->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(books_user[i].autor)));
        ui->tableWidget_ksiazki_3->setItem(ui->tableWidget_ksiazki_3->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(books_user[i].gatunek)));
        ui->tableWidget_ksiazki_3->setItem(ui->tableWidget_ksiazki_3->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(to_string(books_user[i].liczba_stron))));
        ui->tableWidget_ksiazki_3->setItem(ui->tableWidget_ksiazki_3->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(to_string(books_user[i].count))));
    }

}

void MainWindow::init_borrowed() {
    ui->tableWidget_wypozyczenia->setRowCount(0);
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

void MainWindow::init_oddawanie(){

    ui->comboBox_oddawanie->clear();
    vector <Book> books = sq.wypozyczone();
    QStringList q_list;
    for (int i = 0; i < books.size(); i++)
        q_list.push_back(QString::fromStdString(books[i].title));

    ui->comboBox_oddawanie->addItems(q_list);
    

}

void MainWindow::init_spis() {
    ui->tableWidget_wypozyczanie->setRowCount(0);
    vector <Book> books = sq.spis_dostepnych();
    for (int i = 0; i < books.size(); i++) {
        ui->tableWidget_wypozyczanie->insertRow(ui->tableWidget_wypozyczanie->rowCount());
        ui->tableWidget_wypozyczanie->setItem(ui->tableWidget_wypozyczanie->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(books[i].title)));
        ui->tableWidget_wypozyczanie->setItem(ui->tableWidget_wypozyczanie->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(books[i].autor)));
        ui->tableWidget_wypozyczanie->setItem(ui->tableWidget_wypozyczanie->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(books[i].gatunek)));
        ui->tableWidget_wypozyczanie->setItem(ui->tableWidget_wypozyczanie->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(to_string(books[i].liczba_stron))));
        ui->tableWidget_wypozyczanie->setItem(ui->tableWidget_wypozyczanie->rowCount() - 1, 4, new QTableWidgetItem(QString::fromStdString(books[i].data_wydania)));

        
    }

}

void MainWindow::init_daty() {
    
    ui->tableWidget_daty->setRowCount(0);
    vector <Daty_wypozyczen> dates = sq.daty_wypozyczen();
    for (int i = 0; i < dates.size(); i++) {
        ui->tableWidget_daty->insertRow(ui->tableWidget_daty->rowCount());
        ui->tableWidget_daty->setItem(ui->tableWidget_daty->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(dates[i].tytul)));
        ui->tableWidget_daty->setItem(ui->tableWidget_daty->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(dates[i].d_wypozyczenia)));
        ui->tableWidget_daty->setItem(ui->tableWidget_daty->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(dates[i].d_oddania)));

        QTextCharFormat tmp;
        tmp.setBackground(QColor(235, 215, 145));

        QString st = QString::fromStdString(dates[i].d_oddania);
        QDate calendar_date = QDate::fromString(st, "dd.MM.yyyy");
         ui->calendarWidget->setDateTextFormat(calendar_date, tmp);
        
      
    }

    
   

}

void MainWindow::init_spoznione() {
    ui->tableWidget_spoznione->setRowCount(0);
    vector <Opoznione> op = sq.spoznienie();
    for (int i = 0; i < op.size(); i++) {
        ui->tableWidget_spoznione->insertRow(ui->tableWidget_spoznione->rowCount());
        ui->tableWidget_spoznione->setItem(ui->tableWidget_spoznione->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(op[i].login)));
        ui->tableWidget_spoznione->setItem(ui->tableWidget_spoznione->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(op[i].tytul)));
        ui->tableWidget_spoznione->setItem(ui->tableWidget_spoznione->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(op[i].data_oddania)));

    }

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   

    init_users();
    init_books();
    init_borrowed();
    init_spis();
    init_spoznione();
  
     ui->tableWidget_wypozyczenia->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
     ui->comboBox_gatunki->setEnabled(0);


     connect(ui->comboBox_selekcja, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(sig(const QString&)));

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

        if (sq.is_admin()) {
            ui->stackedWidget->widget(3)->show();
            ui->stackedWidget->setCurrentWidget(ui->stackedWidget->widget(3));
            ui->stackedWidget->widget(2)->hide();
            ui->label_zalogowano_login_4->setText(log);
        }
        else {
            ui->stackedWidget->widget(3)->hide();
            ui->stackedWidget->setCurrentWidget(ui->stackedWidget->widget(2));
            ui->stackedWidget->widget(2)->show();
            ui->label_zalogowano_login->setText(log);
        }
            



        ui->stackedWidget->widget(0)->hide();
        ui->stackedWidget->widget(1)->hide();
        
        
       
        ui->lineEdit_login->clear();
        ui->lineEdit_haslo->clear();
        
        init_users();
        init_books();
        init_borrowed();
        init_oddawanie();
        init_daty();
       

        
        
        
        

    }
    // QMessageBox::information(this,"Podane informacje","Wprowadzono login: "+log+" oraz hasło: "+pass);
}


void MainWindow::on_pushButton_zarejestruj_clicked()
{
    ui->stackedWidget->widget(0)->hide();
    ui->stackedWidget->widget(2)->hide();
    ui->stackedWidget->widget(3)->hide();
    ui->stackedWidget->widget(1)->show();
    ui->stackedWidget->setCurrentWidget(ui->stackedWidget->widget(1));
}

void MainWindow::on_pushButton_zaloz_clicked()
{

    QString log = ui->lineEdit_login_2->text();
    QString haslo = ui->lineEdit_haslo_2->text();
    QString email = ui->lineEdit_email_2->text();
    QString nr_tel = ui->lineEdit_telefon_2->text();
  

    if (log.length() == 0 || haslo.length() == 0 ||  email.length()==0  || nr_tel.length()==0) {
        QMessageBox::information(this, "Blad", "Wypelnij puste pole!");
        return;
    }

    try {
        stoll(nr_tel.toStdString());
        }
        catch (...) {
            QMessageBox::information(this, "Blad", "Bledny numer telefonu");
            return;
    }

    if (nr_tel.length() < 9) {
        QMessageBox::information(this, "Blad", "Zbyt krotki nr telefonu");
        return;
    }
    if (nr_tel.length() >11) {
        QMessageBox::information(this, "Blad", "Za dlugi nr telefonu");
        return;
    }



    int done = sq.create_account(log.toStdString(), haslo.toStdString(), email.toStdString(), stoll(nr_tel.toStdString()));
   
    if (done == 1) {
        QMessageBox::information(this, "Sukces", "Pomyslnie zalozono konto");
        ui->stackedWidget->widget(2)->hide();
        ui->stackedWidget->widget(1)->hide();
        ui->stackedWidget->widget(3)->hide();
        ui->stackedWidget->widget(0)->show();
        ui->stackedWidget->setCurrentWidget(ui->stackedWidget->widget(0));

        ui->lineEdit_login_2->clear();
        ui->lineEdit_haslo_2->clear(); 
        ui->lineEdit_email_2->clear(); 
        ui->lineEdit_telefon_2->clear();


    }
    else if(done == -1){
        QMessageBox::information(this, "BLAD", "Zajety login");
    }
  
   
}

void MainWindow::on_pushButton_pokaz_haslo_pressed() {

    ui->lineEdit_haslo_2->setEchoMode(QLineEdit::Normal);

}
void MainWindow::on_pushButton_pokaz_haslo_released() {

    ui->lineEdit_haslo_2->setEchoMode(QLineEdit::Password);

}
void MainWindow::on_pushButton_anuluj_clicked() {
    ui->stackedWidget->widget(2)->hide();
    ui->stackedWidget->widget(1)->hide();
    ui->stackedWidget->widget(3)->hide();
    ui->stackedWidget->widget(0)->show();
    ui->stackedWidget->setCurrentWidget(ui->stackedWidget->widget(0));
}

void MainWindow::on_pushButton_wyloguj_clicked()
{
    ui->stackedWidget->widget(2)->hide();
    ui->stackedWidget->widget(1)->hide();
    ui->stackedWidget->widget(3)->hide();
    ui->stackedWidget->widget(0)->show();
    ui->stackedWidget->setCurrentWidget(ui->stackedWidget->widget(0));
}

void MainWindow::on_pushButton_wyloguj_4_clicked()
{
    ui->stackedWidget->widget(2)->hide();
    ui->stackedWidget->widget(1)->hide();
    ui->stackedWidget->widget(3)->hide();
    ui->stackedWidget->widget(0)->show();
    ui->stackedWidget->setCurrentWidget(ui->stackedWidget->widget(0));
}


void MainWindow::on_pushButton_oddawanie_clicked()
{
    QString book_title = ui->comboBox_oddawanie->currentText();
    if (book_title.length() == 0) {
        QMessageBox::information(this, "", "Brak ksiazek do oddania");
        return;
    }

    sq.return_book(book_title.toStdString());
    QMessageBox::information(this, "Sukces", "Zwrocono ksiazke pt. " + book_title);
    init_borrowed();
    init_oddawanie();
    init_spis();
    init_users();
    init_daty();

}


void MainWindow::on_tableWidget_wypozyczanie_cellClicked(int row, int column)
{
    QString tmp = ui->tableWidget_wypozyczanie->item(row, 0)->text();
    
    for(int i = 0; i< ui->tableWidget_wybrane_ksiazki->rowCount(); i++) {
        if (tmp == ui->tableWidget_wybrane_ksiazki->item(i, 0)->text()) {
            QMessageBox::information(this, "Blad", "Ksiazka o wybranym tytule zostala juz dodana do listy");
            return;
        }
    }

    ui->tableWidget_wybrane_ksiazki->insertRow(ui->tableWidget_wybrane_ksiazki->rowCount());
    ui->tableWidget_wybrane_ksiazki->setItem(ui->tableWidget_wybrane_ksiazki->rowCount() - 1, 0, new QTableWidgetItem(tmp));
   
}

void MainWindow::on_tableWidget_wybrane_ksiazki_cellClicked(int row, int column)
{
    ui->tableWidget_wybrane_ksiazki->removeRow(row);

}

void MainWindow::on_pushButton_wypozycz_clicked()
{
    
    for (int i = 0; i < ui->tableWidget_wybrane_ksiazki->rowCount(); i++) {
        sq.borrow_book(ui->tableWidget_wybrane_ksiazki->item(i, 0)->text().toStdString());
        //QMessageBox::information(this, "Blad", (ui->tableWidget_wybrane_ksiazki->item(i, 0)->text()));
    }
    
    if(ui->tableWidget_wybrane_ksiazki->rowCount()==0)
        QMessageBox::information(this, "Blad", "Nie wybrano ksiazek do wypozyczenia");
    else
         QMessageBox::information(this, "Sukces", "Pomyslnie wypozyczono wybrane ksiazki");
    ui->tableWidget_wybrane_ksiazki->setRowCount(0);
    init_spis();
    init_oddawanie();
    init_borrowed();
    init_daty();
    init_books();

    


}

void MainWindow::on_pushButton_szukaj_clicked() {

    QString kategoria = ui->comboBox_selekcja->currentText();
    QString wybor = ui->lineEdit_selekcja->text();

    if (!ui->lineEdit_selekcja->isEnabled()) {
        wybor = ui->comboBox_gatunki->currentText();
    }
  
    ui->tableWidget_wypozyczanie->setRowCount(0);
    vector <Book> books = sq.spis_wybranych(kategoria.toStdString(), wybor.toStdString());
    for (int i = 0; i < books.size(); i++) {
        ui->tableWidget_wypozyczanie->insertRow(ui->tableWidget_wypozyczanie->rowCount());
        ui->tableWidget_wypozyczanie->setItem(ui->tableWidget_wypozyczanie->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(books[i].title)));
        ui->tableWidget_wypozyczanie->setItem(ui->tableWidget_wypozyczanie->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(books[i].autor)));
        ui->tableWidget_wypozyczanie->setItem(ui->tableWidget_wypozyczanie->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(books[i].gatunek)));
        ui->tableWidget_wypozyczanie->setItem(ui->tableWidget_wypozyczanie->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(to_string(books[i].liczba_stron))));
        ui->tableWidget_wypozyczanie->setItem(ui->tableWidget_wypozyczanie->rowCount() - 1, 4, new QTableWidgetItem(QString::fromStdString(books[i].data_wydania)));

    }
    
    
}

void MainWindow::on_pushButton_filtry_clicked() {
    init_spis();
    ui->lineEdit_selekcja->clear();
    ui->comboBox_gatunki->setEnabled(0);
    ui->lineEdit_selekcja->setEnabled(1);
}

void MainWindow::on_pushButton_D_dodaj_clicked() {
  
    QString tytul = ui->lineEdit_D_tytul->text();
    QString autor = ui->lineEdit_D_autor->text();
    QString gatunek = ui->lineEdit_D_gatunek->text();
    int liczba_stron = ui->spinBox_D_strony->value();
    int num = ui->spinBox_D_ilosc->value();
    QDate data = ui->dateEdit_D_data->date();
    
    if (tytul.length() == 0) {
        QMessageBox::warning(this, "Blad", "Nie dodano tytulu ksiazki");
        return;
    }
    
    int delete_date = 0;
    if(ui->checkBox_D_data->isChecked())
        delete_date =1;
    else {
        delete_date = 0;
    }
    for (int i = 0; i < num; i++) {
        sq.add_book(tytul.toStdString(), autor.toStdString(), gatunek.toStdString(), liczba_stron, data.toString("dd.MM.yyyy").toStdString(), delete_date);
    }
    QMessageBox::information(this, "Sukces", "Pomyslnie dodano nowa ksiazke");

    init_books();
    ui->lineEdit_D_tytul->clear();
    ui->lineEdit_D_autor->clear();
    ui->lineEdit_D_gatunek->clear();
    ui->spinBox_D_strony->clear();
    ui->dateEdit_D_data->clear();
    ui->spinBox_D_ilosc->clear();

}

void MainWindow::on_checkBox_D_data_clicked() {

    
    if (ui->checkBox_D_data->isChecked()) {
        ui->dateEdit_D_data->setEnabled(false);
    }
    else {
        ui->dateEdit_D_data->setEnabled(true);
    }

}

void MainWindow::on_pushButton_przedluz_clicked() {

    QString book_title = ui->comboBox_oddawanie->currentText();
    if (book_title.length() == 0) {
        QMessageBox::information(this, "", "Brak ksiazek do przedluzenia");
        return;
    }
    int done = sq.przedluz(book_title.toStdString());

    if(done==-1)
        QMessageBox::information(this, "Blad", "Przedluzenie tej ksiazki mozliwe jest tylko jeden raz.");
    if(done==1)
        QMessageBox::information(this, "Sukces", "Przedluzono wypozyczenie o 2 tygodnie");

    init_daty();
}

void MainWindow::on_pushButton_modyfikuj_clicked() {

    vector <Book> books;
    
    for (int i = 0; i < ui->tableWidget_modyfikacja->rowCount(); i++) {
        Book book;
       
        book.id = stoi(ui->tableWidget_modyfikacja->item(i, 0)->text().toStdString());
        book.title =  ui->tableWidget_modyfikacja->item(i, 1)->text().toStdString();
        book.autor =  ui->tableWidget_modyfikacja->item(i, 2)->text().toStdString();
        book.gatunek =  ui->tableWidget_modyfikacja->item(i, 3)->text().toStdString();
        book.liczba_stron = stoi(ui->tableWidget_modyfikacja->item(i, 4)->text().toStdString());
        book.data_wydania =  ui->tableWidget_modyfikacja->item(i, 5)->text().toStdString();

        books.push_back(book);
    }
    
    sq.modify_books(books);
}

void MainWindow::on_pushButton_usun_zmiany_clicked() {
    init_books(); 
}

void MainWindow::on_pushButton_del_id_clicked() {
    int id = ui->spinBox_del_id->value();
    sq.delete_book(id);
    init_books();

}

void MainWindow::sig(const QString&){
    vector <string> gatunki = sq.get_gatunki();
    
    QString wybor = ui->comboBox_selekcja->currentText();

    if (wybor.toStdString() != "Gatunek") {
        ui->comboBox_gatunki->setEnabled(0);
        ui->lineEdit_selekcja->setEnabled(1);
        return;
     }
    ui->comboBox_gatunki->setEnabled(1);
    ui->lineEdit_selekcja->setEnabled(0);

    if (ui->comboBox_gatunki->count() == 0) {
        for (int i = 0; i < gatunki.size(); i++)
            ui->comboBox_gatunki->addItem(QString::fromStdString(gatunki[i]));
    }

}