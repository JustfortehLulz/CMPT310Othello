#include <iostream>
#include <cstdlib>
#include "othello.h"

using namespace std;

int main(int argc, char const *argv[])
{

	bool P1moves = true;
	bool P2moves = true;
	vector<int> moves;
	int randIndex;
	int white = 0;
	int black = 0;
	int res = 0;

	OthelloBoard nice;
	cout << "-----------INTIAL BOARD-------------" << endl;
	nice.print_board();
	cout << "------------------------------------" << endl;


	for(int i = 1; i <= 64 ; i++)
	{
		if(P1moves == false && P2moves == false)
		{
			cout << "No more legal moves for both players" << endl;
			white = nice.white_score();
			black = nice.black_score();
			res = nice.check_victory(white,black);
			if(res == 0)
			{
				cout << "Black Wins!" << endl;
			}
			else if(res == 1)
			{
				cout << "White Wins!" << endl;
			}
			else if(res == 2)
			{
				cout << "It's a Draw" << endl;
			}
			break;
		}
		else
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
				if(!(moves.empty()))
				{
					randIndex = rand() % moves.size();
					cout << endl;
					cout << "PLAYING THIS MOVE: " << moves[randIndex] << endl;
					nice.play_move(nice.movenum,moves[randIndex]);
					nice.print_board();
					nice.end_score();
					P1moves = true;
				}
				else
				{
					nice.movenum++;
					P1moves = false;
				}
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
				if(!(moves.empty()))
				{
					randIndex = rand() % moves.size();
					cout << endl;
					cout << "PLAYING THIS MOVE: " << moves[randIndex] << endl;
					nice.play_move(nice.movenum,moves[randIndex]);
					nice.print_board();
					nice.end_score();
					P2moves = true;
				}
				else
				{
					nice.movenum++;
					P2moves = false;
				}
				moves.clear();
			}
			cout << "----------------------------------------" << endl;
		}

	}

	return 0;
}