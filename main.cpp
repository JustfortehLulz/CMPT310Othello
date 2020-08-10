#include <iostream>
#include "othello.h"

using namespace std;

int main(int argc, char const *argv[])
{
	OthelloBoard nice;
	nice.print_board();


	cout << "Black Move" << endl;
	cout << "Player 1 is black" << endl;

	nice.check_legal_moves(nice.movenum);

	nice.play_move(19,nice.movenum);
	
	//cout << nice.movenum << endl;

	cout << "Player 2 is white" << endl;
	nice.play_move(18,nice.movenum);

	//cout << nice.movenum << endl;

	nice.check_legal_moves(nice.movenum);

	nice.print_board();

	return 0;
}