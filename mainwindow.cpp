#include "mainwindow.h"
#include "mainmenu.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("TIC_TAC_TOE");
    setWindowIcon(QIcon(":/images/icon3.png"));
    setWindowFlag(Qt::FramelessWindowHint);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_login_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();
    if ((username == "hossam" && password == "123")||(username == "john" && password == "123")||
        (username == "peter" && password == "123")||(username == "joo" && password == "123")||
        (username == "tasneem" && password == "123"))
    {
        this->hide();
        MainMenu *settings = new MainMenu();
        settings ->setWindowTitle("Main Menu");
        settings ->setWindowIcon(QIcon(":/images/icon3.png"));
        settings->show();

    }
    else
    {
        QMessageBox::warning(this,"TIC TAC TOE","wrong username or password");

    }


}


void MainWindow::on_button_sign_clicked()
{

}


void MainWindow::on_button_cancel_clicked()
{
    QMessageBox::StandardButton reply;
    reply= QMessageBox::question(this,"TIC TAC TOE","Are you sure you want to close the game",QMessageBox::Yes | QMessageBox::No);
    if (QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else
    {
        QMessageBox::information(this,"TIC TAC TOE","Ok");
    }

}



