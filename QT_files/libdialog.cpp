#include "libdialog.h"
#include "ui_libdialog.h"
#include <QMainWindow>

libDialog::libDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::libDialog)
{
    ui->setupUi(this);

   // ui->label_2->setText()

}

libDialog::~libDialog()
{
    delete ui;
}


void libDialog::on_pushButton_clicked()
{
    /*QMainWindow *p= dynamic_cast<QMainWindow>(this->parent());
    p->show;*/
    parentWidget()->show();
    close();
}


void libDialog::on_pushButton_2_clicked()
{

}

