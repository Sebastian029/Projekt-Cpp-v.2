#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QLineEdit>
#include <QString>
#include <QList>
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
    void on_pushButton_wyloguj_clicked();
    void on_pushButton_anuluj_clicked();
    void on_pushButton_oddawanie_clicked();
private:
    Ui::MainWindow *ui;
    void init_users();
    void init_books();
    void init_borrowed();
    void init_oddawanie();

  
};
#endif // MAINWINDOW_H
