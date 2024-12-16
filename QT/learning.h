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

signals:
    void English();

private slots:
    void on_backButton_clicked();
    void on_showButton_clicked();
    void on_nextButton_clicked();

private:
    Ui::Learning *ui = nullptr;
    QString rusWord;
};

#endif // LEARNING_H
