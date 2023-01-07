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

class Mysql_connector {
public:
    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;
    Mysql_connector();
    ~Mysql_connector();
    int id;

    void add_book(std::string tytul, std::string gatunek);
    int login(std::string login, std::string haslo);
    vector <Book> spis();
    vector <User> lista_uzytkownikow(vector<User> books);
    int create_account(string login, string password);
    vector <Book> wypozyczone(vector<Book> books, int id);
    bool borrow_book(string title);
    bool return_book(string title);

};

#endif