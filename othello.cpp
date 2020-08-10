#include <iostream>
#include <vector>
#include <string>
#include "othello.h"


#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"

using namespace std;

OthelloBoard::OthelloBoard()
{
	for(int i = 0;i<64;i++)
	{
		boardArr[i] = -1;
	}
	boardArr[27] = 1;
	boardArr[28] = 0;
	boardArr[35] = 0;
	boardArr[36] = 1;
	movenum = 1;
	return;
}

void OthelloBoard::print_board()
{
	for(int i = 0;i < 64;i++)
	{
		if(boardArr[i] == 1)
		{
			cout << "|" << RED << "W" << RESET << "|";
		}
		else if(boardArr[i] == 0)
		{
			cout << "|" << BLUE << "B" << RESET << "|";
		}
		else if(boardArr[i] == -1)
		{
			cout << "|" << " " << "|";
		}
		//cout << "|" << boardArr[i] << "|";
		if(i % 8 == 7 && i != 63)
		{
			cout << endl;
			cout << "------------------------" << endl;
		}
		else if(i == 63)
		{
			cout << endl;
		}
	}
}

void OthelloBoard::check_legal_moves(int turn)
{
	vector<int> legalMoves;
	//black pieces turn
	if(turn % 2 == 1)
	{
		for(int i = 0;i < 64;i++)
		{
			// find black piece
			if(boardArr[i] == 0)
			{
			// check for white pieces
				// if on the top row
				if(!(i-8 < 0))
				{
					// check up
					while(boardArr[i-8] == 1)
					{
						i = i - 8;
						if(i-8 < 0)
						{
							break;
						}
						if(boardArr[i] == -1)
						{
							// this is a legal move
							legalMoves.push_back(i);
							cout << "FHJIODSJ" << endl;
						}
					}
				}
			}
		}
	}
	for(auto j = legalMoves.begin(); j != legalMoves.end();++j)
	{
		cout << *j <<  " " << endl;
	}
}

void OthelloBoard::play_move(int tile, int turn)
{
	if(boardArr[tile] == 1 || boardArr[tile] == 0)
	{
		cout << "Invalid Move" << endl;
		return;
	}
	else
	{
		// Player 1 black
		if(turn % 2 == 1)
		{
			boardArr[tile] = 0;
		}
		// Player 2 white
		else if(turn % 2 == 0)
		{
			boardArr[tile] = 1;
		}
		movenum++;
	}
}