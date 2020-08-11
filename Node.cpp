#include "Node.h"
#include <string>

using namespace std;

Node::Node(OthelloBoard ParentState, int index) {
    OthelloBoard BoardState = ParentState;  // new instance of the board with the requested move done.
    BoardState.play_move(index);
}
void Node::PrintNode() {
    BoardState.print_board();
}
