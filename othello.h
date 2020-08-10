class OthelloBoard
{
	public:
		int boardArr[64];
		int movenum = 0;

		OthelloBoard();

		void print_board();
	
		void filp_tile();

		void check_legal_moves(int turn);

		void play_move(int tile, int turn);

		void can_flip();

};