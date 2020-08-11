#pragma once
#include <vector>

using namespace std;

class MCTS {
public:
    int BestMove = 0;       // Best move is the move MCTS deems most likely to advance to win state from current state.
    vector<int> ValidMoves; // Create an empty vector for valid moves
    //OthelloBoard Board;     // board that is passed into MCTS class
    MCTS();

    /*
     * Assign a vector of valid moves
     */
    void getLegalMoves();

};

