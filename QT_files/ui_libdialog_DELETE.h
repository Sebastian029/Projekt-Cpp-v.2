/********************************************************************************
** Form generated from reading UI file 'libdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBDIALOG_H
#define UI_LIBDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_libDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QTabWidget *tabWidget;
    QWidget *wyp;
    QWidget *odd;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QDialog *libDialog)
    {
        if (libDialog->objectName().isEmpty())
            libDialog->setObjectName(QString::fromUtf8("libDialog"));
        libDialog->resize(740, 414);
        gridLayout = new QGridLayout(libDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(libDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        label = new QLabel(libDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        label_2 = new QLabel(libDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        pushButton_2 = new QPushButton(libDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(libDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        wyp = new QWidget();
        wyp->setObjectName(QString::fromUtf8("wyp"));
        tabWidget->addTab(wyp, QString());
        odd = new QWidget();
        odd->setObjectName(QString::fromUtf8("odd"));
        tabWidget->addTab(odd, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 7);


        retranslateUi(libDialog);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(libDialog);
    } // setupUi

    void retranslateUi(QDialog *libDialog)
    {
        libDialog->setWindowTitle(QCoreApplication::translate("libDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("libDialog", "Wyloguj", nullptr));
        label->setText(QCoreApplication::translate("libDialog", "Zalogowano jako", nullptr));
        label_2->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("libDialog", "Sprawd\305\272 po\305\202\304\205czenie z baz\304\205 danych", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(wyp), QCoreApplication::translate("libDialog", "Wypo\305\274yczanie", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(odd), QCoreApplication::translate("libDialog", "Oddawanie", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("libDialog", "Lista u\305\274ytkownik\303\263w", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("libDialog", "Lista ksi\304\205\305\274ek", nullptr));
    } // retranslateUi

};

namespace Ui {
    class libDialog: public Ui_libDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBDIALOG_H
