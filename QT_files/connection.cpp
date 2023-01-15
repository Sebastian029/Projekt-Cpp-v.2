#include <iostream>
#include <vector>
#include <list>
#include "connection.h"
#include "structures.h"
using namespace std;

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>



const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "mypass";

Mysql_connector::~Mysql_connector() {
    delete pstmt;
    delete stmt;
    delete con;
    
}


Mysql_connector::Mysql_connector() {

    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }


    //please create database "quickstartdb" ahead of time
    con->setSchema("quickstartdb");
    /*
    stmt = con->createStatement();
    stmt->execute("DROP TABLE IF EXISTS Wypozyczenia");
    stmt->execute("DROP TABLE IF EXISTS Ksiazki");
    stmt->execute("DROP TABLE IF EXISTS Uzytkownicy");
    cout << "Finished dropping table (if existed)" << endl;

    stmt->execute("CREATE TABLE Uzytkownicy (id_uzytkownika INT AUTO_INCREMENT, login VARCHAR(30), haslo VARCHAR(30), email VARCHAR(30), nr_telefonu INTEGER, num_of_borrowed_books INTEGER, admin INTEGER, PRIMARY KEY(id_uzytkownika));");
    stmt->execute("CREATE TABLE Ksiazki (id_ksiazki INT AUTO_INCREMENT, enable BOOLEAN, tytul VARCHAR(30), autor VARCHAR(30), gatunek VARCHAR(20), data_wydania DATE, liczba_stron INT, PRIMARY KEY(id_ksiazki));");
    stmt->execute("CREATE TABLE Wypozyczenia (id_wypozyczenia INT AUTO_INCREMENT,id_uzytkownika INT, id_ksiazki INT UNIQUE, data_wypozyczenia VARCHAR(20), data_oddania VARCHAR(20), PRIMARY KEY(id_wypozyczenia), FOREIGN KEY (id_uzytkownika) REFERENCES Uzytkownicy(id_uzytkownika), FOREIGN KEY (id_ksiazki) REFERENCES Ksiazki(id_ksiazki));");

    cout << "Finished creating tables" << endl;
    //stmt->execute("INSERT INTO Uzytkownicy (login, haslo, num_of_borrowed_books) VALUES ('mylogin', 'mypasswordddd', 1);");



    

    stmt->execute("INSERT INTO Uzytkownicy (login, haslo, num_of_borrowed_books, admin) VALUES ('qwe', 'asd', 0, 0);");
    stmt->execute("INSERT INTO Uzytkownicy (login, haslo, num_of_borrowed_books, admin) VALUES ('mycos', 'mypasads', 0, 0);");
    stmt->execute("INSERT INTO Uzytkownicy (login, haslo, num_of_borrowed_books, admin) VALUES ('LOGIN', 'HASLO', 1, 1);");

    stmt->execute("INSERT INTO Ksiazki (tytul,enable) VALUES ('TytulKsiazki',0);");
    stmt->execute("INSERT INTO Ksiazki (tytul,enable) VALUE ('TytulKsiazki1',0);");
    stmt->execute("INSERT INTO Ksiazki (tytul,enable) VALUE ('TytulKsiazki112',1);");
    stmt->execute("INSERT INTO Ksiazki (tytul,enable) VALUE ('TytulKsiazki12',1);");
    stmt->execute("INSERT INTO Ksiazki (tytul,enable) VALUE ('TytulKsi12',1);");


    stmt->execute("INSERT INTO Wypozyczenia (id_uzytkownika, id_ksiazki, data_oddania) VALUES (1, 2, date_format(NOW(), '%d.%m.%Y'));");
    stmt->execute("INSERT INTO Wypozyczenia (id_uzytkownika, id_ksiazki) VALUES (1, 1);");
    stmt->execute("INSERT INTO Wypozyczenia (id_uzytkownika, id_ksiazki) VALUES (2, 3);");
    stmt->execute("INSERT INTO Wypozyczenia (id_uzytkownika, id_ksiazki) VALUES (3, 4);");

    

    */
}

