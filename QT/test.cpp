#include "test.h"
#include "ui_test.h"
#include "endlesstest.h"
#include "limitedwordstest.h"
#include "limitedmistakestest.h"
#include <QInputDialog>

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
    delete this;
}

void Test::on_endlessTestButton_clicked()
{
    EndlessTest *endlessTestWindow = new EndlessTest();
    connect(endlessTestWindow, &EndlessTest::Test, this, &Test::show);
    endlessTestWindow -> show();
    this -> close();
}

void Test::on_limitedWordsTestButton_clicked()
{
    bool ok;
    unsigned short wordsLimit = QInputDialog::getInt(this, "Number of Words",
                                                     "Enter the number of words the test will contain",
                                                     10, 1, 100, 1, &ok);
    if (ok) {
    LimitedWordsTest *limitedWordsTestWindow = new LimitedWordsTest(wordsLimit);
    connect(limitedWordsTestWindow, &LimitedWordsTest::Test, this, &Test::show);
    limitedWordsTestWindow -> show();
    this -> close();
    }
}

void Test::on_limitedMistakesTestButton_clicked()
{
    bool ok;
    unsigned short mistakesLimit = QInputDialog::getInt(this, "Number of Mistakes",
                                                     "Enter the maximum allowed mistakes",
                                                     3, 1, 50, 1, &ok);
    if (ok) {
    LimitedMistakesTest *limitedMistakesTestWindow = new LimitedMistakesTest(mistakesLimit);
    connect(limitedMistakesTestWindow, &LimitedMistakesTest::Test, this, &Test::show);
    limitedMistakesTestWindow -> show();
    this -> close();
    }
}
