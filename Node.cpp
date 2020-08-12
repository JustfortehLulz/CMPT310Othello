#include "Node.h"
#include <string>

using namespace std;

Node::Node(){
    ParentNodePtr = NULL;
    BoardState = *new OthelloBoard();
}
Node::Node(Node &ParentNode) {
    ParentNodePtr = &ParentNode;

    BoardState = ParentNode.BoardState;  // new instance of the board with the requested move done.
    //vector<int> moves = BoardState.check_legal_moves();
}
void Node::PlayMove(int index) {
    BoardState.play_move(index);
}
void Node::PrintNode() {
    BoardState.print_board();
}
double Node::getEval(){
    return Eval;
}
int Node::getNumVisits(){
    return NumVisits;
}
void Node::updateEval(double value) {
    Eval += value;
}
void Node::incrementNumVisits() {
    NumVisits++;
}
Node Node::searchChildNodes(vector<Node*> ChildNodes, int ChildNodePointer){

    //return *NodePointer;
}

Node Node::TraverseToParent(Node ChildNode) {
    Node Parent = ChildNode; // not working yet
    return Parent;
}

int Node::TraverseToChild(Node ParentNode) {
    //use ChildNode pointer Vector
    //ChildNodes = ParentNode.ChildNodes;
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
