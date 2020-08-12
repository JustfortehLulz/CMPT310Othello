#pragma once
#include <vector>
#include <string>

using namespace std;

class OthelloBoard
{
private:
	int boardArr[64];
	int movenum;

public:
	OthelloBoard(); // Default Constructor for new board.

	OthelloBoard(const OthelloBoard &Board); // Deep Copy Constructor

	void print_board();

	string get_turn();

	void flip_tile(int tile);

	vector<int> check_legal_moves(int current_player);
	vector<int> current_legal_moves();

	int rolloutValue();

	vector<int> black_legal_moves();

	vector<int> white_legal_moves();

	bool is_legal_moves();

	void play_move(int tile);

	void print_score();

	void print_end_score();

	int white_score();

	int black_score();

	string calculate_winner();
};