#include "learning.h"
#include "ui_learning.h"

Learning::Learning(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Learning)
{
    ui->setupUi(this);
    QString nextWord = "AAAAA"; // Нужно реализовать функцию, возвращающую новое слово для перевода из БД
    rusWord = "AAAAA"; // Нужно реализовать функцию, возвращающую перевод слова из БД
    ui->engWordLabel->setText(nextWord);
}

Learning::~Learning()
{
    delete ui;
}

void Learning::on_backButton_clicked()
{
    this -> close();
    emit English();
    delete this;
}

void Learning::on_showButton_clicked()
{
    if (ui->showButton->text() == "Show Translation") {
        ui->showButton->setText("Hide Translation");
        ui->rusWordLabel->setText(rusWord);
    } else {
        ui->showButton->setText("Show Translation");
        ui->rusWordLabel->setText("");
    }
}

void Learning::on_nextButton_clicked()
{
    QString engWord = ui->engWordLabel->text();
    QString nextWord = "BBBBB"; // Нужно реализовать функцию, возвращающую новое слово для перевода из БД
    rusWord = "BBBBB"; // Нужно реализовать функцию, возвращающую перевод слова из БД
    ui->engWordLabel->setText(nextWord);
    ui->rusWordLabel->setText("");
    ui->showButton->setText("Show Translation");
}
