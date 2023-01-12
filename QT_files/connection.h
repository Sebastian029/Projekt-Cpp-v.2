#ifndef CONNECTION_H
#define CONNECTION_H

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <QTableWidget>

#include <iostream>
#include <vector>
#include "structures.h"

class Mysql_connector{
public:
    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;
    Mysql_connector();
    ~Mysql_connector();
    int id;

    void add_book(std::string tytul,std::string autor, std::string gatunek, int liczba_stron, std::string data_wydania, int delete_date);
    int login(std::string login, std::string haslo);
    vector <Book> spis();
    vector <Book> spis_user();
    vector <User> lista_uzytkownikow();
    int create_account(string login, string password, string email, int nr_tel);
    vector <Book> wypozyczone();
    int borrow_book(string title);
    bool return_book(string title);
    vector <Borrowed_books> borrowed_list();
    vector <Book> spis_dostepnych();
    vector <Book> spis_wybranych(string kategoria, string wybor);
    int is_admin();
    vector <Daty_wypozyczen> daty_wypozyczen();
    int przedluz(string title);

    

};

#endif