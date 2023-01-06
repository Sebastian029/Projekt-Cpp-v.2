#pragma once
#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
using namespace std;

class Book {
public:
    int id;
    string title;
    string data_wydania;
    string gatunek;
    int liczba_stron;
};

class User {
public:
    int id;
    string login;
    int num_of_borrowed_books;

};


#endif