#include "limitedmistakestest.h"
#include "ui_limitedmistakestest.h"

LimitedMistakesTest::LimitedMistakesTest(unsigned short mistakesLimit_, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LimitedMistakesTest)
    , mistakesLimit(mistakesLimit_)
{
    ui->setupUi(this);
    ui->score2Label->hide();
    ui->mistakesLimitLabel->setText(QString::number(mistakesLimit));
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
    delete this;
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
        ui->nextButton->show();
    } else {
        ui->mistakesCounterLabel->setText(QString::number(++mistakesCounter));
        ui->correctOrWrongLabel->setText("Wrong! Correct answer is");
        ui->correctAnswerLabel->setText(answer);
        if (mistakesCounter <= mistakesLimit) {
            ui->nextButton->show();
        } else {
            ui->score1Label->setText("You correctly translated");
            ui->mistakesCounterLabel->setText(QString::number(correctAnswersCounter));
            ui->mistakesLimitLabel->setText(QString::number(correctAnswersCounter + mistakesCounter));
            ui->score2Label->show();
        }
    }
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
