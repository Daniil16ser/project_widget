#include "limitedmistakestest.h"
#include "ui_limitedmistakestest.h"

LimitedMistakesTest::LimitedMistakesTest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LimitedMistakesTest)
{
    mistakesCounter = 3; // Нужно запросить у пользователя кол-во ошибок
    // Нужно создать счетчик, показывающий кол-во ошибок
    ui->setupUi(this);
    ui->nextButton->hide();
    QString nextWord = "AAAAA"; // Нужно реализовать функцию, возвращающую новое слово для перевода из БД
    engWord = nextWord;
    ui->engWordLabel->setText(nextWord);
}

LimitedMistakesTest::~LimitedMistakesTest()
{
    delete ui;
}

void LimitedMistakesTest::on_backButton_clicked()
{
    this -> close();
    emit Test();
}

void LimitedMistakesTest::on_checkButton_clicked()
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
        // Нужно обновить счетчик, показывающий кол-во ошибок
        ui->correctOrWrongLabel->setText("Wrong! Correct answer is");
        ui->correctAnswerLabel->setText(answer);
        if (++mistakesCounter == mistakesLimit) {
            // Нужно показать пользователю финальный счет
        }
    }
    ui->nextButton->show();
}

void LimitedMistakesTest::on_nextButton_clicked()
{
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
