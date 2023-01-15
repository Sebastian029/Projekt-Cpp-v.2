#pragma once
#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
using namespace std;

class Book {
public:
    int id;
    string title;
    string autor;
    string data_wydania;
    string gatunek;
    int liczba_stron;
    int count;
};

class User {
public:
    int id;
    string login;
    int num_of_borrowed_books;
    int nr_telefonu;
    string email;

};

class Borrowed_books {
public:
    int id_uzytkownika;
    int id_ksiazki;
    string login;
    string tytul;
    string data_wypozyczenia;
    string data_oddania;

};

class Daty_wypozyczen {
public:
    string tytul;
    string d_wypozyczenia;
    string d_oddania;

};

class Opoznione {
public:
    string login;
    string tytul;
    string data_oddania;
    int dni;
};


#endif