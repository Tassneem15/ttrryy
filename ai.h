#ifndef AI_H
#define AI_H

struct Move {
    int row, col;
};

class TicTacToeAI {
public:
    static const int EMPTY = 0;

    Move findBestMove(char board[3][3], char player, char opponent);
    bool isMovesLeft(char board[3][3]);
    int evaluate(char board[3][3], char player, char opponent);
    int minimax(char board[3][3], int depth, int alpha, int beta, bool isMax, char player, char opponent);
};

#endif // AI_H
