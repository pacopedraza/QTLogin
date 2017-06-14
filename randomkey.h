#ifndef RANDOMKEY_H
#define RANDOMKEY_H

#include <QDialog>

namespace Ui {
class RandomKey;
}

class RandomKey : public QDialog
{
    Q_OBJECT

public:
    explicit RandomKey(QWidget *parent = 0);
    ~RandomKey();

private slots:

    void on_btn_generatekeys_clicked();

private:
    Ui::RandomKey *ui;
};

#endif // RANDOMKEY_H
