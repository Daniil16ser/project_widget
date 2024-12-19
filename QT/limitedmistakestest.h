#ifndef LIMITEDMISTAKESTEST_H
#define LIMITEDMISTAKESTEST_H

#include <QMainWindow>

namespace Ui {
class LimitedMistakesTest;
}

class LimitedMistakesTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit LimitedMistakesTest(unsigned short mistakesLimit_, QWidget *parent = nullptr);
    ~LimitedMistakesTest();

signals:
    void Test();

private slots:
    void on_backButton_clicked();
    void on_checkButton_clicked();
    void on_nextButton_clicked();

private:
    Ui::LimitedMistakesTest *ui = nullptr;
    QString engWord;
    unsigned short mistakesLimit;
    unsigned short mistakesCounter = 0;
    unsigned short correctAnswersCounter = 0;
};

#endif // LIMITEDMISTAKESTEST_H
