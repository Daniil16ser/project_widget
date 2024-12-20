#include "limitedmistakestest.h"
#include "ui_limitedmistakestest.h"
#include "database3.h"

LimitedMistakesTest::LimitedMistakesTest(unsigned short mistakesLimit_, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LimitedMistakesTest)
    , mistakesLimit(mistakesLimit_)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->score2Label->hide();
    ui->mistakesLimitLabel->setText(QString::number(mistakesLimit));
    ui->nextButton->hide();
    //parsik = store.getRandomPairs(wordsLimit);
    //ui->engWordLabel->setText(parsik[0].first);
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
    /*if (rusWord.compare(parsik[index].second) == 0) {
        ui->correctOrWrongLabel->setText("Correct!");
        ui->correctAnswerLabel->clear();
        ++correctAnswersCounter;
        ui->nextButton->show();
    } else {
        ui->mistakesCounterLabel->setText(QString::number(++mistakesCounter));
        ui->correctOrWrongLabel->setText("Wrong! Correct answer is");
        ui->correctAnswerLabel->setText(parsik[index].second);
        if (mistakesCounter <= mistakesLimit) {
            ui->nextButton->show();
        } else {
            ui->score1Label->setText("You correctly translated");
            ui->mistakesCounterLabel->setText(QString::number(correctAnswersCounter));
            ui->mistakesLimitLabel->setText(QString::number(correctAnswersCounter + mistakesCounter));
            ui->score2Label->show();
        }
    }*/
}

void LimitedMistakesTest::on_nextButton_clicked()
{
    ui->nextButton->hide();
    ui->correctOrWrongLabel->clear();
    ui->correctAnswerLabel->clear();
    ui->rusWordField->clear();
    if (++index == parsik.size()) {
        index = 0;
        //parsik = store.getRandomPairs(wordsLimit);
    }
    //ui->engWordLabel->setText(parsik[index].first);
    ui->checkButton->setEnabled(true);
    ui->rusWordField->setEnabled(true);
}
