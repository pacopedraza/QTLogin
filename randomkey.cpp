#include "randomkey.h"
#include "ui_randomkey.h"
#include <QStringList>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "mainwindow.h"


RandomKey::RandomKey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandomKey)
{
    ui->setupUi(this);
    QPixmap picture(":/imgs/encryption_1.png");
        ui->lblKey->setPixmap(picture.scaled(30,30, Qt::KeepAspectRatio));
}

RandomKey::~RandomKey()
{
    delete ui;
}

void RandomKey::on_btn_generatekeys_clicked()
{
    QFile file (":/MyPreciousRes/log.txt");
    if(!file.open(QIODevice::ReadOnly))
        //extern QString key;
        QMessageBox::information(0,"Error opening key file",file.errorString());
    QTextStream in(&file);

    ui->textBrowser->setText(in.readLine(4));
    ui->textBrowser_2->setText(in.readLine(4));
    ui->textBrowser_3->setText(in.readLine(4));
    ui->textBrowser_4->setText(in.readLine(4));
}
