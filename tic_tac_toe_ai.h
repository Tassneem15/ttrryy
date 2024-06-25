#ifndef TIC_TAC_TOE_AI_H
#define TIC_TAC_TOE_AI_H
#include "ai.h"
#include <QPushButton>
#include <QMainWindow>
#include <QMessageBox>
#include <QMainWindow>

namespace Ui {
class tic_tac_toe_AI;
}

class tic_tac_toe_AI : public QMainWindow
{
    Q_OBJECT

public:
    explicit tic_tac_toe_AI(QWidget *parent = nullptr);
    ~tic_tac_toe_AI();

private :
    QPushButton *Grid[3][3];



public:
    void checkwin();
    void resetgrid();
    void makeAIMove();
    void playerMove(QPushButton* button);
    int evaluate(char b[3][3], char player, char opponent);
    bool isMovesLeft(char b[3][3]);
    int minimax(char b[3][3], int depth, int alpha, int beta, bool isMax, char player, char opponent);
    Move findBestMove(char b[3][3], char player, char opponent);

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
    Ui::tic_tac_toe_AI *ui;
};

#endif // TIC_TAC_TOE_AI_H
