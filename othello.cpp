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