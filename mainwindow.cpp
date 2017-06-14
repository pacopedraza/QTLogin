#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include "dialog.h"
#include "randomkey.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap picture(":/imgs/login_icon_y.png");
    ui->label->setPixmap(picture.scaled(300,700, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLogin_clicked()
{
    this->hide();
    QString var_user = ui->txtUser->text();
    QString var_pass = ui->txt_pass->text();

    QFile file (":/MyPreciousRes/log.txt");
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"Error opening key file",file.errorString());
    QTextStream in(&file);

    if(var_user == "user" && var_pass == in.readLine(16))
        {
            Dialog window_loged;
            window_loged.exec();

        }else{
            QMessageBox::warning(this,"Error !", " User and/or pass incorrect!");
            this->show();
        }
}

void MainWindow::on_btn_callGenerateKey_clicked()
{
    RandomKey random_window;
    random_window.exec();
}
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            