void Mysql_connector::add_book(string tytul, string autor, string gatunek,  int liczba_stron, string data_wydania, int delete_date) {

    try {
        if (liczba_stron > 0) {
            sql::PreparedStatement* pstmt;
            pstmt = con->prepareStatement("INSERT INTO Ksiazki(tytul, autor, gatunek, data_wydania, liczba_stron, enable) VALUES(?,?,?,?,?,1)");
            pstmt->setString(1, tytul);
            pstmt->setString(2, autor);
            pstmt->setString(3, gatunek);
            pstmt->setString(4, data_wydania);
            if (delete_date)
                pstmt->setNull(4, 0);
            pstmt->setInt(5, liczba_stron);
            pstmt->execute();

        }
        else {
            sql::PreparedStatement* pstmt;
            pstmt = con->prepareStatement("INSERT INTO Ksiazki(tytul, autor, gatunek, data_wydania, enable) VALUES(?,?,?,?,1)");
            pstmt->setString(1, tytul);
            pstmt->setString(2, autor);
            pstmt->setString(3, gatunek);
            pstmt->setString(4, data_wydania);
            if (delete_date)
                pstmt->setNull(4, 0);
            pstmt->execute();
        }
    }
    catch (...) {}

}

int Mysql_connector::login(string login, string haslo) {
    sql::PreparedStatement* pstmt;
    pstmt = con->prepareStatement("SELECT id_uzytkownika, login, haslo FROM Uzytkownicy;");
    result = pstmt->executeQuery();
    while (result->next()) {
        // printf("Reading from table=(%d, %s, %s)\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str());
        if (login == result->getString(2).c_str()) {
            if (haslo == result->getString(3).c_str()) {
                cout << "zalogowano" << endl;
                this->id = result->getInt(1);
                return result->getInt(1);
            }
            cout << "Bledne haslo" << endl;
            return -2;
        }
    }
    cout << "Bledne dane" << endl;
    return -1;

    //delete pstmt;
}

vector <Book>  Mysql_connector::spis() {

    vector <Book> books;
    pstmt = con->prepareStatement("SELECT id_ksiazki, tytul, autor, data_wydania, gatunek, liczba_stron FROM Ksiazki;");
    result = pstmt->executeQuery();
    while (result->next()) {
        //printf("Reading from table=(%d, %s, %s, %d)\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), result->getInt(4));
        Book temp;
        temp.id = -1;
        temp.id = result->getInt(1);

        temp.title = "";
        temp.title = result->getString(2).c_str();

        temp.autor = "";
        temp.autor = result->getString(3).c_str();

        temp.data_wydania = "";
        temp.data_wydania = result->getString(4).c_str();

        temp.gatunek = "";
        temp.gatunek = result->getString(5).c_str();

        temp.liczba_stron = 0;
        temp.liczba_stron = result->getInt(6);
        books.push_back(temp);
    }

    return books;
};

vector <User>  Mysql_connector::lista_uzytkownikow() {

    vector<User> users;
    pstmt = con->prepareStatement("SELECT id_uzytkownika, login, num_of_borrowed_books, nr_telefonu, email FROM Uzytkownicy;");
    result = pstmt->executeQuery();
    while (result->next()) {
        //printf("Reading from table=(%d, %s, %s, %d)\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), result->getInt(4));
        User temp;
        temp.id = -1;
        temp.id = result->getInt(1);

        temp.login = "";
        temp.login = result->getString(2).c_str();
        
        temp.num_of_borrowed_books = -1;
        temp.num_of_borrowed_books = result->getInt(3);

        temp.nr_telefonu = -1;
        temp.nr_telefonu = result->getInt(4);


        temp.email = "";
        temp.email = result->getString(5).c_str();

        users.push_back(temp);
    }

    return users;
};

