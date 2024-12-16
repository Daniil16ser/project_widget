#ifndef LIMITEDWORDSTEST_H
#define LIMITEDWORDSTEST_H

#include <QMainWindow>

namespace Ui {
class LimitedWordsTest;
}

class LimitedWordsTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit LimitedWordsTest(QWidget *parent = nullptr);
    ~LimitedWordsTest();

signals:
    void Test();

private slots:
    void on_backButton_clicked();
    void on_checkButton_clicked();
    void on_nextButton_clicked();

private:
    Ui::LimitedWordsTest *ui;
    QString engWord;
    unsigned short wordsLimit = 10;
    unsigned short wordsCounter = 1;
    unsigned short correctAnswersCounter = 0;
};

#endif // LIMITEDWORDSTEST_H
