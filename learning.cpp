#include "learning.h"
#include "ui_learning.h"

Learning::Learning(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Learning)
{
    ui->setupUi(this);
}

Learning::~Learning()
{
    delete ui;
}
