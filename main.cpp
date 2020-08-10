#include <iostream>
#include <cstdlib>
#include "othello.h"

using namespace std;

int main(int argc, char const *argv[])
{

	vector<int> moves;
	int randIndex;

	OthelloBoard nice;
	cout << "-----------INTIAL BOARD-------------" << endl;
	nice.print_board();
	cout << "------------------------------------" << endl;


	for(int i = 1; i <= 10 ; i++)
	{
		cout << "-------------------- TURN " << i << "------------" << endl;
		if(i % 2 == 1)
		{
			cout << "Black Move" << endl;
			cout << "BLACK LEGAL MOVES" << endl;

			moves = nice.check_legal_moves(nice.movenum);
			for(auto j = moves.begin(); j != moves.end();++j)
			{
				cout << *j <<  " " << endl;
			}
			cout << endl;
			randIndex = rand() % moves.size();
			cout << endl;
			cout << "PLAYING THIS MOVE: " << moves[randIndex] << endl;
			nice.play_move(nice.movenum,moves[randIndex]);
			nice.print_board();
			moves.clear();
		}
		else if(i % 2 == 0)
		{
			cout << "White Move" << endl;
			cout << "WHITE LEGAL MOVES" << endl;

			moves = nice.check_legal_moves(nice.movenum);
			for(auto j = moves.begin(); j != moves.end();++j)
			{
				cout << *j <<  " " << endl;
			}
			cout << endl;
			randIndex = rand() % moves.size();
			cout << endl;
			cout << "PLAYING THIS MOVE: " << moves[randIndex] << endl;
			nice.play_move(nice.movenum,moves[randIndex]);
			nice.print_board();
			moves.clear();
		}
		cout << "--------------------------------------------------" << endl;
	}


	// cout << "Black Move" << endl;

	// cout << "BLACK LEGAL MOVES" << endl;

	// moves = nice.check_legal_moves(nice.movenum);
	// for(auto j = moves.begin(); j != moves.end();++j)
	// {
	// 	cout << *j <<  " " << endl;
	// }
	// moves.clear();
	// cout << endl;

	// //nice.print_array();

	// nice.play_move(nice.movenum,19);
	
	// cout << endl;


	// nice.print_board();
	
	// // cout << nice.movenum << endl;

	// cout << "WHITE LEGAL MOVES" << endl;
	// moves = nice.check_legal_moves(nice.movenum);
	// for(auto j = moves.begin(); j != moves.end();++j)
	// {
	// 	cout << *j <<  " " << endl;
	// }
	// moves.clear();
	// cout << endl;

	// // cout << "Player 2 is white" << endl;
	// nice.play_move(nice.movenum,18);

	// //cout << nice.movenum << endl;

	// cout << "BLACK LEGAL MOVES" << endl;
	// moves = nice.check_legal_moves(nice.movenum);
	// for(auto j = moves.begin(); j != moves.end();++j)
	// {
	// 	cout << *j <<  " " << endl;
	// }
	// moves.clear();
	// cout << endl;

	// nice.print_board();

	//nice.print_array();

	return 0;
}