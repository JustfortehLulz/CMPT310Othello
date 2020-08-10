class OthelloBoard
{
	public:
		int boardArr[64];


		OthelloBoard();

		void print_board();
	
		void filp_tile();

		void check_legal_moves();

		void play_move();

};