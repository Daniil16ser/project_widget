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
    void on_backButton_clicked();
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_changeButton_clicked();

private:
    Ui::Dictionary *ui = nullptr;
};

#endif // DICTIONARY_H
