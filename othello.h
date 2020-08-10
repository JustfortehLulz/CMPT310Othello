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

};