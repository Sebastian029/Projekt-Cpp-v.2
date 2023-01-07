#include "addaccount.h"
#include "ui_addaccount.h"
#include "connection.h"

Mysql_connector sqq;
AddAccount::AddAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAccount)
{

    ui->setupUi(this);
}

AddAccount::~AddAccount()
{
    delete ui;
}

void AddAccount::on_pushButton_zaloz_clicked()
{
    QString log = ui->lineEdit_login->text();
    QString pass = ui->lineEdit_haslo->text();
    
   
    int w = 0;
    //sq.create_account(log.toStdString(), pass.toStdString());
    if(w==-1)
        QMessageBox::information(this, "B³¹d", "Zajety login");

    parentWidget()->show();
    close();
}

