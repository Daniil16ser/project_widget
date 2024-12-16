#include "dictionary.h"
#include "ui_dictionary.h"
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
    // Нужно реализовать функцию, проверяющую, есть ли слово в БД, и добавляющую его, если его нет в БД
    // Либо можно спрашивать у пользователя, заменить ли старый перевод на новый
    bool isAdded = true;
    if (isAdded) {
        ui->isAddedLabel_1->setText("This word has already been added!");
    } else {
        ui->isAddedLabel_1->setText("A new word has been added!");
    }
    QTimer::singleShot(4000, [this](){ui->isAddedLabel_1->setText("");});
    ui->addFieldEnglish->setText("");
    ui->addFieldRussian->setText("");
}

void Dictionary::on_deleteButton_clicked()
{
    QString word = ui->deleteField->text();
    // Нужно реализовать функцию, проверяющую, есть ли слово в БД, и удаляющую его, если оно есть в БД
    bool isAdded = true;
    if (isAdded) {
        ui->isAddedLabel_2->setText("The word has been deleted!");
    } else {
        ui->isAddedLabel_2->setText("This word is not in the dictionary!");
    }
    QTimer::singleShot(4000, [this](){ui->isAddedLabel_2->setText("");});
    ui->deleteField->setText("");
}

void Dictionary::on_changeButton_clicked()
{
    QString engWord = ui->changeFieldEnglish->text();
    QString rusWord = ui->changeFieldRussian->text();
    // Нужно реализовать функцию, проверяющую, есть ли слово в БД, и меняющую его перевод, если оно есть в БД
    // Либо можно спрашивать у пользователя, добавить ли в БД новое слово
    bool isAdded = true;
    if (isAdded) {
        ui->isAddedLabel_3->setText("The translation has been changed!");
    } else {
        ui->isAddedLabel_3->setText("This word is not in the dictionary!");
    }
    QTimer::singleShot(4000, [this](){ui->isAddedLabel_3->setText("");});
    ui->changeFieldEnglish->setText("");
    ui->changeFieldRussian->setText("");
}
