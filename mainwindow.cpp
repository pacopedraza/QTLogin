#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include "dialog.h"

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
    if(var_user == "user" && var_pass == "pass")
    {
        Dialog window_loged;
        window_loged.exec();

    }else{
        QMessageBox::warning(this,"Error !", " User and/or pass incorrect!");//:/new/result/results/Results.txt
    }

}
