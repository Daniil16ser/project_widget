#include "limitedwordstest.h"
#include "ui_limitedwordstest.h"

LimitedWordsTest::LimitedWordsTest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LimitedWordsTest)
{
    wordsLimit = 10; // Нужно запросить у пользователя кол-во слов
    // Нужно создать счетчик, показывающий кол-во слов
    ui->setupUi(this);
    ui->nextButton->hide();
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
    if (++wordsCounter > wordsLimit) {
        // Нужно показать пользователю финальный счет
    }
    ui->nextButton->show();
}

void LimitedWordsTest::on_nextButton_clicked()
{
    // Нужно обновить счетчик, показывающий кол-во слов
    ui->nextButton->hide();
    ui->correctOrWrongLabel->setText("");
    ui->correctAnswerLabel->setText("");
    ui->rusWordField->setText("");
    QString nextWord = "BBBBB"; // Нужно реализовать функцию, возвращающую новое слово для перевода из БД
    engWord = nextWord;
    ui->engWordLabel->setText(nextWord);
    ui->checkButton->setEnabled(true);
    ui->rusWordField->setEnabled(true);
}
