#include "dictionary.h"
#include "ui_dictionary.h"

Dictionary::Dictionary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dictionary)
{
    ui->setupUi(this);
}

Dictionary::~Dictionary()
{
    delete ui;
}

void Dictionary::on_pushButton_clicked()
{
    this -> close();
    emit English();
}

