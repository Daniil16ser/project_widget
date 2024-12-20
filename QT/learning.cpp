#include "learning.h"
#include "ui_learning.h"
#include "database3.h"

Learning::Learning(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Learning)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    //parsik = store.getRandomPairs(1)[0];
    //ui->engWordLabel->setText(parsik.first);
}

Learning::~Learning()
{
    delete ui;
}

void Learning::on_backButton_clicked()
{
    this -> close();
    emit English();
}

void Learning::on_showButton_clicked()
{
    if (ui->showButton->text() == "Show Translation") {
        ui->showButton->setText("Hide Translation");
        //ui->rusWordLabel->setText(parsik.second);
    } else {
        ui->showButton->setText("Show Translation");
        ui->rusWordLabel->clear();
    }
}

void Learning::on_nextButton_clicked()
{
    //parsik = store.getRandomPairs(1)[0];
    //ui->engWordLabel->setText(parsik.first);
    ui->rusWordLabel->clear();
    ui->showButton->setText("Show Translation");
}
