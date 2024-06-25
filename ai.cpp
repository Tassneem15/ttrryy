#include "ai.h"
#include <algorithm>

bool TicTacToeAI::isMovesLeft(char board[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == '_')
                return true;
    return false;
}

int TicTacToeAI::evaluate(char board[3][3], char player, char opponent) {
    // Check rows and columns
    for (int row = 0; row < 3; ++row) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == player)
                return +10;
            else if (board[row][0] == opponent)
                return -10;
        }
    }
    for (int col = 0; col < 3; ++col) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == player)
                return +10;
            else if (board[0][col] == opponent)
                return -10;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == player)
            return +10;
        else if (board[0][0] == opponent)
            return -10;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == player)
            return +10;
        else if (board[0][2] == opponent)
            return -10;
    }
    return 0; // No winner
}

int TicTacToeAI::minimax(char board[3][3], int depth, int alpha, int beta, bool isMax, char player, char opponent) {
    int score = evaluate(board, player, opponent);
    if (score == 10 || score == -10 || !isMovesLeft(board))
        return score;
    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == '_') {
                    board[i][j] = player;
                    best = std::max(best, minimax(board, depth + 1, alpha, beta, !isMax, player, opponent));
                    alpha = std::max(alpha, best);
                    board[i][j] = '_';
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
                if (board[i][j] == '_') {
                    board[i][j] = opponent;
                    best = std::min(best, minimax(board, depth + 1, alpha, beta, !isMax, player, opponent));
                    beta = std::min(beta, best);
                    board[i][j] = '_';
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return best;
    }
}

Move TicTacToeAI::findBestMove(char board[3][3], char player, char opponent) {
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '_') {
                board[i][j] = player;
                int moveVal = minimax(board, 0, -1000, 1000, false, player, opponent);
                board[i][j] = '_';
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
