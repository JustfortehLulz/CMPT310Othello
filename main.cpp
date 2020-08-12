#include <iostream>
#include <cstdlib>
#include <ctime>
#include "othello.h"
#include <algorithm>
#include <chrono>
#include "Node.h"
#define BLACK 0
#define WHITE 1

using namespace std;

int main(int argc, char const *argv[])
{
    Node *board = new Node();
    vector<int> moves;
    int num_turns = 0;

    srand(time(NULL));

    while (board->isTerminus() == false)
    {
        string current_turn = board->BoardState.get_turn();
        if (current_turn == "black")
        {
            cout << endl;
            cout << "AI 1 Turn " << num_turns << endl;
            auto current_time = std::chrono::high_resolution_clock::now();
            board->nodeExpansion();
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - current_time).count();
            cout << "Run time:      " << duration << " Micro seconds" << endl;
            board->makeOptimalMove(); //Vanilla MCTS Algorithm.
        }
        else if (current_turn == "white")
        {
            //white makes random moves in this block
//            moves = board->BoardState.white_legal_moves();
//            int randIndex = rand() % moves.size();
//            board->BoardState.play_move(moves.at(randIndex));

            //This block of code to run black as AI2
            cout << endl;
            cout << "AI 2 Turn " << num_turns << endl;
            auto current_time = std::chrono::high_resolution_clock::now();
            board->nodeExpansion();
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end_time - current_time ).count();
            cout << "Run time:      " << duration << " Micro seconds" << endl;
            board->makeOptimalRobustMove(); // modified MCTS Algorithm.
            //            cout << endl;
            //            cout << "AI 2 Turn." << endl;
            //            auto current_time = std::chrono::high_resolution_clock::now();
            //            board->nodeExpansion();
            //            auto end_time = std::chrono::high_resolution_clock::now();
            //            auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end_time - current_time ).count();
            //            cout << "Run time:      " << duration << " Micro seconds" << endl;
            //            board->makeOptimalRobustMove(); // modified MCTS Algorithm.

        }
        //        board->BoardState.print_board();
        //        cout << "Board State #: " << counter << endl;
        //        string isTerminus = board->BoardState.is_legal_moves() ? "FALSE" : "TRUE";
        //        cout << "Is Board State Terminus? " << isTerminus << endl;
        num_turns++;
    }
    //    board->BoardState.print_board();
    board->BoardState.print_end_score();
    double Value = board->BoardState.rolloutValue();
    if (Value > 0)
    {
        cout << "Winner->BLACK, val:    " << Value << endl;
    }
    else if (Value < 0)
    {
        cout << "Winner->WHITE, val:    " << Value << endl;
    }
    else if (Value == 0)
    {
        cout << "Tie, val:               " << Value << endl;
    }
    cout << endl;
    return 0;
}