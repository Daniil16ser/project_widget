#include "english.h"
#include "./ui_english.h"
#include "dictionary.h"
#include "learning.h"
#include "test.h"

English::English(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::English)
{
    ui->setupUi(this);
}

English::~English()
{
    delete ui;
}

void English::on_dictionaryButton_clicked()
{
    Dictionary *dictionaryWindow = new Dictionary();
    connect(dictionaryWindow, &Dictionary::English, this, &English::show);
    dictionaryWindow -> show();
    this -> close();
}

void English::on_learningButton_clicked()
{
    Learning *learningWindow = new Learning();
    connect(learningWindow, &Learning::English, this, &English::show);
    learningWindow -> show();
    this -> close();
}

void English::on_testButton_clicked()
{
    Test *testWindow = new Test();
    connect(testWindow, &Test::English, this, &English::show);
    testWindow -> show();
    this -> close();
}
