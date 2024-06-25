#include "tic_tac_toe_ai.h"
#include "ui_tic_tac_toe_ai.h"
#include "mainmenu.h"
#include <QString>
#include <QRandomGenerator>
#include <QMessageBox>
#include <algorithm>

using namespace std;

int current_player_Ai = 0;
QPushButton *Grid_Ai[3][3];
char board[3][3];



tic_tac_toe_AI::tic_tac_toe_AI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tic_tac_toe_AI)
{
    ui->setupUi(this);

    // Adding icons
    QIcon btnhistory(":/images/employment-records.png");
    QIcon btnmainmenu(":/images/logout.png");
    QIcon btnreset(":/images/refresh.png");

    // Resize the icon (image) to a larger size
    QSize iconSize(35, 35);

    ui->pushButton_history->setIcon(btnhistory);
    ui->pushButton_mainmenu->setIcon(btnmainmenu);
    ui->pushButton_reset->setIcon(btnreset);

    // Set the button size to accommodate the icon
    ui->pushButton_history->setIconSize(iconSize);
    ui->pushButton_mainmenu->setIconSize(iconSize);
    ui->pushButton_reset->setIconSize(iconSize);

    // Setting Grid in Matrix For checkwin
    Grid_Ai[0][0] = ui->pushButton;
    Grid_Ai[0][1] = ui->pushButton_2;
    Grid_Ai[0][2] = ui->pushButton_3;
    Grid_Ai[1][0] = ui->pushButton_4;
    Grid_Ai[1][1] = ui->pushButton_5;
    Grid_Ai[1][2] = ui->pushButton_6;
    Grid_Ai[2][0] = ui->pushButton_7;
    Grid_Ai[2][1] = ui->pushButton_8;
    Grid_Ai[2][2] = ui->pushButton_9;

    resetgrid();
}

tic_tac_toe_AI::~tic_tac_toe_AI()
{
    delete ui;
}

// Check if moves are left
bool tic_tac_toe_AI::isMovesLeft(char b[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[i][j] == '_')
                return true;
    return false;
}

// Evaluate function
int tic_tac_toe_AI::evaluate(char b[3][3], char player, char opponent)
{
    // Check rows and columns
    for (int row = 0; row < 3; ++row) {
        if (b[row][0] == b[row][1] && b[row][1] == b[row][2]) {
            if (b[row][0] == player)
                return +10;
            else if (b[row][0] == opponent)
                return -10;
        }
    }
    for (int col = 0; col < 3; ++col) {
        if (b[0][col] == b[1][col] && b[1][col] == b[2][col]) {
            if (b[0][col] == player)
                return +10;
            else if (b[0][col] == opponent)
                return -10;
        }
    }
    // Check diagonals
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        if (b[0][0] == player)
            return +10;
        else if (b[0][0] == opponent)
            return -10;
    }
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        if (b[0][2] == player)
            return +10;
        else if (b[0][2] == opponent)
            return -10;
    }
    return 0; // No winner
}

// Minimax function with alpha-beta pruning
int tic_tac_toe_AI::minimax(char b[3][3], int depth, int alpha, int beta, bool isMax, char player, char opponent)
{
    int score = evaluate(b, player, opponent);

    if (score == 10 || score == -10 || !isMovesLeft(b))
        return score;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (b[i][j] == '_') {
                    b[i][j] = player;
                    best = max(best, minimax(b, depth + 1, alpha, beta, !isMax, player, opponent));
                    alpha = max(alpha, best);
                    b[i][j] = '_';
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (b[i][j] == '_') {
                    b[i][j] = opponent;
                    best = min(best, minimax(b, depth + 1, alpha, beta, !isMax, player, opponent));
                    beta = min(beta, best);
                    b[i][j] = '_';
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return best;
    }
}

// Function to find the best move using the minimax algorithm
Move tic_tac_toe_AI::findBestMove(char b[3][3], char player, char opponent)
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (b[i][j] == '_') {
                b[i][j] = player;
                int moveVal = minimax(b, 0, -1000, 1000, false, player, opponent);
                b[i][j] = '_';
                if (moveVal > bestVal) {
                    bestVal = moveVal;
                    bestMove.row = i;
                    bestMove.col = j;
                }
            }
        }
    }
    return bestMove;
}

