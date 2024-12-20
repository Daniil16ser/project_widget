#include "dictionary.h"
#include "ui_dictionary.h"
#include "database3.h"
#include <stdexcept>
#include <QTimer>

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

void Dictionary::on_backButton_clicked()
{
    this -> close();
    emit English();
}

void Dictionary::on_addButton_clicked()
{
    QString engWord = ui->addFieldEnglish->text();
    QString rusWord = ui->addFieldRussian->text();
    try {
        // store.add(engWord, rusWord);
        ui->isAddedLabel_1->setText("A new word has been added!");
    } catch(const std::exception& e) {
        ui->isAddedLabel_1->setText(e.what());
    }
    QTimer::singleShot(4000, [this](){ ui->isAddedLabel_1->clear(); });
    ui->addFieldEnglish->clear();
    ui->addFieldRussian->clear();
}

void Dictionary::on_deleteButton_clicked()
{
    QString word = ui->deleteField->text();
    try {
        //store.remove(word);
        ui->isAddedLabel_2->setText("The word has been deleted!");
    } catch(const std::exception& e) {
        ui->isAddedLabel_2->setText(e.what());
    }
    QTimer::singleShot(4000, [this](){ui->isAddedLabel_2->clear();});
    ui->deleteField->clear();
}

void Dictionary::on_changeButton_clicked()
{
    QString engWord = ui->changeFieldEnglish->text();
    QString rusWord = ui->changeFieldRussian->text();
    try {
        //store.remove(engWord);
        //store.add(engWord, rusWord);
        ui->isAddedLabel_3->setText("The translation has been changed!");
    } catch(const std::exception& e) {
        ui->isAddedLabel_3->setText(e.what());
    }
    QTimer::singleShot(4000, [this](){ui->isAddedLabel_3->clear();});
    ui->changeFieldEnglish->clear();
    ui->changeFieldRussian->clear();
}
