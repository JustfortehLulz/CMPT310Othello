#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

void OthelloBoard::print_array()
{
	for(int i = 0; i < 64; i++)
	{
		cout << boardArr[i] << endl;
	}
}

vector<int> OthelloBoard::check_legal_moves(int turn)
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
							if(find(legalMoves.begin(),legalMoves.end(),up) == legalMoves.end())
							{
								legalMoves.push_back(up);
							}
							
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
							if(find(legalMoves.begin(),legalMoves.end(),left) == legalMoves.end())
							{
								legalMoves.push_back(left);
							}
							
						}
					}
				}
				//DOWN
				if(!(i > 55))
				{
					// keeps going until there is an empty spot or until the edge
					while(boardArr[down] == 1)
					{
						down += 8;
						if(down > 63)
						{
							break;
						}
						if(boardArr[down] == -1)
						{
							if(find(legalMoves.begin(),legalMoves.end(),down) == legalMoves.end())
							{
								legalMoves.push_back(down);
							}
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
							if(find(legalMoves.begin(),legalMoves.end(),right) == legalMoves.end())
							{
								legalMoves.push_back(right);
							}
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
							if(find(legalMoves.begin(),legalMoves.end(),down_right) == legalMoves.end())
							{
								legalMoves.push_back(down_right);
							}
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
							if(find(legalMoves.begin(),legalMoves.end(),down_left) == legalMoves.end())
							{
								legalMoves.push_back(down_left);
							}
						}
					}
				}
				//UP-RIGHT
				if(! ((up < 0) || (i % 8 == 7)))
				{
					while(boardArr[up_right] == 1)
					{
						up_right -= 7;
						if(up_right % 8 == 7 || up_right < 0)
						{
							break;
						}
						if(boardArr[up_right] == -1)
						{
							if(find(legalMoves.begin(),legalMoves.end(),up_right) == legalMoves.end())
							{
								legalMoves.push_back(up_right);
							}
						}
					}	
				}
				//UP-LEFT
				if(! ((up < 0) || (i % 8 == 0)) )
				{
					while(boardArr[up_left] == 1)
					{
						up_left -= 9;
						if(up_left < 0 || up_left % 8 == 0)
						{
							break;
						}
						if(boardArr[up_left] == -1)
						{
							if(find(legalMoves.begin(),legalMoves.end(),up_left) == legalMoves.end())
							{
								legalMoves.push_back(up_left);
							}
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
							if(find(legalMoves.begin(),legalMoves.end(),up) == legalMoves.end())
							{
								legalMoves.push_back(up);
							}
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
							if(find(legalMoves.begin(),legalMoves.end(),left) == legalMoves.end())
							{
								legalMoves.push_back(left);
							}
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
							if(find(legalMoves.begin(),legalMoves.end(),down) == legalMoves.end())
							{
								legalMoves.push_back(down);
							}
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
							if(find(legalMoves.begin(),legalMoves.end(),right) == legalMoves.end())
							{
								legalMoves.push_back(right);
							}
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
							if(find(legalMoves.begin(),legalMoves.end(),down_right) == legalMoves.end())
							{
								legalMoves.push_back(down_right);
							}
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
							if(find(legalMoves.begin(),legalMoves.end(),down_left) == legalMoves.end())
							{
								legalMoves.push_back(down_left);
							}
						}
					}
				}
				//UP-RIGHT
				if(! ((up < 0) || (i % 8 == 7)))
				{
					while(boardArr[up_right] == 0)
					{
						up_right -= 7;
						if(up_right % 8 == 7 || up_right < 0)
						{
							break;
						}
						if(boardArr[up_right] == -1)
						{
							if(find(legalMoves.begin(),legalMoves.end(),up_right) == legalMoves.end())
							{
								legalMoves.push_back(up_right);
							}
						}
					}	
				}
				//UP-LEFT
				if(! ((up < 0) || (i % 8 == 0)) )
				{
					while(boardArr[up_left] == 0)
					{
						up_left -= 9;
						if(up_left < 0 || up_left % 8 == 0)
						{
							break;
						}
						if(boardArr[up_left] == -1)
						{
							if(find(legalMoves.begin(),legalMoves.end(),up_left) == legalMoves.end())
							{
								legalMoves.push_back(up_left);
							}
						}
					}
				}
			}
		}
	}
	// for(auto j = legalMoves.begin(); j != legalMoves.end();++j)
	// {
	// 	cout << *j <<  " " << endl;
	// }
	return legalMoves;
	//return the vector
}

