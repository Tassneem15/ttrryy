#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include <QPushButton>
#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class TIC_TAC_TOE;
}

class TIC_TAC_TOE : public QMainWindow
{
    Q_OBJECT

public:
    explicit TIC_TAC_TOE(QWidget *parent = nullptr);
    ~TIC_TAC_TOE();

private :
    QPushButton *Grid[3][3];

public:
    void checkwin();
    void resetgrid();
    void playerMove(QPushButton* button);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();


    void on_pushButton_reset_clicked();
    void on_pushButton_mainmenu_clicked();

private:
    Ui::TIC_TAC_TOE *ui;
};

#endif // TIC_TAC_TOE_H
