#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Cpp_projekt.h"

class Cpp_projekt : public QMainWindow
{
    Q_OBJECT

public:
    Cpp_projekt(QWidget *parent = nullptr);
    ~Cpp_projekt();

private:
    Ui::Cpp_projektClass ui;
};