void OthelloBoard::play_move(int turn, int tile)
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
			flip_tile(turn,tile);
		}
		// Player 2 white
		else if(turn % 2 == 0)
		{
			boardArr[tile] = 1;
			flip_tile(turn,tile);
		}
		movenum++;
	}
}

void OthelloBoard::flip_tile(int turn, int tile)
{
	vector<int> flipPieces;
	// black pieces turn
	if(turn % 2 == 1)
	{
		int up = tile - 8;
		int left = tile - 1;
		int down = tile + 8;
		int right = tile + 1;
				
		int down_right = tile + 9;
		int down_left = tile + 7;
		int up_right = tile - 7;
		int up_left = tile - 9;
		if(!(up < 0))
		{
			// check up if theres a white piece
			while(boardArr[up] == 1)
			{
				// keeps going up until either hits the edge or finds another black piece
				flipPieces.push_back(up);
				up -= 8;
				if(up < 0 || boardArr[up] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[up] == 0)
				{
					// hit a black piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 0;
					}
				}
			}
		}
		//if not on the left most column
		//LEFT
		if(!(tile % 8 == 0))
		{
			while(boardArr[left] == 1)
			{
				flipPieces.push_back(left);
				left -= 1;
				if(left % 8 == 0 || boardArr[left] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[left] == 0)
				{
					// hit a black piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 0;
					}
				}
			}
		}
		//DOWN
		if(!(tile > 55))
		{
			while(boardArr[down] == 1)
			{
				flipPieces.push_back(down);
				down += 8;
				if(down > 63 || boardArr[down] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[down] == 0)
				{
					// hit a black piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						cout << *j << endl;
						boardArr[*j] = 0;
					}
				}
			}
		}
		//RIGHT
		if(!(tile % 8 == 7))
		{
			while(boardArr[right] == 1)
			{
				flipPieces.push_back(right);
				right += 1;
				if(right % 8 == 7 || boardArr[right] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[right] == 0)
				{
					// hit a black piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 0;
					}
				}
			}
		}
		//DOWN-RIGHT
		if(!( (tile > 55) || (tile % 8 == 7) ))
		{
			while(boardArr[down_right] == 1)
			{
				flipPieces.push_back(down_right);
				down_right += 9;
				if(down_right > 55 || down_right % 8 == 7 || boardArr[down_right] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[down_right] == 0)
				{
					// hit a black piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 0;
					}
				}
			}
		}
		//DOWN-LEFT
		if(! (tile > 55) || (tile % 8 == 0))
		{
			while(boardArr[down_left] == 1)
			{
				flipPieces.push_back(down_left);
				down_left += 7;
				if(down_left > 55 || down_left % 8 == 0 || boardArr[down_left] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[down_left] == 0)
				{
					// hit a black piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 0;
					}
				}
			}
		}
		//UP-RIGHT
		if(! ((up < 0) || (tile % 8 == 7)))
		{
			while(boardArr[up_right] == 1)
			{
			flipPieces.push_back(up_right);
			up_right -= 7;
				if(up_right % 8 == 7 || up_right < 0 || boardArr[up_right] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[up_right] == 0)
				{
					// hit a black piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 0;
					}
				}
			}	
		}
		//UP-LEFT
		if(! ((up < 0) || (tile % 8 == 0)) )
		{
			while(boardArr[up_left] == 1)
			{
			flipPieces.push_back(up_left);
			up_left -= 9;
				if(up_left < 0 || up_left % 8 == 0 || boardArr[up_left] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[up_left] == 0)
				{
					// hit a black piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 0;
					}
				}
			}
		}
	}
	// white pieces turn
	else if(turn % 2 == 0)
	{

		int up = tile - 8;
		int left = tile - 1;
		int down = tile + 8;
		int right = tile + 1;
		
		int down_right = tile + 9;
		int down_left = tile + 7;
		int up_right = tile - 7;
		int up_left = tile - 9;
		// if not on the top row
		// UP
		if(!(up < 0))
		{
			// check up if theres a black piece
			while(boardArr[up] == 0)
			{
				// keeps going up until either hits the edge or finds an empty spot
				flipPieces.push_back(up);
				up -= 8;
				if(up < 0 || boardArr[up] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[up] == 1)
				{
					// hit a white piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 1;
					}
				}
			}
		}

		// if not on the left most column
		// LEFT
		if(!(tile % 8 == 0))
		{
			while(boardArr[left] == 0)
			{
				flipPieces.push_back(left);
				left -= 1;
				if(left % 8 == 0 || boardArr[left] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[left] == 1)
				{
					// hit a white piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 1;
					}				
				}
			}
		}

		//DOWN
		if(!(tile > 55))
		{
			while(boardArr[down] == 0)
			{
				flipPieces.push_back(down);
				down += 8;
				if(down > 63  || boardArr[down] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[down] == 1)
				{
					// hit a white piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 1;
					}
				}
			}
		}

		//RIGHT
		if(!(tile % 8 == 7))
		{
			while(boardArr[right] == 0)
			{
				flipPieces.push_back(right);
				right += 1;
				if(right % 8 == 7 || boardArr[right] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[right] == 1)
				{
					// hit a white piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 1;
					}
				}
			}
		}

		//DOWN-RIGHT
		if(!( (tile > 55) || (tile % 8 == 7) ))
		{
			while(boardArr[down_right] == 0)
			{
				flipPieces.push_back(down_right);
				down_right += 9;
				if(down_right > 55 || down_right % 8 == 7 || boardArr[down_right] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[down_right] == 1)
				{
					// hit a white piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 1;
					}
				}
			}
		}

		//DOWN-LEFT
		if(! (tile > 55) || (tile % 8 == 0))
		{
			while(boardArr[down_left] == 0)
			{
				flipPieces.push_back(down_left);
				down_left += 7;
				if(down_left > 55 || down_left % 8 == 0 || boardArr[down_left] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[down_left] == 1)
				{
					// hit a white piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 1;
					}
				}
			}
		}

		//UP-RIGHT
		if(! ((up < 0) || (tile % 8 == 7)))
		{
			while(boardArr[up_right] == 0)
			{
				flipPieces.push_back(up_right);
				up_right -= 7;
				if(up_right % 8 == 7 || up_right < 0 || boardArr[up_right] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[up_right] == 1)
				{
					// hit a white piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 1;
					}
				}
			}	
		}
		//UP-LEFT
		if(! ((up < 0) || (tile % 8 == 0)) )
		{
			while(boardArr[up_left] == 0)
			{
				flipPieces.push_back(up_left);
				up_left -= 9;
				if(up_left < 0 || up_left % 8 == 0 || boardArr[up_left] == -1)
				{
					flipPieces.clear();
					break;
				}
				if(boardArr[up_left] == 1)
				{
					// hit a white piece, time to flip over the white pieces
					for(auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
					{
						boardArr[*j] = 1;
					}
				}
			}
		}
	}
}

void OthelloBoard::end_score()
{
	int white_score = 0;
	int black_score = 0;
	for(int i = 0;i<64;i++)
	{
		if(boardArr[i] == 0)
		{
			black_score++;
		}
		else if(boardArr[i] == 1)
		{
			white_score++;
		}
	}
	cout << "White: " << white_score << " Black: " << black_score << endl;
}

int OthelloBoard::white_score()
{
	int white_score = 0;
	for(int i = 0;i<64;i++)
	{
		if(boardArr[i] == 1)
		{
			white_score++;
		}
	}
	return white_score;
}

int OthelloBoard::black_score()
{
	int black_score = 0;
	for(int i = 0;i<64;i++)
	{
		if(boardArr[i] == 0)
		{
			black_score++;
		}
	}
	return black_score;
}

// 0 = win for black
// 1 = win for white
// 2 = draw
int OthelloBoard::check_victory(int white,int black)
{
	if(white > black)
	{
		return 1;
	}
	else if (white < black)
	{
		return 0;
	}
	else if(white == black)
	{
		return 2;
	}
}