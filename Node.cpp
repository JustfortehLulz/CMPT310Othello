#include "Node.h"
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

//Node Node::TraverseToParent(Node ChildNode) {}

double Node::UCB1(){
    if (getNumVisits() == 0){return (float)INT_MAX;}
    double UCB1 = ExploitationVal() + ExplorationVal();
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
    if (ChildNodes.front() == NULL){return NULL;}
    int maxIndex = 0;
    double maxValue = ChildNodes.front()->UCB1();
    for(int i = 0 ; i < ChildNodes.size();i++ ){
        double currentUCB = ChildNodes.at(i)->UCB1();
        if (currentUCB >= maxValue) {
            maxValue = currentUCB;
            maxIndex = i;
        }
    }
    return maxIndex;
}

void Node::nodeExpansion(){
    srand(time(NULL));
    int UCB1choice = getUCB1Index();
    int randIndex;
    if(ChildNodes.at(UCB1choice)->getNumVisits() == 0){
        Node *newNode = new Node(*ChildNodes.at(UCB1choice));
        while (newNode->isTerminus() == false){
            vector<int> validMoves = newNode->BoardState.current_legal_moves();
            randIndex = rand() % validMoves.size();
            newNode->BoardState.play_move(validMoves[randIndex]);
            //newNode->BoardState.print_board();
            //newNode->BoardState.end_score();
        }
    }
    else{

    }
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
