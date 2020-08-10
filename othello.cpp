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
				int up = i - 8;
				int left = i - 1;
				int down = i + 8;
				int right = i + 1;
				
				int down_right = i + 9;
				int down_left = i + 7;
				int up_right = i - 7;
				int up_left = i - 9;
				// if not on the top row
				// UP
				if(!(up < 0))
				{
					// check up if theres a white piece
					while(boardArr[up] == 1)
					{
						// keeps going up until either hits the edge or finds an empty spot
						up -= 8;
						if(up < 0)
						{
							break;
						}
						if(boardArr[up] == -1)
						{
							// this is a legal move
							legalMoves.push_back(up);
						}
					}
				}
				// if not on the left most column
				// LEFT
				if(!(i % 8 == 0))
				{
					while(boardArr[left] == 1)
					{
						left -= 1;
						if(left % 8 == 0)
						{
							break;
						}
						if(boardArr[left] == -1)
						{
							legalMoves.push_back(left);
						}
					}
				}
				//DOWN
				if(!(i > 55))
				{
					while(boardArr[down] == 1)
					{
						down += 8;
						if(down > 63)
						{
							break;
						}
						if(boardArr[down] == -1)
						{
							legalMoves.push_back(down);
						}
					}
				}
				//RIGHT
				if(!(i % 8 == 7))
				{
					while(boardArr[right] == 1)
					{
						right += 1;
						if(right % 8 == 7)
						{
							break;
						}
						if(boardArr[right] == -1)
						{
							legalMoves.push_back(right);
						}
					}
				}
				//DOWN-RIGHT
				if(!( (i > 55) || (i % 8 == 7) ))
				{
					while(boardArr[down_right] == 1)
					{
						down_right += 9;
						if(down_right > 55 || down_right % 8 == 7)
						{
							break;
						}
						if(boardArr[down_right] == -1)
						{
							legalMoves.push_back(down_right);
						}
					}
				}
				//DOWN-LEFT
				if(! (i > 55) || (i % 8 == 0))
				{
					while(boardArr[down_left] == 1)
					{
						down_left += 7;
						if(down_left > 55 || down_left % 8 == 0)
						{
							break;
						}
						if(boardArr[down_left] == -1)
						{
							legalMoves.push_back(down_left);
						}
					}
				}
				//UP-RIGHT
				if(! ((up < 0) || (i % 8 == 7)))
				{
					up_right -= 7;
					while(boardArr[up_right] == 1)
					{
						if(up_right % 8 == 7 || up_right < 0)
						{
							break;
						}
						if(boardArr[up_right] == -1)
						{
							legalMoves.push_back(up_right);
						}
					}	
				}
				//UP-LEFT
				if(! ((up < 0) || (i % 8 == 0)) )
				{
					up_left -= 9;
					while(boardArr[up_left] == 1)
					{
						if(up_left < 0 || up_left % 8 == 0)
						{
							break;
						}
						if(boardArr[up_left] == -1)
						{
							legalMoves.push_back(up_left);
						}
					}
				}
			}
		}
	}
	else if(turn % 2 == 0)
	{
		for(int i = 0;i < 64;i++)
		{
			// find white piece
			if(boardArr[i] == 1)
			{
			// check for white pieces
				int up = i - 8;
				int left = i - 1;
				int down = i + 8;
				int right = i + 1;
				
				int down_right = i + 9;
				int down_left = i + 7;
				int up_right = i - 7;
				int up_left = i - 9;
				// if not on the top row
				// UP
				if(!(up < 0))
				{
					// check up if theres a white piece
					while(boardArr[up] == 0)
					{
						// keeps going up until either hits the edge or finds an empty spot
						up -= 8;
						if(up < 0)
						{
							break;
						}
						if(boardArr[up] == -1)
						{
							// this is a legal move
							legalMoves.push_back(up);
						}
					}
				}
				// if not on the left most column
				// LEFT
				if(!(i % 8 == 0))
				{
					while(boardArr[left] == 0)
					{
						left -= 1;
						if(left % 8 == 0)
						{
							break;
						}
						if(boardArr[left] == -1)
						{
							legalMoves.push_back(left);
						}
					}
				}
				//DOWN
				if(!(i > 55))
				{
					while(boardArr[down] == 0)
					{
						down += 8;
						if(down > 63)
						{
							break;
						}
						if(boardArr[down] == -1)
						{
							legalMoves.push_back(down);
						}
					}
				}
				//RIGHT
				if(!(i % 8 == 7))
				{
					while(boardArr[right] == 0)
					{
						right += 1;
						if(right % 8 == 7)
						{
							break;
						}
						if(boardArr[right] == -1)
						{
							legalMoves.push_back(right);
						}
					}
				}
				//DOWN-RIGHT
				if(!( (i > 55) || (i % 8 == 7) ))
				{
					while(boardArr[down_right] == 0)
					{
						down_right += 9;
						if(down_right > 55 || down_right % 8 == 7)
						{
							break;
						}
						if(boardArr[down_right] == -1)
						{
							legalMoves.push_back(down_right);
						}
					}
				}
				//DOWN-LEFT
				if(! (i > 55) || (i % 8 == 0))
				{
					while(boardArr[down_left] == 0)
					{
						down_left += 7;
						if(down_left > 55 || down_left % 8 == 0)
						{
							break;
						}
						if(boardArr[down_left] == -1)
						{
							legalMoves.push_back(down_left);
						}
					}
				}
				//UP-RIGHT
				if(! ((up < 0) || (i % 8 == 7)))
				{
					up_right -= 7;
					while(boardArr[up_right] == 0)
					{
						if(up_right % 8 == 7 || up_right < 0)
						{
							break;
						}
						if(boardArr[up_right] == -1)
						{
							legalMoves.push_back(up_right);
						}
					}	
				}
				//UP-LEFT
				if(! ((up < 0) || (i % 8 == 0)) )
				{
					up_left -= 9;
					while(boardArr[up_left] == 0)
					{
						if(up_left < 0 || up_left % 8 == 0)
						{
							break;
						}
						if(boardArr[up_left] == -1)
						{
							legalMoves.push_back(up_left);
						}
					}
				}
			}
		}
	}
	cout << "LEGAL MOVES" << endl;
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