int Mysql_connector::create_account(string login, string password, string email, int nr_tel) {
    sql::PreparedStatement* pstmt;
    list <string> logins;
    pstmt = con->prepareStatement("SELECT login FROM Uzytkownicy;");
    result = pstmt->executeQuery();
    while (result->next()) {
        if (result->getString(1).c_str() == login) {
            cout << "Zajety login";
            return -1;
        }
    }


    pstmt = con->prepareStatement("INSERT INTO Uzytkownicy(login, haslo, email, nr_telefonu, num_of_borrowed_books, admin) VALUES(?,?,?,?,?,?)");
    pstmt->setString(1, login);
    pstmt->setString(2, password);
    pstmt->setString(3, email);
    pstmt->setInt(4, nr_tel);
    pstmt->setInt(5, 0);
    pstmt->setInt(6, 0);
    pstmt->execute();

    cout << "Dodano uzytkownika";
    return 1;
}

vector <Book>  Mysql_connector::wypozyczone() {

    vector<Book> books;
    if (this->id < 0) {
        cout << "Nie zalogwany uzytkownik";
        return books;
    }


    pstmt = con->prepareStatement("SELECT ksiazki.id_ksiazki, ksiazki.tytul FROM ksiazki, Wypozyczenia, Uzytkownicy WHERE uzytkownicy.id_uzytkownika = wypozyczenia.id_uzytkownika AND wypozyczenia.id_ksiazki = ksiazki.id_ksiazki AND uzytkownicy.id_uzytkownika=?;");
    pstmt->setInt(1, this->id);
    result = pstmt->executeQuery();
    while (result->next()) {
        Book temp;
        temp.id = -1;
        temp.id = result->getInt(1);

        temp.title = "";
        temp.title = result->getString(2).c_str();
        books.push_back(temp);
    }

    return books;
};

int Mysql_connector::borrow_book(string title) {
    int book_id = -1;
    //odnalezienie ksiazki
    try {
        pstmt = con->prepareStatement("SELECT id_ksiazki FROM ksiazki WHERE tytul=? AND enable=1 LIMIT 1;");
        pstmt->setString(1, title);
        result = pstmt->executeQuery();
        result->next();
        book_id = result->getInt(1);
    }
    catch (...) {
        cout << "Brak dostepnosci podanej ksiazki";
        return 0;
    }
   

    // zmiana dostepsnosci ksiazki
    pstmt = con->prepareStatement("UPDATE ksiazki SET enable=0 WHERE id_ksiazki=?;");
    pstmt->setInt(1, book_id);
    pstmt->executeQuery();

    
    // dodanie do wypozyczen
    pstmt = con->prepareStatement("INSERT INTO wypozyczenia (id_uzytkownika, id_ksiazki, data_wypozyczenia, data_oddania, przedluzenie) VALUES (?, ?, date_format(NOW(), '%d.%m.%Y'), date_format(DATE_ADD(NOW(), INTERVAL 1 MONTH), '%d.%m.%Y'), 0);");
    pstmt->setInt(1, this->id);
    pstmt->setInt(2, book_id);
    pstmt->executeQuery();
 
    // borrowed books + 1
    pstmt = con->prepareStatement("UPDATE uzytkownicy SET num_of_borrowed_books = num_of_borrowed_books + 1 WHERE id_uzytkownika = ?;");
    pstmt->setInt(1, this->id);
    pstmt->executeQuery();


    return 1;
}

bool Mysql_connector::return_book(string title) {
    int book_id = -1;
    
    //odnalezienie ksiazki
    try {
        pstmt = con->prepareStatement("SELECT ksiazki.id_ksiazki FROM ksiazki, wypozyczenia WHERE enable=0 AND tytul=? AND id_uzytkownika=? AND ksiazki.id_ksiazki=wypozyczenia.id_ksiazki LIMIT 1;");
        pstmt->setString(1, title);
        pstmt->setInt(2, this->id);
        result = pstmt->executeQuery();
        result->next();
        book_id = result->getInt(1);
    }
    catch (...) {
        cout << "Nie odnaleziono ksiazki";
        return 0;
    }

    // zmiana dostepsnosci ksiazki
    pstmt = con->prepareStatement("UPDATE ksiazki SET enable=1 WHERE id_ksiazki=? LIMIT 1;");
    pstmt->setInt(1, book_id);
    pstmt->executeQuery();

    // usuniecie wypozyczen
    pstmt = con->prepareStatement("DELETE FROM wypozyczenia WHERE wypozyczenia.id_ksiazki=? LIMIT 1;");
    pstmt->setInt(1, book_id);
    pstmt->executeQuery();

    pstmt = con->prepareStatement("UPDATE uzytkownicy SET num_of_borrowed_books = num_of_borrowed_books - 1 WHERE id_uzytkownika = ?");
    pstmt->setInt(1, this->id);
    pstmt->executeQuery();

    return 1;
}

