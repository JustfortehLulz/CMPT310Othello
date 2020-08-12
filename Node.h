#pragma once
#include "othello.h"
#include <vector>

class Node
{
public:
    OthelloBoard BoardState;

    int Eval = 0;      //Value of the node
    int NumVisits = 0; //Number of times the node has been visited
    Node *ParentNodePtr;
    vector<Node *> ChildNodes; //Vector of Child Nodes from all legal moves on parent node

    //initialization.
    Node();
    Node(Node &ParentNode);
    Node(OthelloBoard &StartState);

    void PlayMove(int index);

    void PrintNode();

    double getEval();

    int getNumVisits();

    void updateEval(double value);

    void incrementNumVisits();

    unsigned int getUCB1Index();

    unsigned int getUCB1MaxChildIndex();

    void makeOptimalMove();

    void makeOptimalRobustMove();

    void nodeExpansion();

    double UCB1();

    double ExploitationVal();

    double ExplorationVal();

    void spawnChildren();

    void printChildren();

    /* Check if the game has reached end game state.*/
    bool isTerminus();

    bool isIndexInBounds();
};
