#ifndef EMAIL_H
#define EMAIL_H

#include <QDialog>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include<QtWidgets/QMessageBox>
#include <QByteArray>




namespace Ui {
class Email;
}

class Email : public QDialog
{
    Q_OBJECT

public:
    explicit Email(QWidget *parent = 0);
      ~Email();



private slots:

    void on_btnSendEmail_clicked();

private:
    Ui::Email *ui;

};

#endif // EMAIL_H
