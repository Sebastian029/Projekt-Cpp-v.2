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

    stmt = con->createStatement();
    stmt->execute("DROP TABLE IF EXISTS Wypozyczenia");
    stmt->execute("DROP TABLE IF EXISTS Ksiazki");
    stmt->execute("DROP TABLE IF EXISTS Uzytkownicy");
    cout << "Finished dropping table (if existed)" << endl;

    stmt->execute("CREATE TABLE Uzytkownicy (id_uzytkownika INT AUTO_INCREMENT, login VARCHAR(30),haslo VARCHAR(30), num_of_borrowed_books INTEGER, PRIMARY KEY(id_uzytkownika));");
    stmt->execute("CREATE TABLE Ksiazki (id_ksiazki INT AUTO_INCREMENT, enable BOOLEAN, tytul VARCHAR(30), autor VARCHAR(30), gatunek VARCHAR(20), data_wydania DATE, liczba_stron INT, PRIMARY KEY(id_ksiazki));");
    stmt->execute("CREATE TABLE Wypozyczenia (id_wypozyczenia INT AUTO_INCREMENT,id_uzytkownika INT, id_ksiazki INT UNIQUE, data_wypozyczenia DATE, data_oddania DATE, PRIMARY KEY(id_wypozyczenia), FOREIGN KEY (id_uzytkownika) REFERENCES Uzytkownicy(id_uzytkownika), FOREIGN KEY (id_ksiazki) REFERENCES Ksiazki(id_ksiazki));");

    cout << "Finished creating tables" << endl;
    //stmt->execute("INSERT INTO Uzytkownicy (login, haslo, num_of_borrowed_books) VALUES ('mylogin', 'mypasswordddd', 1);");





    stmt->execute("INSERT INTO Uzytkownicy (login, haslo, num_of_borrowed_books) VALUES ('mylogin', 'mypasswordddd', 0);");
    stmt->execute("INSERT INTO Uzytkownicy (login, haslo, num_of_borrowed_books) VALUES ('mycos', 'mypasads', 1);");
    stmt->execute("INSERT INTO Uzytkownicy (login, haslo, num_of_borrowed_books) VALUES ('LOGIN', 'HASLO', 2);");

    stmt->execute("INSERT INTO Ksiazki (tytul,enable) VALUES ('TytulKsiazki',1);");
    stmt->execute("INSERT INTO Ksiazki (tytul,enable) VALUE ('TytulKsiazki1',1);");
    stmt->execute("INSERT INTO Ksiazki (tytul,enable) VALUE ('TytulKsiazki112',1);");
    stmt->execute("INSERT INTO Ksiazki (tytul,enable) VALUE ('TytulKsiazki12',1);");
    stmt->execute("INSERT INTO Ksiazki (tytul,enable) VALUE ('TytulKsi12',1);");


    //stmt->execute("INSERT INTO Wypozyczenia (id_uzytkownika, id_ksiazki) VALUES (1, 2);");
    //stmt->execute("INSERT INTO Wypozyczenia (id_uzytkownika, id_ksiazki) VALUES (1, 1);");
    //stmt->execute("INSERT INTO Wypozyczenia (id_uzytkownika, id_ksiazki) VALUES (2, 3);");
    //stmt->execute("INSERT INTO Wypozyczenia (id_uzytkownika, id_ksiazki) VALUES (3, 4);");


}

void Mysql_connector::add_book(string tytul, string gatunek) {
    sql::PreparedStatement* pstmt;
    pstmt = con->prepareStatement("INSERT INTO Ksiazki(tytul, gatunek) VALUES(?,?)");
    pstmt->setString(1, tytul);
    pstmt->setString(2, gatunek);
    pstmt->execute();

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
                return result->getInt(1);
            }
            cout << "Bledne haslo" << endl;
            return -1;
        }
    }
    cout << "Bledne dane" << endl;
    return -1;

    //delete pstmt;
}

