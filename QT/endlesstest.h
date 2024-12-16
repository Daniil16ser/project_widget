#ifndef ENDLESSTEST_H
#define ENDLESSTEST_H

#include <QMainWindow>

namespace Ui {
class EndlessTest;
}

class EndlessTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit EndlessTest(QWidget *parent = nullptr);
    ~EndlessTest();

signals:
    void Test();

private slots:
    void on_backButton_clicked();
    void on_checkButton_clicked();
    void on_nextButton_clicked();

private:
    Ui::EndlessTest *ui = nullptr;
    QString engWord;
};

#endif // ENDLESSTEST_H
