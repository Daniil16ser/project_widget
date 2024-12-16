#include "limitedwordstest.h"
#include "ui_limitedwordstest.h"
#include <QString>

LimitedWordsTest::LimitedWordsTest(unsigned short wordsLimit_, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LimitedWordsTest)
    , wordsLimit(wordsLimit_)
{
    ui->setupUi(this);
    ui->nextButton->hide();
    ui->score2Label->hide();
    ui->wordsLimitLabel->setText(QString::number(wordsLimit));
    QString nextWord = "AAAAA"; // Нужно реализовать функцию, возвращающую новое слово для перевода из БД
    engWord = nextWord;
    ui->engWordLabel->setText(nextWord);
}

LimitedWordsTest::~LimitedWordsTest()
{
    delete ui;
}

void LimitedWordsTest::on_backButton_clicked()
{
    this -> close();
    emit Test();
    delete this;
}

void LimitedWordsTest::on_checkButton_clicked()
{
    ui->checkButton->setDisabled(true);
    ui->rusWordField->setDisabled(true);
    QString rusWord = ui->rusWordField->text();
    QString answer = "AAAAA"; // Нужно реализовать функцию, возвращающую перевод слова из БД
    if (answer == rusWord) {
        ui->correctOrWrongLabel->setText("Correct!");
        ui->correctAnswerLabel->setText("");
        ++correctAnswersCounter;
    } else {
        ui->correctOrWrongLabel->setText("Wrong! Correct answer is");
        ui->correctAnswerLabel->setText(answer);
    }
    if (++wordsCounter <= wordsLimit) {
        ui->nextButton->show();
    } else {
        ui->score1Label->setText("You correctly translated");
        ui->wordsCounterLabel->setText(QString::number(correctAnswersCounter));
        ui->score2Label->show();
    }
}

void LimitedWordsTest::on_nextButton_clicked()
{
    ui->nextButton->hide();
    ui->correctOrWrongLabel->setText("");
    ui->correctAnswerLabel->setText("");
    ui->rusWordField->setText("");
    ui->wordsCounterLabel->setText(QString::number(wordsCounter));
    QString nextWord = "BBBBB"; // Нужно реализовать функцию, возвращающую новое слово для перевода из БД
    engWord = nextWord;
    ui->engWordLabel->setText(nextWord);
    ui->checkButton->setEnabled(true);
    ui->rusWordField->setEnabled(true);
}
