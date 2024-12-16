#include "test.h"
#include "ui_test.h"

Test::Test(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test)
{
    ui->setupUi(this);
}

Test::~Test()
{
    delete ui;
}

void Test::on_backButton_clicked()
{
    this -> close();
    emit English();
}

void Test::on_endlessTestButton_clicked()
{
    endlessTestWindow = new EndlessTest();
    connect(endlessTestWindow, &EndlessTest::Test, this, &Test::show);
    endlessTestWindow -> show();
    this -> close();
}

void Test::on_limitedWordsTestButton_clicked()
{
    // Нужно запросить у пользователя кол-во слов
    limitedWordsTestWindow = new LimitedWordsTest();
    connect(limitedWordsTestWindow, &LimitedWordsTest::Test, this, &Test::show);
    limitedWordsTestWindow -> show();
    this -> close();
}

void Test::on_limitedMistakesTestButton_clicked()
{
    // Нужно запросить у пользователя кол-во ошибок
    limitedMistakesTestWindow = new LimitedMistakesTest();
    connect(limitedMistakesTestWindow, &LimitedMistakesTest::Test, this, &Test::show);
    limitedMistakesTestWindow -> show();
    this -> close();
}
