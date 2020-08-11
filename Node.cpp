#include "Node.h"
#include <string>

using namespace std;

Node::Node(OthelloBoard ParentState) {
    OthelloBoard BoardState = ParentState;  // new instance of the board with the requested move done.
}
void Node::PlayMove(int index) {
    BoardState.play_move(index);
}
void Node::PrintNode() {
    BoardState.print_board();
}
int Node::getEval(){
    return Eval;
}
int Node::getNumVisits(){
    return NumVisits;
}
int Node::updateNumVisits() {
    NumVisits++;
}
int Node::updateEval(int value) {
    NumVisits += value;
    return NumVisits;
}
