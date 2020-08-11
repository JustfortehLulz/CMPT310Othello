#pragma once
#include "othello.h"


class Node {
private:
    OthelloBoard BoardState;
public:

    //initialization.
    Node(OthelloBoard ParentState);
    void PlayMove(int index);

    void PrintNode();
};

