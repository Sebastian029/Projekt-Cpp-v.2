#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QLineEdit>
#include <QString>
#include <QList>

#include <QColor>

#include <QTextFormat>
#include <string>
#include <cctype>
#include "connection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_zaloguj_clicked();
    void on_pushButton_zarejestruj_clicked();
    void on_pushButton_zaloz_clicked();
    void on_pushButton_pokaz_haslo_pressed();
    void on_pushButton_pokaz_haslo_released();
    void on_pushButton_wyloguj_clicked();
    void on_pushButton_wyloguj_4_clicked();
    void on_pushButton_anuluj_clicked();
    void on_pushButton_oddawanie_clicked();
    void on_pushButton_wypozycz_clicked();
    void on_tableWidget_wypozyczanie_cellClicked(int row, int column);
    void on_tableWidget_wybrane_ksiazki_cellClicked(int row, int column);
    void on_pushButton_szukaj_clicked();
    void on_pushButton_filtry_clicked();
    void on_pushButton_D_dodaj_clicked();
    void on_checkBox_D_data_clicked();
    void on_pushButton_przedluz_clicked();
    void on_pushButton_modyfikuj_clicked();
    void on_pushButton_usun_zmiany_clicked();
private:
    Ui::MainWindow *ui;
    void init_users();
    void init_books();
    void init_borrowed();
    void init_oddawanie();
    void init_spis();
    void select_user();
    void select_admin();
    void init_daty();

  
    
  
};
#endif // MAINWINDOW_H