void tic_tac_toe_AI::checkwin()
{
    for (int i = 0; i < 3; ++i) {
        if (Grid_Ai[i][0]->text() == Grid_Ai[i][1]->text() && Grid_Ai[i][1]->text() == Grid_Ai[i][2]->text() && !Grid_Ai[i][0]->text().isEmpty()) {
            // A player has won
            QString winner = Grid_Ai[i][0]->text();
            QMessageBox msgBox;
            msgBox.setWindowTitle("Result");
            msgBox.setText("Player " + winner + " wins!");
            msgBox.setStyleSheet("QLabel { color: red; font-size: 20px; }");
            msgBox.exec();
            resetgrid();
            return;
        }
        if (Grid_Ai[0][i]->text() == Grid_Ai[1][i]->text() && Grid_Ai[1][i]->text() == Grid_Ai[2][i]->text() && !Grid_Ai[0][i]->text().isEmpty()) {
            // A player has won
            QString winner = Grid_Ai[0][i]->text();
            QMessageBox msgBox;
            msgBox.setWindowTitle("Result");
            msgBox.setText("Player " + winner + " wins!");
            msgBox.setStyleSheet("QLabel { color: red; font-size: 20px; }");
            msgBox.exec();
            resetgrid();
            return;
        }
    }

    // Check diagonals for a win
    if (Grid_Ai[0][0]->text() == Grid_Ai[1][1]->text() && Grid_Ai[1][1]->text() == Grid_Ai[2][2]->text() && !Grid_Ai[0][0]->text().isEmpty()) {
        // A player has won
        QString winner = Grid_Ai[0][0]->text();
        QMessageBox msgBox;
        msgBox.setWindowTitle("Result");
        msgBox.setText("Player " + winner + " wins!");
        msgBox.setStyleSheet("QLabel { color: red; font-size: 20px; }");
        msgBox.exec();
        resetgrid();
        return;
    }
    if (Grid_Ai[0][2]->text() == Grid_Ai[1][1]->text() && Grid_Ai[1][1]->text() == Grid_Ai[2][0]->text() && !Grid_Ai[0][2]->text().isEmpty()) {
        // A player has won
        QString winner = Grid_Ai[0][2]->text();
        QMessageBox msgBox;
        msgBox.setWindowTitle("Result");
        msgBox.setText("Player " + winner + " wins!");
        msgBox.setStyleSheet("QLabel { color: red; font-size: 20px; }");
        msgBox.exec();
        resetgrid();
        return;
    }

    // Check for a draw
    bool isDraw = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (Grid_Ai[i][j]->text().isEmpty()) {
                isDraw = false;
                break;
            }
        }
    }
    if (isDraw) {
        // It's a draw
        QMessageBox msgBox;
        msgBox.setWindowTitle("Result");
        msgBox.setText("It's a Draw!");
        msgBox.setStyleSheet("QLabel { color: red; font-size: 20px; }");
        msgBox.exec();
        resetgrid();
        return;
    }

}

// Reseting the grid color and text
void tic_tac_toe_AI::resetgrid()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            Grid_Ai[i][j]->setText("");
            Grid_Ai[i][j]->setStyleSheet("background-color:rgb(7,245,189)");
            board[i][j] = '_';
        }
    }
    current_player_Ai = 0;
}

void tic_tac_toe_AI::makeAIMove()
{
    Move bestMove = findBestMove(board, 'O', 'X');
    if (bestMove.row != -1 && bestMove.col != -1) {
        Grid_Ai[bestMove.row][bestMove.col]->setText("O");
        Grid_Ai[bestMove.row][bestMove.col]->setStyleSheet("color:rgb(250,196,0); background-color:rgb(59,61,64); font-size: 80px;");
        board[bestMove.row][bestMove.col] = 'O';
        checkwin();
        current_player_Ai = 0; // Set player turn to human
    }
}

void tic_tac_toe_AI::playerMove(QPushButton* button)
{
    QString text = button->text();
    if (current_player_Ai == 0 && text == "")
    {
        button->setText("X");
        button->setStyleSheet("color:rgb(224,95,9); background-color:rgb(59,61,64); font-size: 80px;");
        int row = -1, col = -1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (Grid_Ai[i][j] == button) {
                    row = i;
                    col = j;
                    break;
                }
            }
        }
        if (row != -1 && col != -1) {
            board[row][col] = 'X';
        }
        checkwin();
        current_player_Ai = 1;
        makeAIMove(); // Call AI move
    }
}

// The grid
void tic_tac_toe_AI::on_pushButton_clicked() { playerMove(ui->pushButton); }
void tic_tac_toe_AI::on_pushButton_2_clicked() { playerMove(ui->pushButton_2); }
void tic_tac_toe_AI::on_pushButton_3_clicked() { playerMove(ui->pushButton_3); }
void tic_tac_toe_AI::on_pushButton_4_clicked() { playerMove(ui->pushButton_4); }
void tic_tac_toe_AI::on_pushButton_5_clicked() { playerMove(ui->pushButton_5); }
void tic_tac_toe_AI::on_pushButton_6_clicked() { playerMove(ui->pushButton_6); }
void tic_tac_toe_AI::on_pushButton_7_clicked() { playerMove(ui->pushButton_7); }
void tic_tac_toe_AI::on_pushButton_8_clicked() { playerMove(ui->pushButton_8); }
void tic_tac_toe_AI::on_pushButton_9_clicked() { playerMove(ui->pushButton_9); }

// End of grid

// Reseting the grid
void tic_tac_toe_AI::on_pushButton_reset_clicked() { resetgrid(); }

// Go back to main menu
void tic_tac_toe_AI::on_pushButton_mainmenu_clicked()
{
    this->hide();
    MainMenu *settings = new MainMenu();
    settings->setWindowTitle("Main Menu");
    settings->setWindowIcon(QIcon(":/images/icon3.png"));
    settings->show();
}
