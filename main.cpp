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
    Node *board = new Node();
    vector<int> moves;
    int counter = 0;
    int randIndex;

    srand(time(NULL));

    while (board->isTerminus() == false){
        string current_turn = board->BoardState.get_turn();
        if(current_turn == "black"){
            board->nodeExpansion();
            board->makeOptimalMove();
        }
        else if(current_turn == "white"){
            moves = board->BoardState.white_legal_moves();
            int randIndex = rand() % moves.size();
            board->BoardState.play_move(moves.at(randIndex));
        }
        board->BoardState.print_board();
        cout << "Board State #: " << counter << endl;
        string isTerminus = board->BoardState.is_legal_moves() ? "TRUE" : "FALSE";
        cout << "Is Board State Terminus? " << isTerminus << endl;
        board->BoardState.end_score();
        counter++;
    }

//    cout << "-----------INITIAL BOARD-------------" << endl;
//    Board.print_board();
//    cout << "------------------------------------" << endl;
//
//
//    for (int i = 1; i <= 60; i++)
//    {
//        if (P1moves || P2moves) {
//            cout << "-------------------- TURN " << i << "------------" << endl;
//            if (Board.get_turn() == "black") {
//                cout << "Black Move" << endl;
//                cout << "BLACK LEGAL MOVES" << endl;
//
//                moves = Board.check_legal_moves(BLACK);
//                for (auto j = moves.begin(); j != moves.end(); ++j) {
//                    cout << *j << " " << endl;
//                }
//                cout << endl;
//                if (!(moves.empty())) {
//                    randIndex = rand() % moves.size();
//                    cout << endl;
//                    cout << "PLAYING THIS MOVE: " << moves[randIndex] << endl;
//                    Board.play_move(moves[randIndex]);
//                    Board.print_board();
//                    Board.end_score();
//                    P1moves = true;
//                }
//                else {
//                    Board.movenum++;
//                    P1moves = false;
//                }
//                moves.clear();
//            }
//            else if (Board.get_turn() == "white") {
//                cout << "White Move" << endl;
//                cout << "WHITE LEGAL MOVES" << endl;
//
//                moves = Board.check_legal_moves(WHITE);
//                for (auto j = moves.begin(); j != moves.end(); ++j) {
//                    cout << *j << " " << endl;
//                }
//                cout << endl;
//                if (!(moves.empty())) {
//                    randIndex = rand() % moves.size();
//                    cout << endl;
//                    cout << "PLAYING THIS MOVE: " << moves[randIndex] << endl;
//                    Board.play_move(moves[randIndex]);
//                    Board.print_board();
//                    Board.end_score();
//                    P2moves = true;
//                }
//                else {
//                    Board.movenum++;
//                    P2moves = false;
//                }
//                moves.clear();
//            }
//            cout << "----------------------------------------" << endl;
//        }
//        else {
//            cout << "No more legal moves for both players" << endl;
//            break;
//        }
//
//    }
//
//    string winner = Board.calculate_winner();
//
//    if (winner == "black")
//    {
//        cout << "Black Wins!" << endl;
//    }
//    else if (winner == "white")
//    {
//        cout << "White Wins!" << endl;
//    }
//    else if (winner == "draw")
//    {
//        cout << "It's a Draw" << endl;
//    }
//    cout << "Test Node: "   << endl;


    return 0;
}