#include "english.h"
#include "./ui_english.h"

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




void English::on_DICTIONARY_clicked()
{

    window = new Dictionary(this);
    window -> show();

}






void English::on_LEARNING_clicked()
{
    window1 = new Learning(this);
    window1 -> show();
}