vector <Book>  Mysql_connector::spis(vector<Book> books) {

    pstmt = con->prepareStatement("SELECT id_ksiazki, tytul FROM Ksiazki;");
    result = pstmt->executeQuery();
    while (result->next()) {
        //printf("Reading from table=(%d, %s, %s, %d)\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), result->getInt(4));
        Book temp;
        temp.id = -1;
        temp.id = result->getInt(1);

        temp.title = "";
        temp.title = result->getString(2).c_str();
        books.push_back(temp);
    }

    return books;
};


vector <User>  Mysql_connector::lista_uzytkownikow(vector<User> users) {

    pstmt = con->prepareStatement("SELECT id_uzytkownika, login FROM Uzytkownicy;");
    result = pstmt->executeQuery();
    while (result->next()) {
        //printf("Reading from table=(%d, %s, %s, %d)\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), result->getInt(4));
        User temp;
        temp.id = -1;
        temp.id = result->getInt(1);

        temp.login = "";
        temp.login = result->getString(2).c_str();
        users.push_back(temp);
    }

    return users;
};

void Mysql_connector::create_account(string login, string password) {
    sql::PreparedStatement* pstmt;
    list <string> logins;
    pstmt = con->prepareStatement("SELECT login FROM Uzytkownicy;");
    result = pstmt->executeQuery();
    while (result->next()) {
        if (result->getString(1).c_str() == login) {
            cout << "Zajety login";
            return;
        }
    }


    pstmt = con->prepareStatement("INSERT INTO Uzytkownicy(login, haslo, num_of_borrowed_books) VALUES(?,?,?)");
    pstmt->setString(1, login);
    pstmt->setString(2, password);
    pstmt->setInt(3, 0);
    pstmt->execute();

    cout << "Dodano uzytkownika";
}



vector <Book>  Mysql_connector::wypozyczone(vector<Book> books, int id) {

    if (id < 0) {
        cout << "Nie zalogwany uzytkownik";
        return books;
    }


    pstmt = con->prepareStatement("SELECT ksiazki.id_ksiazki, ksiazki.tytul FROM ksiazki, Wypozyczenia, Uzytkownicy WHERE uzytkownicy.id_uzytkownika = wypozyczenia.id_uzytkownika AND wypozyczenia.id_ksiazki = ksiazki.id_ksiazki AND uzytkownicy.id_uzytkownika=?;");
    pstmt->setInt(1, id);
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

bool Mysql_connector::borrow_book(int user_id, string title) {
    int book_id = -1;
    //odnalezienie ksiazki
    try {
        pstmt = con->prepareStatement("SELECT id_ksiazki FROM ksiazki WHERE tytul=? AND enable=1 LIMIT 1");
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
    pstmt = con->prepareStatement("INSERT INTO wypozyczenia (wypozyczenia.id_uzytkownika, wypozyczenia.id_ksiazki) VALUES (?, ?);");
    pstmt->setInt(1, user_id);
    pstmt->setInt(2, book_id);
    pstmt->executeQuery();

    return 1;
}

bool Mysql_connector::return_book(int user_id, string title) {
    int book_id = -1;
    //odnalezienie ksiazki
    try {
        pstmt = con->prepareStatement("SELECT ksiazki.id_ksiazki FROM ksiazki, wypozyczenia WHERE enable=0 AND tytul=? AND id_uzytkownika=? AND ksiazki.id_ksiazki=wypozyczenia.id_ksiazki LIMIT 1;");
        pstmt->setString(1, title);
        pstmt->setInt(2, user_id);
        result = pstmt->executeQuery();
        result->next();
        book_id = result->getInt(1);
    }
    catch (...) {
        cout << "Nie odnaleziono ksiazki";
        return 0;
    }

    // zmiana dostepsnosci ksiazki
    pstmt = con->prepareStatement("UPDATE ksiazki SET enable=1 WHERE id_ksiazki=?;");
    pstmt->setInt(1, book_id);
    pstmt->executeQuery();

    // usuniecie wypozyczen
    pstmt = con->prepareStatement("DELETE FROM wypozyczenia WHERE wypozyczenia.id_ksiazki=? LIMIT 1;");
    pstmt->setInt(1, book_id);
    pstmt->executeQuery();

    return 1;
}