vector <Borrowed_books> Mysql_connector::borrowed_list()     {
    
    vector <Borrowed_books> borrowed;

    pstmt = con->prepareStatement("SELECT uzytkownicy.id_uzytkownika, ksiazki.id_ksiazki, login, tytul, data_wypozyczenia, data_oddania FROM ksiazki, uzytkownicy, wypozyczenia WHERE wypozyczenia.id_uzytkownika = uzytkownicy.id_uzytkownika AND wypozyczenia.id_ksiazki = ksiazki.id_ksiazki;");
    result = pstmt->executeQuery();

    while (result->next()) {
        Borrowed_books item;

        item.id_uzytkownika = -1;
        item.id_uzytkownika = result->getInt(1);

        item.id_ksiazki = -1;
        item.id_ksiazki = result->getInt(2);

        item.login = "";
        item.login = result->getString(3).c_str();

        item.tytul = "";
        item.tytul = result->getString(4).c_str();

        item.data_wypozyczenia = "";
        item.data_wypozyczenia = result->getString(5).c_str();

        item.data_oddania = "";
        item.data_oddania = result->getString(6).c_str();

        borrowed.push_back(item);
    }

    return borrowed;

}

vector <Book>  Mysql_connector::spis_dostepnych() {

    vector <Book> books;
    pstmt = con->prepareStatement("SELECT DISTINCT tytul, autor, data_wydania, gatunek, liczba_stron FROM Ksiazki WHERE enable =1;");
    result = pstmt->executeQuery();
    while (result->next()) {
        //printf("Reading from table=(%d, %s, %s, %d)\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), result->getInt(4));
        Book temp;
     
        temp.title = "";
        temp.title = result->getString(1).c_str();

        temp.autor = "";
        temp.autor = result->getString(2).c_str();

        temp.data_wydania = "";
        temp.data_wydania = result->getString(3).c_str();

        temp.gatunek = "";
        temp.gatunek = result->getString(4).c_str();

        temp.liczba_stron = 0;
        temp.liczba_stron = result->getInt(5);
        
        books.push_back(temp);
    }




    return books;

}

vector <Book>  Mysql_connector::spis_wybranych(string kategoria, string wybor){
    vector <Book> books;

    if (kategoria == "Tytul") {
        pstmt = con->prepareStatement("SELECT DISTINCT tytul, autor, gatunek, liczba_stron, data_wydania FROM Ksiazki WHERE enable = 1 AND tytul=?;");
        pstmt->setString(1, wybor);
        result = pstmt->executeQuery();
        while (result->next()) {
            Book temp;
          
            temp.title = "";
            temp.title = result->getString(1).c_str();

            temp.autor = "";
            temp.autor = result->getString(2).c_str();

            temp.gatunek = "";
            temp.gatunek = result->getString(3).c_str();

            temp.liczba_stron = 0;
            temp.liczba_stron = result->getInt(4);


            temp.data_wydania = "";
            temp.data_wydania = result->getString(5).c_str();

            books.push_back(temp);
        }
    }
    else if (kategoria == "Autor") {
        pstmt = con->prepareStatement("SELECT DISTINCT tytul, autor, gatunek, liczba_stron, data_wydania FROM Ksiazki WHERE enable = 1 AND autor=?;");
        pstmt->setString(1, wybor);
        result = pstmt->executeQuery();
        while (result->next()) {
            Book temp;
       

            temp.title = "";
            temp.title = result->getString(1).c_str();

            temp.autor = "";
            temp.autor = result->getString(2).c_str();

            temp.gatunek = "";
            temp.gatunek = result->getString(3).c_str();

            temp.liczba_stron = 0;
            temp.liczba_stron = result->getInt(4);


            temp.data_wydania = "";
            temp.data_wydania = result->getString(5).c_str();

            books.push_back(temp);
        }
    }
    else if (kategoria == "Gatunek") {
        pstmt = con->prepareStatement("SELECT DISTINCT tytul, autor, gatunek, liczba_stron, data_wydania FROM Ksiazki WHERE enable = 1 AND gatunek=?;");
        pstmt->setString(1, wybor);
        result = pstmt->executeQuery();
        while (result->next()) {
            Book temp;
  
            temp.title = "";
            temp.title = result->getString(1).c_str();

            temp.autor = "";
            temp.autor = result->getString(2).c_str();

            temp.gatunek = "";
            temp.gatunek = result->getString(3).c_str();

            temp.liczba_stron = 0;
            temp.liczba_stron = result->getInt(4);


            temp.data_wydania = "";
            temp.data_wydania = result->getString(5).c_str();

            books.push_back(temp);
        }
    }

    return books;
}

