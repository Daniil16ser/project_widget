#include "english.h"
#include "./ui_english.h"
#include "learning.h"

English::English(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::English)
    , dictionaryWindow(new Dictionary())
    , testWindow(new Test())
{
    ui->setupUi(this);
    connect(dictionaryWindow, &Dictionary::English, this, &English::show);
    connect(testWindow, &Test::English, this, &English::show);
}

English::~English()
{
    delete dictionaryWindow;
    delete ui;
}

void English::on_dictionaryButton_clicked()
{
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
    testWindow -> show();
    this -> close();
}
