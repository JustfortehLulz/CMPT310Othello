#include <iostream>
#include <cstdlib>
#include <ctime>
#include "othello.h"
#include "MCTS.h"
#include <algorithm>
#include "Node.h"


using namespace std;

int main(int argc, char const *argv[])
{
    OthelloBoard TestNodeBoard;
    bool P1moves = true;
    bool P2moves = true;
    vector<int> moves;
    int randIndex;

    srand(time(NULL));
    OthelloBoard Board;

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

                moves = Board.check_legal_moves();
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

                moves = Board.check_legal_moves();
                for (auto j = moves.begin(); j != moves.end(); ++j) {
                    cout << *j << " " << endl;
                }
                cout << endl;
                if (!(moves.empty())) {
                    int move = 0;
                    //cin >> move;
                    randIndex = rand() % moves.size();
                    cout << endl;
                    cout << "PLAYING THIS MOVE: " << moves[randIndex] << endl;
                    Board.play_move(moves[randIndex]);
                    /*
                     * Find the index with the value move in the moves vector.
                     */
                     //vector<int>::iterator value=find(moves.begin(), moves.end(), move);
                     //int index = distance(moves.begin(), value);
                     //cout << "PLAYING THIS MOVE: " << move << " AT INDEX: "<< index << endl;
                     //Board.play_move( move);
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

    Node TestNode(TestNodeBoard, 20);
    cout << "Test Node: " << TestNodeBoard.boardArr << "&" << TestNodeBoard.movenum << endl;
    return 0;
}