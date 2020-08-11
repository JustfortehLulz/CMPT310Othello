#include <vector>

using namespace std;

class OthelloBoard
{
public:
	int boardArr[64];
	int movenum;

	OthelloBoard();

	void print_board();

	void flip_tile(int turn, int tile);

	vector<int> check_legal_moves(int turn);

	void play_move(int turn, int tile);

	void print_array();

	void print_score();

	void end_score();

	int white_score();

	int black_score();

	string calculate_winner(int white, int black);

};