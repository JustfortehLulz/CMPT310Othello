#include "Node.h"
#include <iostream>
#include <string>
#include "math.h"
#include <ctime>

using namespace std;

Node::Node() {
    ParentNodePtr = NULL;
    BoardState = *new OthelloBoard();
}
Node::Node(Node &ParentNode) {
    ParentNodePtr = &ParentNode;
    BoardState = ParentNode.BoardState;  // new instance of the board with the requested move done.
}

Node::Node(OthelloBoard &StartState) {
    ParentNodePtr = NULL;

    BoardState = StartState;  // new instance of the board with the requested move done.
}
void Node::PlayMove(int index) {
    BoardState.play_move(index);
}
void Node::PrintNode() {
    BoardState.print_board();
}
double Node::getEval() {
    return Eval;
}
int Node::getNumVisits() {
    return NumVisits;
}
void Node::updateEval(double value) {
    Eval += value;
}
void Node::incrementNumVisits() {
    NumVisits++;
}

double Node::UCB1(){
    if (getNumVisits() == 0){return (double)INT_MAX;}
    double UCB1 = ExploitationVal() + ExplorationVal();
    UCB1 = UCB1/(double)getNumVisits();
    return UCB1;
}

double Node::ExploitationVal(){
    double Value = ((double)getEval()/(double)getNumVisits());
    return Value;
}

double Node::ExplorationVal(){
    const double C = 2;
    double ParentVisits = ParentNodePtr->getNumVisits();
    double exp = (log(ParentVisits)/(double)getNumVisits());
    exp = sqrt(exp);
    exp = C*exp;
    return exp;

}
int Node::getUCB1Index() {
    int maxIndex = 0;
    if (ChildNodes.size() == 0){
        spawnChildren();
    }
    double maxValue = ChildNodes.front()->UCB1();
    for(int i = 0 ; i < ChildNodes.size();i++ ){
        double currentUCB = ChildNodes.at(i)->UCB1();
        if (currentUCB >= maxValue) {
            maxValue = currentUCB;
            maxIndex = i;
        }
        if (maxIndex >= BoardState.current_legal_moves().size()){
            maxIndex = 0;
        }
    }
    return maxIndex;
}

int Node::getUCB1MaxChildIndex() {
    int maxIndex = 0;
    if (ChildNodes.size() == 0){
        spawnChildren();
    }
    double maxValue = ChildNodes.front()->getNumVisits();
    for(int i = 0 ; i < ChildNodes.size();i++ ){
        double currentUCB = ChildNodes.at(i)->getNumVisits();
        if (currentUCB >= maxValue) {
            maxValue = currentUCB;
            if ((currentUCB && maxValue)!= 0) {
                maxIndex = i;
            }
        }
        if (maxIndex >= BoardState.current_legal_moves().size()){
            maxIndex = 0;
        }
    }
    return maxIndex;
}
bool Node::isIndexInBounds() {
    vector<int> ValidMoves = BoardState.current_legal_moves();
    if(getUCB1Index() >= ValidMoves.size()){
        cout << "UCB1 Index: " << getUCB1Index() << " Valid Moves Size: " << ValidMoves.size() << endl;
        return false;
    }
    return true;
}

void Node::makeOptimalMove(){
    int maxIndex = getUCB1Index();
    vector<int> ValidMoves = BoardState.current_legal_moves();
    if (!isIndexInBounds()){
        cout << "UCB1 Index out of bounds" << endl;
    }
    BoardState.play_move(ValidMoves.at(maxIndex));
}

void Node::makeOptimalRobustMove() {
    int maxChildIndex = getUCB1MaxChildIndex();
    vector<int> ValidMoves = BoardState.current_legal_moves();
    if (!isIndexInBounds()){
        cout << "UCB1 Index out of bounds" << endl;
    }
    BoardState.play_move(ValidMoves.at(maxChildIndex));
}

void Node::nodeExpansion(){
    int Param = 700;
    int counter = 0;
    srand(time(NULL));
    int NumberOfPlayouts = 0;
    while(counter <= Param){
        int UCB1choice = getUCB1Index();
        int randIndex;
        int value;
        if(ChildNodes.size() > 0 && ChildNodes.at(UCB1choice)->getNumVisits() == 0){ // Roll out
            OthelloBoard *newBoard = new OthelloBoard(BoardState);

            //Node *newNode = new Node(*ChildNodes.at(UCB1choice));
            while (newBoard->is_legal_moves() == true){
                vector<int> validMoves = newBoard->current_legal_moves();
                if (validMoves.size() != 0 ){
                    randIndex = rand() % validMoves.size();
                    newBoard->play_move(validMoves[randIndex]);
                    NumberOfPlayouts++;
                }
//                if(difftime(start_time,time(NULL) >= timeParam)){
//                    break;
//                }
                //newNode->BoardState.print_board();
                //newNode->BoardState.end_score();
                value = newBoard->rolloutValue();
            }
            Node nodeCopy = *this;
            while(nodeCopy.ParentNodePtr != NULL){  //Backpropogation
                nodeCopy.updateEval(value);
                nodeCopy.incrementNumVisits();
                nodeCopy = *nodeCopy.ParentNodePtr;
            }
            nodeCopy.updateEval(value);
            incrementNumVisits();
        }
        else{ // Expand nodes
            spawnChildren();
        }
        counter++;
    }
    cout << "Num Play-outs: " << NumberOfPlayouts << endl;
}

void Node::spawnChildren(){
    vector<int> ValidMoves = BoardState.current_legal_moves();
    for (auto & move : ValidMoves){
        Node* newNode = new Node(*this);
        newNode->PlayMove(move);
        ChildNodes.push_back(newNode);
    }
}
void Node::printChildren(){
    for (auto & child : ChildNodes){
        child->PrintNode();
    }
}

bool Node::isTerminus(){
    return not BoardState.is_legal_moves();
}
