#include "dialog.h"
#include "ui_dialog.h"
#include <QtCore/QString>
#include <QtCore/QFile>
#include <QtCore/QDebug>
#include <QtCore/QTextStream>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QTimer>
#include <QDateTime>
#include "email.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(clock()));
    timer->start(1000);
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::clock()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    if((time.second() % 2) == 0)
    {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    ui->lbl_time->setText(time_text);
}

void Dialog::on_btnRead_clicked()
{
    QString str;
    QString var_num1 = ui->txtnum1->text();
    QString var_num2 = ui->txtnum2->text();
    if(ui->rbtn_suma->isChecked())
    {
        int sum = var_num1.toInt() + var_num2.toInt();
        ui->lcdNumber->display(sum);
    }
}

void Dialog::on_btnCalculate_clicked()
{

    QString var_num1 = ui->txtnum1->text();
    QString var_num2 = ui->txtnum2->text();


    // Suma check box
    if(ui->rbtn_suma->isChecked())
    {
        double sum = var_num1.toDouble() + var_num2.toDouble();
        ui->lcdNumber->display(sum);
        QFile file("out.txt");

        if(!file.open(QIODevice::Append | QIODevice::Text))
            return;
        QTextStream out(&file);
        QTime time = QTime::currentTime();
        QString time_text = time.toString("hh : mm : ss");
        out << "Log sum: " << sum << ", time: " << time_text << "\n";


    }else if(ui->rbtn_resta->isChecked()){
        double res = var_num1.toDouble() - var_num2.toDouble();
        ui->lcdNumber->display(res);
        QFile file("out.txt");

        if(!file.open(QIODevice::Append | QIODevice::Text))
            return;
        QTextStream out(&file);
        QTime time = QTime::currentTime();
        QString time_text = time.toString("hh : mm : ss");
        out << "Log res: " << res << ", time: " << time_text << "\n";

    }else if(ui->rbtn_multi->isChecked()){
        double multi = var_num1.toDouble() * var_num2.toDouble();
        ui->lcdNumber->display(multi);
        QFile file("out.txt");

        if(!file.open(QIODevice::Append | QIODevice::Text))
            return;
        QTextStream out(&file);
        QTime time = QTime::currentTime();
        QString time_text = time.toString("hh : mm : ss");
        out << "Log mul: " << multi << ", time: " << time_text << "\n";

    }else if(ui->rbtn_div->isChecked()){
        double div;
        div = var_num1.toDouble() / var_num2.toDouble();
        if(var_num2 == 0)
        {
            QMessageBox::warning(this,"Error !", " In div operations denominator must be different than zero!");
            ui->txtnum2->setText("");
        }else{
        ui->lcdNumber->display(div);
        QFile file("out.txt");

        if(!file.open(QIODevice::Append | QIODevice::Text))
            return;
        QTextStream out(&file);
        QTime time = QTime::currentTime();
        QString time_text = time.toString("hh : mm : ss");
        out << "Log div: " << div << ", time: " << time_text << "\n";
        }

    }
}

void Dialog::on_btnReset_clicked()
{
    ui->txtnum1->setText("");
    ui->txtnum2->setText("");
}


void Dialog::on_btnSendEmail_clicked()
{
    Email window_email;
    window_email.exec();
}

void Dialog::on_btnDeleteData_clicked()
{

    QMessageBox::StandardButton answer = QMessageBox::question(this,"Do you want to erase data?",
                                                               "The data will be erased",
                                         QMessageBox::StandardButton::No | QMessageBox::StandardButton::Yes);
    if(answer == QMessageBox::StandardButton::Yes)
    {
        QFile file("out.txt");

        if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
            return;
    }



}
