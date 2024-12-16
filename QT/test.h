#ifndef TEST_H
#define TEST_H

#include <QMainWindow>

namespace Ui {
class Test;
}

class Test : public QMainWindow
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = nullptr);
    ~Test();

signals:
    void English();

private slots:
    void on_backButton_clicked();
    void on_endlessTestButton_clicked();
    void on_limitedWordsTestButton_clicked();
    void on_limitedMistakesTestButton_clicked();

private:
    Ui::Test *ui = nullptr;
};

#endif // TEST_H
