#ifndef LEARNING_H
#define LEARNING_H

#include <QMainWindow>

namespace Ui {
class Learning;
}

class Learning : public QMainWindow
{
    Q_OBJECT

public:
    explicit Learning(QWidget *parent = nullptr);
    ~Learning();

private:
    Ui::Learning *ui;
};

#endif // LEARNING_H
