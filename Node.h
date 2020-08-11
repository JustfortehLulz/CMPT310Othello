#pragma once

class Node {
    OthelloBoard Board;
public:
    //initialization.
    Node(OthelloBoard ParentState, int index);

    void PrintNode();
};

