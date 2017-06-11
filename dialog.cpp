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

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
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
        int sum = var_num1.toInt() + var_num2.toInt();
        ui->lcdNumber->display(sum);
        QFile file("out.txt");

        if(!file.open(QIODevice::Append | QIODevice::Text))
            return;
        QTextStream out(&file);
        out << "Log sum: " << sum << "\n";


    }else if(ui->rbtn_resta->isChecked()){
        int res = var_num1.toInt() - var_num2.toInt();
        ui->lcdNumber->display(res);
        QFile file("out.txt");

        if(!file.open(QIODevice::Append | QIODevice::Text))
            return;
        QTextStream out(&file);
        out << "Log rest: " << res << "\n";

    }else if(ui->rbtn_multi->isChecked()){
        int multi = var_num1.toInt() * var_num2.toInt();
        ui->lcdNumber->display(multi);
        QFile file("out.txt");

        if(!file.open(QIODevice::Append | QIODevice::Text))
            return;
        QTextStream out(&file);
        out << "Log mult: " << multi << "\n";

    }else if(ui->rbtn_div->isChecked()){
        int div = var_num1.toInt() / var_num2.toInt();
        ui->lcdNumber->display(div);
        QFile file("out.txt");

        if(!file.open(QIODevice::Append | QIODevice::Text))
            return;
        QTextStream out(&file);
        out << "Log div: " << div << "\n";

    }
}

void Dialog::on_btnReset_clicked()
{
    ui->txtnum1->setText("");
    ui->txtnum2->setText("");
}
