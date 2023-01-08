/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_3;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_zaloguj;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_haslo;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_zarejestruj;
    QWidget *page_tworzenie_konta;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_6;
    QFormLayout *formLayout_5;
    QLabel *label_6;
    QLineEdit *lineEdit_login_2;
    QLabel *label_7;
    QLineEdit *lineEdit_haslo_2;
    QLabel *label_8;
    QLineEdit *lineEdit_email_2;
    QLabel *label_9;
    QLineEdit *lineEdit_telefon_2;
    QGridLayout *gridLayout_9;
    QPushButton *pushButton_zaloz;
    QPushButton *pushButton_anuluj;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_6;
    QWidget *page_5;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_wyloguj;
    QLabel *label_zalogowano_login;
    QLabel *label_16;
    QTabWidget *tabWidget;
    QWidget *wypozyczenie;
    QTableWidget *tableWidget_wypozyczanie;
    QPushButton *pushButton_szukaj;
    QWidget *oddawanie;
    QComboBox *comboBox_oddawanie;
    QPushButton *pushButton_oddawanie;
    QCalendarWidget *calendarWidget;
    QWidget *ksiazki;
    QTableWidget *tableWidget_ksiazki;
    QWidget *uzytkownicy;
    QTableWidget *tableWidget_uzytkownicy;
    QWidget *wypozyczenia;
    QTableWidget *tableWidget_wypozyczenia;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(773, 449);
        QIcon icon;
        icon.addFile(QString::fromUtf8("favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(218, 218, 218);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        formLayoutWidget = new QWidget(page_3);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 1, 791, 381));
        formLayout_3 = new QFormLayout(formLayoutWidget);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_4, 4, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 0, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 6, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 0, 1, 1);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_3->addWidget(label_2, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127,0);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 0, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 2, 1, 1);

        pushButton_zaloguj = new QPushButton(formLayoutWidget);
        pushButton_zaloguj->setObjectName(QString::fromUtf8("pushButton_zaloguj"));

        gridLayout_3->addWidget(pushButton_zaloguj, 5, 1, 1, 1);

        lineEdit_login = new QLineEdit(formLayoutWidget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        QFont font1;
        font1.setPointSize(10);
        lineEdit_login->setFont(font1);
        lineEdit_login->setStyleSheet(QString::fromUtf8(""));
        lineEdit_login->setMaxLength(30);

        gridLayout_3->addWidget(lineEdit_login, 3, 1, 1, 1);

        lineEdit_haslo = new QLineEdit(formLayoutWidget);
        lineEdit_haslo->setObjectName(QString::fromUtf8("lineEdit_haslo"));
        lineEdit_haslo->setFont(font1);
        lineEdit_haslo->setMaxLength(30);
        lineEdit_haslo->setEchoMode(QLineEdit::Password);

        gridLayout_3->addWidget(lineEdit_haslo, 4, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 6, 2, 1, 1);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_3->addWidget(label_5, 6, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 7, 0, 1, 1);

        pushButton_zarejestruj = new QPushButton(formLayoutWidget);
        pushButton_zarejestruj->setObjectName(QString::fromUtf8("pushButton_zarejestruj"));

        gridLayout_3->addWidget(pushButton_zarejestruj, 7, 1, 1, 1);


        formLayout_3->setLayout(0, QFormLayout::SpanningRole, gridLayout_3);

        stackedWidget->addWidget(page_3);
        page_tworzenie_konta = new QWidget();
        page_tworzenie_konta->setObjectName(QString::fromUtf8("page_tworzenie_konta"));
        gridLayout_2 = new QGridLayout(page_tworzenie_konta);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_16, 0, 2, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_14, 0, 0, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_17, 0, 3, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 3, 2, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_13, 3, 1, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_15, 0, 1, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_18, 0, 4, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 3, 4, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_12, 3, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_11, 3, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 4, 1, 1);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_6 = new QLabel(page_tworzenie_konta);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_6);

        lineEdit_login_2 = new QLineEdit(page_tworzenie_konta);
        lineEdit_login_2->setObjectName(QString::fromUtf8("lineEdit_login_2"));
        lineEdit_login_2->setMaxLength(30);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, lineEdit_login_2);

        label_7 = new QLabel(page_tworzenie_konta);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_7);

        lineEdit_haslo_2 = new QLineEdit(page_tworzenie_konta);
        lineEdit_haslo_2->setObjectName(QString::fromUtf8("lineEdit_haslo_2"));
        lineEdit_haslo_2->setMaxLength(30);

        formLayout_5->setWidget(2, QFormLayout::FieldRole, lineEdit_haslo_2);

        label_8 = new QLabel(page_tworzenie_konta);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label_8);

        lineEdit_email_2 = new QLineEdit(page_tworzenie_konta);
        lineEdit_email_2->setObjectName(QString::fromUtf8("lineEdit_email_2"));
        lineEdit_email_2->setMaxLength(30);

        formLayout_5->setWidget(3, QFormLayout::FieldRole, lineEdit_email_2);

        label_9 = new QLabel(page_tworzenie_konta);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_5->setWidget(4, QFormLayout::LabelRole, label_9);

        lineEdit_telefon_2 = new QLineEdit(page_tworzenie_konta);
        lineEdit_telefon_2->setObjectName(QString::fromUtf8("lineEdit_telefon_2"));
        lineEdit_telefon_2->setMaxLength(30);

        formLayout_5->setWidget(4, QFormLayout::FieldRole, lineEdit_telefon_2);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        pushButton_zaloz = new QPushButton(page_tworzenie_konta);
        pushButton_zaloz->setObjectName(QString::fromUtf8("pushButton_zaloz"));

        gridLayout_9->addWidget(pushButton_zaloz, 0, 1, 1, 1);

        pushButton_anuluj = new QPushButton(page_tworzenie_konta);
        pushButton_anuluj->setObjectName(QString::fromUtf8("pushButton_anuluj"));

        gridLayout_9->addWidget(pushButton_anuluj, 0, 3, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_19, 0, 2, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_20, 0, 0, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_21, 0, 4, 1, 1);


        formLayout_5->setLayout(5, QFormLayout::FieldRole, gridLayout_9);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_5->setItem(0, QFormLayout::FieldRole, verticalSpacer_4);


        gridLayout_2->addLayout(formLayout_5, 1, 1, 1, 3);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 2, 2, 1, 1);

        stackedWidget->addWidget(page_tworzenie_konta);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        gridLayout_4 = new QGridLayout(page_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(289, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        pushButton_wyloguj = new QPushButton(page_5);
        pushButton_wyloguj->setObjectName(QString::fromUtf8("pushButton_wyloguj"));

        gridLayout_5->addWidget(pushButton_wyloguj, 0, 4, 1, 1);

        label_zalogowano_login = new QLabel(page_5);
        label_zalogowano_login->setObjectName(QString::fromUtf8("label_zalogowano_login"));

        gridLayout_5->addWidget(label_zalogowano_login, 0, 3, 1, 1);

        label_16 = new QLabel(page_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_5->addWidget(label_16, 0, 2, 1, 1);

        tabWidget = new QTabWidget(page_5);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        wypozyczenie = new QWidget();
        wypozyczenie->setObjectName(QString::fromUtf8("wypozyczenie"));
        tableWidget_wypozyczanie = new QTableWidget(wypozyczenie);
        if (tableWidget_wypozyczanie->columnCount() < 5)
            tableWidget_wypozyczanie->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_wypozyczanie->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_wypozyczanie->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_wypozyczanie->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_wypozyczanie->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_wypozyczanie->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget_wypozyczanie->setObjectName(QString::fromUtf8("tableWidget_wypozyczanie"));
        tableWidget_wypozyczanie->setGeometry(QRect(0, 0, 721, 161));
        tableWidget_wypozyczanie->horizontalHeader()->setStretchLastSection(true);
        pushButton_szukaj = new QPushButton(wypozyczenie);
        pushButton_szukaj->setObjectName(QString::fromUtf8("pushButton_szukaj"));
        pushButton_szukaj->setGeometry(QRect(20, 180, 93, 28));
        tabWidget->addTab(wypozyczenie, QString());
        oddawanie = new QWidget();
        oddawanie->setObjectName(QString::fromUtf8("oddawanie"));
        comboBox_oddawanie = new QComboBox(oddawanie);
        comboBox_oddawanie->setObjectName(QString::fromUtf8("comboBox_oddawanie"));
        comboBox_oddawanie->setGeometry(QRect(10, 30, 261, 31));
        pushButton_oddawanie = new QPushButton(oddawanie);
        pushButton_oddawanie->setObjectName(QString::fromUtf8("pushButton_oddawanie"));
        pushButton_oddawanie->setGeometry(QRect(110, 110, 93, 28));
        calendarWidget = new QCalendarWidget(oddawanie);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(300, 10, 401, 241));
        calendarWidget->setAutoFillBackground(false);
        calendarWidget->setMinimumDate(QDate(2000, 9, 14));
        calendarWidget->setGridVisible(true);
        calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(true);
        tabWidget->addTab(oddawanie, QString());
        ksiazki = new QWidget();
        ksiazki->setObjectName(QString::fromUtf8("ksiazki"));
        tableWidget_ksiazki = new QTableWidget(ksiazki);
        if (tableWidget_ksiazki->columnCount() < 4)
            tableWidget_ksiazki->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_ksiazki->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_ksiazki->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_ksiazki->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_ksiazki->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        tableWidget_ksiazki->setObjectName(QString::fromUtf8("tableWidget_ksiazki"));
        tableWidget_ksiazki->setGeometry(QRect(0, 0, 731, 291));
        tableWidget_ksiazki->horizontalHeader()->setStretchLastSection(true);
        tableWidget_ksiazki->verticalHeader()->setVisible(false);
        tabWidget->addTab(ksiazki, QString());
        uzytkownicy = new QWidget();
        uzytkownicy->setObjectName(QString::fromUtf8("uzytkownicy"));
        tableWidget_uzytkownicy = new QTableWidget(uzytkownicy);
        if (tableWidget_uzytkownicy->columnCount() < 3)
            tableWidget_uzytkownicy->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_uzytkownicy->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_uzytkownicy->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_uzytkownicy->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        tableWidget_uzytkownicy->setObjectName(QString::fromUtf8("tableWidget_uzytkownicy"));
        tableWidget_uzytkownicy->setGeometry(QRect(0, 0, 721, 281));
        tableWidget_uzytkownicy->horizontalHeader()->setStretchLastSection(true);
        tableWidget_uzytkownicy->verticalHeader()->setVisible(false);
        tableWidget_uzytkownicy->verticalHeader()->setStretchLastSection(false);
        tabWidget->addTab(uzytkownicy, QString());
        wypozyczenia = new QWidget();
        wypozyczenia->setObjectName(QString::fromUtf8("wypozyczenia"));
        tableWidget_wypozyczenia = new QTableWidget(wypozyczenia);
        if (tableWidget_wypozyczenia->columnCount() < 6)
            tableWidget_wypozyczenia->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_wypozyczenia->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_wypozyczenia->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_wypozyczenia->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_wypozyczenia->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_wypozyczenia->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_wypozyczenia->setHorizontalHeaderItem(5, __qtablewidgetitem17);
        tableWidget_wypozyczenia->setObjectName(QString::fromUtf8("tableWidget_wypozyczenia"));
        tableWidget_wypozyczenia->setGeometry(QRect(0, 0, 721, 271));
        tableWidget_wypozyczenia->horizontalHeader()->setStretchLastSection(true);
        tableWidget_wypozyczenia->verticalHeader()->setVisible(false);
        tabWidget->addTab(wypozyczenia, QString());

        gridLayout_5->addWidget(tabWidget, 1, 0, 1, 5);


        gridLayout_4->addLayout(gridLayout_5, 0, 0, 1, 1);

        stackedWidget->addWidget(page_5);

        gridLayout->addWidget(stackedWidget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 773, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Biblioteka", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Has\305\202o", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Prosz\304\231 si\304\231 zalogowa\304\207", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Witamy w Bibliotece", nullptr));
        pushButton_zaloguj->setText(QCoreApplication::translate("MainWindow", "Zaloguj", nullptr));
        lineEdit_login->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Nie masz konta?", nullptr));
        pushButton_zarejestruj->setText(QCoreApplication::translate("MainWindow", "Zarejestruj si\304\231", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Has\305\202o", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Adres e- mail", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Telefon", nullptr));
        lineEdit_telefon_2->setInputMask(QString());
        lineEdit_telefon_2->setText(QString());
        pushButton_zaloz->setText(QCoreApplication::translate("MainWindow", "Za\305\202\303\263\305\274 konto", nullptr));
        pushButton_anuluj->setText(QCoreApplication::translate("MainWindow", "Anuluj", nullptr));
        pushButton_wyloguj->setText(QCoreApplication::translate("MainWindow", "Wyloguj", nullptr));
        label_zalogowano_login->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "Zalogowano jako", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_wypozyczanie->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Tytu\305\202 ksiazki", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_wypozyczanie->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Autor", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_wypozyczanie->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Gatunek", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_wypozyczanie->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Liczba stron", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_wypozyczanie->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Data wydania", nullptr));
        pushButton_szukaj->setText(QCoreApplication::translate("MainWindow", "Szukaj", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(wypozyczenie), QCoreApplication::translate("MainWindow", "Wypo\305\274yczanie", nullptr));
        pushButton_oddawanie->setText(QCoreApplication::translate("MainWindow", "Zwroc ksiazke", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(oddawanie), QCoreApplication::translate("MainWindow", "Oddawanie", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_ksiazki->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Tytu\305\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_ksiazki->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Autor", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_ksiazki->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Gatunek", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_ksiazki->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Liczba stron", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ksiazki), QCoreApplication::translate("MainWindow", "Lista ksi\304\205\305\274ek", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_uzytkownicy->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_uzytkownicy->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_uzytkownicy->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Liczba wypozyczonych", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(uzytkownicy), QCoreApplication::translate("MainWindow", "Lista u\305\274ytkownik\303\263w", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_wypozyczenia->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "id_uzytkownika", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_wypozyczenia->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "id_ksiazki", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_wypozyczenia->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "login", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_wypozyczenia->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "tytul", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_wypozyczenia->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "d_wypozyczenia", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_wypozyczenia->horizontalHeaderItem(5);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "d_oddania", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(wypozyczenia), QCoreApplication::translate("MainWindow", "Wypozyczenia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
