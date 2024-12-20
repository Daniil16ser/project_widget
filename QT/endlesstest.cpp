#include "endlesstest.h"
#include "ui_endlesstest.h"
#include "database3.h"

EndlessTest::EndlessTest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EndlessTest)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    //parsik = store.getRandomPairs(wordsLimit);
    //ui->engWordLabel->setText(parsik[0].first);
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
    /*if (parsik[index].second == rusWord) {
        ui->correctOrWrongLabel->setText("Correct!");
        ui->correctAnswerLabel->clear();
    } else {
        ui->correctOrWrongLabel->setText("Wrong! Correct answer is");
        ui->correctAnswerLabel->setText(parsik[index].second);
    }*/
}

void EndlessTest::on_nextButton_clicked()
{
    if (++index == parsik.size()) {
        index = 0;
        //parsik = store.getRandomPairs(wordsLimit);
    }
    //ui->engWordLabel->setText(parsik[index].first);
    ui->correctOrWrongLabel->clear();
    ui->correctAnswerLabel->clear();
    ui->rusWordField->clear();
    ui->checkButton->setEnabled(true);
    ui->rusWordField->setEnabled(true);
}
