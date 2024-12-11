#ifndef ENGLISH_H
#define ENGLISH_H

#include <QMainWindow>
#include "dictionary.h"
#include "learning.h"


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


    void on_DICTIONARY_clicked();


    void on_LEARNING_clicked();

private:
    Ui::English *ui;
    Dictionary *window;
    Learning *window1;

};
#endif // ENGLISH_H
