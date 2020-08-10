#include <iostream>
#include "othello.h"

using namespace std;

int main(int argc, char const *argv[])
{
	OthelloBoard nice;
	nice.print_board();


	cout << "Black Move" << endl;
	cout << "Player 1 is black" << endl;

	// cout << "BLACK LEGAL MOVES" << endl;

	// vector<int> moves = nice.check_legal_moves(nice.movenum);
	// for(auto j = moves.begin(); j != moves.end();++j)
	// {
	// 	cout << *j <<  " " << endl;
	// }
	// cout << endl;

	//nice.print_array();

	nice.play_move(nice.movenum,19);
	
	cout << endl;


	nice.print_board();
	
	//cout << nice.movenum << endl;

	// cout << "WHITE LEGAL MOVES" << endl;
	// vector<int> moves = nice.check_legal_moves(nice.movenum);
	// for(auto j = moves.begin(); j != moves.end();++j)
	// {
	// 	cout << *j <<  " " << endl;
	// }
	// cout << endl;

	// cout << "Player 2 is white" << endl;
	nice.play_move(nice.movenum,18);

	//cout << nice.movenum << endl;

	// cout << "BLACK LEGAL MOVES" << endl;
	// vector<int> moves = nice.check_legal_moves(nice.movenum);
	// for(auto j = moves.begin(); j != moves.end();++j)
	// {
	// 	cout << *j <<  " " << endl;
	// }
	// cout << endl;
	cout << endl;

	nice.print_board();

	//nice.print_array();

	return 0;
}