#include "limitedwordstest.h"
#include "ui_limitedwordstest.h"
#include "database3.h"

LimitedWordsTest::LimitedWordsTest(unsigned short wordsLimit_, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LimitedWordsTest)
    , wordsLimit(wordsLimit_)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->nextButton->hide();
    ui->score2Label->hide();
    ui->wordsLimitLabel->setText(QString::number(wordsLimit));
    //parsik = store.getRandomPairs(wordsLimit);
    //ui->engWordLabel->setText(parsik[0].first);
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
    /*if (rusWord.compare(parsik[index].second) == 0) {
        ui->correctOrWrongLabel->setText("Correct!");
        ui->correctAnswerLabel->clear();
        ++correctAnswersCounter;
    } else {
        ui->correctOrWrongLabel->setText("Wrong! Correct answer is");
        ui->correctAnswerLabel->setText(parsik[index].second);
    }*/
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
    ui->correctOrWrongLabel->clear();
    ui->correctAnswerLabel->clear();
    ui->rusWordField->clear();
    ui->wordsCounterLabel->setText(QString::number(wordsCounter));
    //ui->engWordLabel->setText(parsik[++index].first);
    ui->checkButton->setEnabled(true);
    ui->rusWordField->setEnabled(true);
}
