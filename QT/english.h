#ifndef ENGLISH_H
#define ENGLISH_H

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
    Ui::English *ui = nullptr;
};

#endif // ENGLISH_H
