#ifndef ENGLISH_H
#define ENGLISH_H

#include "dictionary.h"
#include "learning.h"
#include "test.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class English;
}
QT_END_NAMESPACE

class English : public QMainWindow
{
    Q_OBJECT

public:
    English(QWidget *parent = nullptr);
    ~English();

private slots:
    void on_dictionaryButton_clicked();
    void on_learningButton_clicked();
    void on_testButton_clicked();

private:
    Ui::English *ui;
    Dictionary *dictionaryWindow;
    Learning *learningWindow;
    Test *testWindow;
};

#endif // ENGLISH_H
