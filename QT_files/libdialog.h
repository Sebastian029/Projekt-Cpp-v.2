#ifndef LIBDIALOG_H
#define LIBDIALOG_H

#include <QDialog>


namespace Ui {
class libDialog;
}


class libDialog : public QDialog
{
    Q_OBJECT

public:
    explicit libDialog(QWidget *parent = nullptr);
    ~libDialog();


private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::libDialog *ui;

};

#endif // LIBDIALOG_H