int Mysql_connector::is_admin() {
  
    pstmt = con->prepareStatement("SELECT admin FROM uzytkownicy WHERE id_uzytkownika=?;");
    pstmt->setInt(1, this->id);
    result = pstmt->executeQuery();
    result->next();
    int admin = result->getInt(1);

    return admin;
}

vector <Daty_wypozyczen> Mysql_connector::daty_wypozyczen() {

    vector <Daty_wypozyczen> dates;
    pstmt = con->prepareStatement("SELECT tytul, data_wypozyczenia, data_oddania FROM wypozyczenia, ksiazki, uzytkownicy WHERE wypozyczenia.id_uzytkownika= uzytkownicy.id_uzytkownika AND wypozyczenia.id_ksiazki = ksiazki.id_ksiazki  AND uzytkownicy.id_uzytkownika=?;");
    pstmt->setInt(1, this->id);
    result = pstmt->executeQuery();
    while (result->next()) {
        Daty_wypozyczen date;
        
        date.tytul = result->getString(1).c_str();
        date.d_wypozyczenia = result->getString(2).c_str();
        date.d_oddania = result->getString(3).c_str();

        dates.push_back(date);
    }

    return dates;
}


int Mysql_connector::przedluz(string title) {
        pstmt = con->prepareStatement("SELECT przedluzenie FROM wypozyczenia, uzytkownicy, ksiazki WHERE wypozyczenia.id_uzytkownika = uzytkownicy.id_uzytkownika AND wypozyczenia.id_ksiazki = ksiazki.id_ksiazki AND ksiazki.tytul = ? AND uzytkownicy.id_uzytkownika = ? LIMIT 1;");
        pstmt->setString(1, title);
        pstmt->setInt(2, this->id);
        result = pstmt->executeQuery();
        result->next();
        int enable = result->getInt(1);
        

        if (enable > 0)
            return -1;


        pstmt = con->prepareStatement("UPDATE wypozyczenia, uzytkownicy, ksiazki SET przedluzenie = 1 WHERE wypozyczenia.id_uzytkownika = uzytkownicy.id_uzytkownika AND wypozyczenia.id_ksiazki= ksiazki.id_ksiazki AND ksiazki.tytul = ? AND uzytkownicy.id_uzytkownika = ? LIMIT 1;");
        pstmt->setString(1, title);
        pstmt->setInt(2, this->id);
        result = pstmt->executeQuery();

        pstmt = con->prepareStatement("UPDATE Wypozyczenia left join ksiazki on wypozyczenia.id_ksiazki = ksiazki.id_ksiazki set data_oddania = date_format(DATE_ADD(date_format(str_to_date(data_oddania, '%d.%m.%Y'), '%Y-%m-%d'), INTERVAL 2 WEEK), '%d.%m.%Y') WHERE ksiazki.tytul = ? AND wypozyczenia.id_uzytkownika = ? LIMIT 1; ");
        pstmt->setString(1, title);
        pstmt->setInt(2, this->id);
        result = pstmt->executeQuery();
        
        return 1;


}


