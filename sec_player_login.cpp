#include "sec_player_login.h"
#include "ui_sec_player_login.h"
#include "tic_tac_toe.h"
#include "mainmenu.h"
#include <QMessageBox>
sec_player_login::sec_player_login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sec_player_login)
{
    ui->setupUi(this);

    //set icon and title for window
    setWindowTitle("TIC_TAC_TOE");
    setWindowIcon(QIcon(":/images/icon3.png"));
    setWindowFlag(Qt::FramelessWindowHint);

}

sec_player_login::~sec_player_login()
{
    delete ui;
}

void sec_player_login::on_Button_login_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();

    //checking name and password
    if ((username == "hossam" && password == "123")||(username == "john" && password == "123")||
        (username == "peter" && password == "123")||(username == "joo" && password == "123")||
        (username == "tasneem" && password == "123"))
    {
        this->hide();
        TIC_TAC_TOE *grid = new TIC_TAC_TOE();
        grid ->setWindowTitle("TIC TAC TOE Match");
        grid ->setWindowIcon(QIcon(":/images/icon3.png"));
        grid->show();
    }
    else
    {
        QMessageBox::warning(this,"TIC TAC TOE","wrong username or password");

    }

}


void sec_player_login::on_button_cancel_clicked()
{
    this->hide();
    MainMenu *settings = new MainMenu();
    settings ->setWindowTitle("Main Menu");
    settings ->setWindowIcon(QIcon(":/images/icon3.png"));
    settings->show();
}


