#pragma once
#include "othello.h"


class Node {
private:
    OthelloBoard BoardState;
public:
    int Eval;           //Value of the node
    int NumVisits;      //Number of times the node has been visited

    //initialization.
    Node(OthelloBoard ParentState);
    void PlayMove(int index);

    void PrintNode();
    int getEval();
    int getNumVisits();
    void updateEval(int value);
    void incrementNumVisits();
};

