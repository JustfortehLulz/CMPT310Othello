#pragma once
#include "othello.h"


class Node {
    OthelloBoard BoardState;
public:
    //initialization.
    Node(OthelloBoard ParentState, int index);

    void PrintNode();
};

