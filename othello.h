#include <vector>

using namespace std;

class OthelloBoard
{
	public:
		int boardArr[64];
		int movenum;

		// struct score
		// {
		// 	int white_score;
		// 	int black_score;
		// };

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

		int check_victory(int white,int black);

};