vector <Book> Mysql_connector::spis_user() {
    vector <Book> books;
    pstmt = con->prepareStatement("select distinct(tytul), autor, gatunek,data_wydania, liczba_stron, cnt from ksiazki left join(select tytul ty, count(tytul) cnt from ksiazki WHERE enable = 1  group by tytul)AS t on tytul=ty;");
    result = pstmt->executeQuery();
    while (result->next()) {
        //printf("Reading from table=(%d, %s, %s, %d)\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), result->getInt(4));
        Book temp;
 
        temp.title = "";
        temp.title = result->getString(1).c_str();

        temp.autor = "";
        temp.autor = result->getString(2).c_str();

        temp.gatunek = "";
        temp.gatunek = result->getString(3).c_str();

        temp.data_wydania = "";
        temp.data_wydania = result->getString(4).c_str();

        temp.liczba_stron = 0;
        temp.liczba_stron = result->getInt(5);

        temp.count = 0;
        temp.count = result->getInt(6);

        books.push_back(temp);
    }

    return books;


}

void Mysql_connector::modify_books(vector <Book> books) {
    
    for (int i = 0; i < books.size(); i++) {
        try {
            if (books[i].data_wydania.length() == 0) {
                pstmt = con->prepareStatement("UPDATE ksiazki SET tytul=?, autor=?,gatunek=?, liczba_stron=? WHERE id_ksiazki = ?;");
                pstmt->setString(1, books[i].title);
                pstmt->setString(2, books[i].autor);
                pstmt->setString(3, books[i].gatunek);
                pstmt->setInt(4, books[i].liczba_stron);
                pstmt->setInt(5, books[i].id);
                result = pstmt->executeQuery();
            }
            else {
                pstmt = con->prepareStatement("UPDATE ksiazki SET tytul=?, autor=?,gatunek=?, data_wydania=?, liczba_stron=? WHERE id_ksiazki = ?;");
                pstmt->setString(1, books[i].title);
                pstmt->setString(2, books[i].autor);
                pstmt->setString(3, books[i].gatunek);
                pstmt->setString(4, books[i].data_wydania);
                pstmt->setInt(5, books[i].liczba_stron);
                pstmt->setInt(6, books[i].id);
                result = pstmt->executeQuery();
            }
        }
        catch (...) {}
    }
}

void Mysql_connector::delete_book(int id){

    try {
        pstmt = con->prepareStatement("DELETE FROM wypozyczenia WHERE id_ksiazki = ?;");
        pstmt->setInt(1, id);
        pstmt->executeQuery();

        pstmt = con->prepareStatement("DELETE FROM ksiazki WHERE id_ksiazki = ?;");
        pstmt->setInt(1, id);
        pstmt->executeQuery();
    }
    catch (...) {}
}

vector <string> Mysql_connector::get_gatunki() {

    vector <string> gatunki;
    pstmt = con->prepareStatement("SELECT DISTINCT(gatunek) FROM ksiazki WHERE length(gatunek)>0;");
    result = pstmt->executeQuery();
    while (result->next()) {
        string tmp = result->getString(1).c_str();
        gatunki.push_back(tmp);
    }

    return gatunki;
}

vector <Opoznione> Mysql_connector::spoznienie() {

    vector <Opoznione> op;
    pstmt = con->prepareStatement("SELECT login, tytul, data_oddania FROM uzytkownicy, wypozyczenia, ksiazki WHERE uzytkownicy.id_uzytkownika=wypozyczenia.id_uzytkownika AND ksiazki.id_ksiazki = wypozyczenia.id_ksiazki AND str_to_date(data_oddania, '%d.%m.%Y')<curdate();");
    result = pstmt->executeQuery();
    while (result->next()) {
        Opoznione temp;

        temp.login = "";
        temp.login = result->getString(1).c_str();

        temp.tytul = "";
        temp.tytul = result->getString(2).c_str();

        temp.data_oddania = "";
        temp.data_oddania = result->getString(3).c_str();

        op.push_back(temp);
    }



    return op;
}