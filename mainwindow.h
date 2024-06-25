#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMessageBox>
#include <QMainWindow>
#include"tic_tac_toe.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button_login_clicked();
    void on_button_sign_clicked();
    void on_button_cancel_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
