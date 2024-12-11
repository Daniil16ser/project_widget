#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QMainWindow>


namespace Ui {
class Dictionary;
}

class Dictionary : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dictionary(QWidget *parent = nullptr);
    ~Dictionary();

signals:
    void English();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dictionary *ui;

};

#endif // DICTIONARY_H
