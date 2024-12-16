#include "endlesstest.h"
#include "ui_endlesstest.h"

EndlessTest::EndlessTest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EndlessTest)
{
    ui->setupUi(this);
    QString nextWord = "AAAAA"; // Нужно реализовать функцию, возвращающую новое слово для перевода из БД
    ui->engWordLabel->setText(nextWord);
    engWord = nextWord;
}

EndlessTest::~EndlessTest()
{
    delete ui;
}

void EndlessTest::on_backButton_clicked()
{
    this -> close();
    emit Test();
}

void EndlessTest::on_checkButton_clicked()
{
    ui->checkButton->setDisabled(true);
    ui->rusWordField->setDisabled(true);
    QString rusWord = ui->rusWordField->text();
    QString answer = "AAAAA"; // Нужно реализовать функцию, возвращающую перевод слова из БД
    if (answer == rusWord) {
        ui->correctOrWrongLabel->setText("Correct!");
        ui->correctAnswerLabel->setText("");
    } else {
        ui->correctOrWrongLabel->setText("Wrong! Correct answer is");
        ui->correctAnswerLabel->setText(answer);
    }
}

void EndlessTest::on_nextButton_clicked()
{
    QString nextWord = "BBBBB"; // Нужно реализовать функцию, возвращающую новое слово для перевода из БД
    ui->engWordLabel->setText(nextWord);
    engWord = nextWord;
    ui->correctOrWrongLabel->setText("");
    ui->correctAnswerLabel->setText("");
    ui->rusWordField->setText("");
    ui->checkButton->setEnabled(true);
    ui->rusWordField->setEnabled(true);
}
