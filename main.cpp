#include <iostream>
#include <cstdlib>
#include <ctime>
#include "othello.h"
#include <algorithm>
#include "Node.h"
#define BLACK 0
#define WHITE 1


using namespace std;

int main(int argc, char const *argv[])
{
    Node *rootNode = new Node();
    Node *ChildNode = new Node(*rootNode);
    ChildNode->nodeExpansion();
    OthelloBoard TestNodeBoard;
    bool P1moves = true;
    bool P2moves = true;
    vector<int> moves;
    int randIndex;

    srand(time(NULL));
    OthelloBoard Board;

    while ()

    cout << "-----------INITIAL BOARD-------------" << endl;
    Board.print_board();
    cout << "------------------------------------" << endl;


    for (int i = 1; i <= 60; i++)
    {
        if (P1moves || P2moves) {
            cout << "-------------------- TURN " << i << "------------" << endl;
            if (Board.get_turn() == "black") {
                cout << "Black Move" << endl;
                cout << "BLACK LEGAL MOVES" << endl;

                moves = Board.check_legal_moves(BLACK);
                for (auto j = moves.begin(); j != moves.end(); ++j) {
                    cout << *j << " " << endl;
                }
                cout << endl;
                if (!(moves.empty())) {
                    randIndex = rand() % moves.size();
                    cout << endl;
                    cout << "PLAYING THIS MOVE: " << moves[randIndex] << endl;
                    Board.play_move(moves[randIndex]);
                    Board.print_board();
                    Board.end_score();
                    P1moves = true;
                }
                else {
                    Board.movenum++;
                    P1moves = false;
                }
                moves.clear();
            }
            else if (Board.get_turn() == "white") {
                cout << "White Move" << endl;
                cout << "WHITE LEGAL MOVES" << endl;

                moves = Board.check_legal_moves(WHITE);
                for (auto j = moves.begin(); j != moves.end(); ++j) {
                    cout << *j << " " << endl;
                }
                cout << endl;
                if (!(moves.empty())) {
                    randIndex = rand() % moves.size();
                    cout << endl;
                    cout << "PLAYING THIS MOVE: " << moves[randIndex] << endl;
                    Board.play_move(moves[randIndex]);
                    Board.print_board();
                    Board.end_score();
                    P2moves = true;
                }
                else {
                    Board.movenum++;
                    P2moves = false;
                }
                moves.clear();
            }
            cout << "----------------------------------------" << endl;
        }
        else {
            cout << "No more legal moves for both players" << endl;
            break;
        }

    }

    string winner = Board.calculate_winner();

    if (winner == "black")
    {
        cout << "Black Wins!" << endl;
    }
    else if (winner == "white")
    {
        cout << "White Wins!" << endl;
    }
    else if (winner == "draw")
    {
        cout << "It's a Draw" << endl;
    }
    cout << "Test Node: "   << endl;


    return 0;
}