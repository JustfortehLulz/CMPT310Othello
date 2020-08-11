#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "othello.h"


#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define BLACK 0
#define WHITE 1
#define EMPTY -1

using namespace std;

OthelloBoard::OthelloBoard()
{
    for (int i = 0;i<64;i++)
    {
        boardArr[i] = EMPTY;
    }
    boardArr[27] = WHITE;
    boardArr[28] = BLACK;
    boardArr[35] = BLACK;
    boardArr[36] = WHITE;
    movenum = 1;
    return;
}

void OthelloBoard::print_board()
{
    for (int i = 0;i < 64;i++)
    {
        if (boardArr[i] == WHITE)
        {
            cout << "|" << RED << "W " << RESET << "|";
        }
        else if (boardArr[i] == BLACK)
        {
            cout << "|" << BLUE << "B " << RESET << "|";
        }
        else if (boardArr[i] == EMPTY)
        {
            if (i < 10)
            {
                cout << "| " << YELLOW << i << RESET << "|";
            }
            else
            {
                cout << "|" << YELLOW << i << RESET << "|";
            }

        }
        //cout << "|" << boardArr[i] << "|";
        if (i % 8 == 7 && i != 63)
        {
            cout << endl;
            cout << "--------------------------------" << endl;
        }
        else if (i == 63)
        {
            cout << endl;
        }
    }
}

void OthelloBoard::print_array()
{
    for (int i = 0; i < 64; i++)
    {
        cout << boardArr[i] << endl;
    }
}

vector<int> OthelloBoard::check_legal_moves(int turn)
{
    vector<int> legalMoves;
    //black pieces turn
    if (turn % 2 == 1)
    {
        for (int i = 0;i < 64;i++)
        {
            // find black piece
            if (boardArr[i] == BLACK)
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
                if (i - 8 < 0) {
                }
                else {
                    // check up if theres a white piece
                    while (boardArr[up] == WHITE) {
                        // keeps going up until either hits the edge or finds an empty spot
                        up -= 8;
                        if (up < 0) {
                            break;
                        }
                        if (boardArr[up] == EMPTY) {
                            // this is a legal move
                            if (find(legalMoves.begin(), legalMoves.end(), up) == legalMoves.end()) {
                                legalMoves.push_back(up);
                            }
                        }
                    }
                }
                // if not on the left most column
                // LEFT
                if (i % 8 == 0) {
                }
                else {
                    while (boardArr[left] == WHITE) {
                        left -= 1;
                        if (left % 8 == 7) {
                            break;
                        }
                        if (boardArr[left] == EMPTY) {
                            if (find(legalMoves.begin(), legalMoves.end(), left) == legalMoves.end()) {
                                legalMoves.push_back(left);
                            }

                        }
                    }
                }
                //DOWN
                if (i >= 55) {
                }
                else {
                    // keeps going until there is an empty spot or until the edge
                    while (boardArr[down] == WHITE) {
                        down += 8;
                        if (down > 63) {
                            break;
                        }
                        if (boardArr[down] == EMPTY) {
                            if (find(legalMoves.begin(), legalMoves.end(), down) == legalMoves.end()) {
                                legalMoves.push_back(down);
                            }
                        }
                    }
                }
                //RIGHT
                if (i % 8 == 7) {
                }
                else {
                    while (boardArr[right] == WHITE) {
                        right += 1;
                        if (right % 8 == 0) {
                            break;
                        }
                        if (boardArr[right] == EMPTY) {
                            if (find(legalMoves.begin(), legalMoves.end(), right) == legalMoves.end()) {
                                legalMoves.push_back(right);
                            }
                        }
                    }
                }
                //DOWN-RIGHT
                if (!((i >= 55) || (i % 8 == 7)))
                {
                    while (boardArr[down_right] == WHITE)
                    {
                        down_right += 9;
                        if (down_right > 63 || down_right % 8 == 0)
                        {
                            break;
                        }
                        if (boardArr[down_right] == EMPTY)
                        {
                            if (find(legalMoves.begin(), legalMoves.end(), down_right) == legalMoves.end())
                            {
                                legalMoves.push_back(down_right);
                            }
                        }
                    }
                }
                //DOWN-LEFT
                if (i < 55 || i % 8 == 0) {
                    while (boardArr[down_left] == WHITE) {
                        down_left += 7;
                        if (down_left > 63 || down_left % 8 == 7) {
                            break;
                        }
                        if (boardArr[down_left] == EMPTY) {
                            if (find(legalMoves.begin(), legalMoves.end(), down_left) == legalMoves.end()) {
                                legalMoves.push_back(down_left);
                            }
                        }
                    }
                }
                else {
                }
                //UP-RIGHT
                if (!((i-8 < 0) || (i % 8 == 7)))
                {
                    while (boardArr[up_right] == WHITE)
                    {
                        up_right -= 7;
                        if (up_right % 8 == 0 || up_right < 0)
                        {
                            break;
                        }
                        if (boardArr[up_right] == EMPTY)
                        {
                            if (find(legalMoves.begin(), legalMoves.end(), up_right) == legalMoves.end())
                            {
                                legalMoves.push_back(up_right);
                            }
                        }
                    }
                }
                //UP-LEFT
                if (!((i-8 < 0) || (i % 8 == 0)))
                {
                    while (boardArr[up_left] == WHITE)
                    {
                        up_left -= 9;
                        if (up_left < 0 || up_left % 8 == 7)
                        {
                            break;
                        }
                        if (boardArr[up_left] == EMPTY)
                        {
                            if (find(legalMoves.begin(), legalMoves.end(), up_left) == legalMoves.end())
                            {
                                legalMoves.push_back(up_left);
                            }
                        }
                    }
                }
            }
        }
    }
    else if (turn % 2 == 0)
    {
        for (int i = 0;i < 64;i++)
        {
            // find white piece
            if (boardArr[i] == WHITE)
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
                if (i - 8 < 0) {
                }
                else {
                    // check up if theres a white piece
                    while (boardArr[up] == BLACK) {
                        // keeps going up until either hits the edge or finds an empty spot
                        up -= 8;
                        if (up < 0) {
                            break;
                        }
                        if (boardArr[up] == EMPTY) {
                            // this is a legal move
                            if (find(legalMoves.begin(), legalMoves.end(), up) == legalMoves.end()) {
                                legalMoves.push_back(up);
                            }
                        }
                    }
                }
                // if not on the left most column
                // LEFT
                if (i % 8 == 0) {
                }
                else {
                    while (boardArr[left] == BLACK) {
                        left -= 1;
                        if (left % 8 == 7) {
                            break;
                        }
                        if (boardArr[left] == EMPTY) {
                            if (find(legalMoves.begin(), legalMoves.end(), left) == legalMoves.end()) {
                                legalMoves.push_back(left);
                            }
                        }
                    }
                }
                //DOWN
                if (i >= 55) {
                }
                else {
                    while (boardArr[down] == BLACK) {
                        down += 8;
                        if (down > 63) {
                            break;
                        }
                        if (boardArr[down] == EMPTY) {
                            if (find(legalMoves.begin(), legalMoves.end(), down) == legalMoves.end()) {
                                legalMoves.push_back(down);
                            }
                        }
                    }
                }
                //RIGHT
                if (i % 8 == 7) {
                }
                else {
                    while (boardArr[right] == BLACK) {
                        right += 1;
                        if (right % 8 == 0) {
                            break;
                        }
                        if (boardArr[right] == EMPTY) {
                            if (find(legalMoves.begin(), legalMoves.end(), right) == legalMoves.end()) {
                                legalMoves.push_back(right);
                            }
                        }
                    }
                }
                //DOWN-RIGHT
                if (!((i >= 55) || (i % 8 == 7)))
                {
                    while (boardArr[down_right] == BLACK)
                    {
                        down_right += 9;
                        if (down_right > 63 || down_right % 8 == 0)
                        {
                            break;
                        }
                        if (boardArr[down_right] == EMPTY)
                        {
                            if (find(legalMoves.begin(), legalMoves.end(), down_right) == legalMoves.end())
                            {
                                legalMoves.push_back(down_right);
                            }
                        }
                    }
                }
                //DOWN-LEFT
                if (i < 55 || i % 8 == 0) {
                    while (boardArr[down_left] == BLACK) {
                        down_left += 7;
                        if (down_left > 63 || down_left % 8 == 7) {
                            break;
                        }
                        if (boardArr[down_left] == EMPTY) {
                            if (find(legalMoves.begin(), legalMoves.end(), down_left) == legalMoves.end()) {
                                legalMoves.push_back(down_left);
                            }
                        }
                    }
                }
                else {
                }
                //UP-RIGHT
                if (!((i-8 < 0) || (i % 8 == 7)))
                {
                    while (boardArr[up_right] == BLACK)
                    {
                        up_right -= 7;
                        if (up_right % 8 == 0 || up_right < 0)
                        {
                            break;
                        }
                        if (boardArr[up_right] == EMPTY)
                        {
                            if (find(legalMoves.begin(), legalMoves.end(), up_right) == legalMoves.end())
                            {
                                legalMoves.push_back(up_right);
                            }
                        }
                    }
                }
                //UP-LEFT
                if (!((i-8 < 0) || (i % 8 == 0)))
                {
                    while (boardArr[up_left] == BLACK)
                    {
                        up_left -= 9;
                        if (up_left < 0 || up_left % 8 == 7)
                        {
                            break;
                        }
                        if (boardArr[up_left] == EMPTY)
                        {
                            if (find(legalMoves.begin(), legalMoves.end(), up_left) == legalMoves.end())
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

// put in legal moves ///////////////////////////////////////////////////////
void OthelloBoard::play_move(int turn, int tile)
{
    if (boardArr[tile] != EMPTY)
    {
        cout << "Invalid Move" << endl;
        return;
    }
    else
    {
        // Player 1 black
        if (turn % 2 == 1)
        {
            boardArr[tile] = BLACK;
            flip_tile(turn, tile);
        }
        // Player 2 white
        else if (turn % 2 == 0)
        {
            boardArr[tile] = WHITE;
            flip_tile(turn, tile);
        }
        movenum++;
    }
}

void OthelloBoard::flip_tile(int turn, int tile)
{
    vector<int> flipPieces;
    // black pieces turn
    if (turn % 2 == 1)
    {
        int up = tile - 8;
        int left = tile - 1;
        int down = tile + 8;
        int right = tile + 1;

        int down_right = tile + 9;
        int down_left = tile + 7;
        int up_right = tile - 7;
        int up_left = tile - 9;
        if (tile - 8 < 0) {
        }
        else {
            // check up if theres a white piece
            while (boardArr[up] == WHITE) {
                // keeps going up until either hits the edge or finds another black piece
                flipPieces.push_back(up);
                up -= 8;
                if (up < 0 || boardArr[up] == EMPTY) {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[up] == BLACK) {
                    // hit a black piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j) {
                        boardArr[*j] = BLACK;
                    }
                }
            }
        }
        //if not on the left most column
        //LEFT
        if (tile % 8 == 0) {
        }
        else {
            while (boardArr[left] == WHITE) {
                flipPieces.push_back(left);
                left -= 1;
                if (left % 8 == 7 || boardArr[left] == EMPTY) {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[left] == BLACK) {
                    // hit a black piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j) {
                        boardArr[*j] = BLACK;
                    }
                }
            }
        }
        //DOWN
        if (tile > 55) {
        }
        else {
            while (boardArr[down] == WHITE) {
                flipPieces.push_back(down);
                down += 8;
                if (down > 63 || boardArr[down] == EMPTY) {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[down] == BLACK) {
                    // hit a black piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j) {
                        cout << *j << endl;
                        boardArr[*j] = BLACK;
                    }
                }
            }
        }
        //RIGHT
        if (tile % 8 == 7) {
        }
        else {
            while (boardArr[right] == WHITE) {
                flipPieces.push_back(right);
                right += 1;
                if (right % 8 == 0 || boardArr[right] == EMPTY) {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[right] == BLACK) {
                    // hit a black piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j) {
                        boardArr[*j] = BLACK;
                    }
                }
            }
        }
        //DOWN-RIGHT
        if (!((tile > 55) || (tile % 8 == 7)))
        {
            while (boardArr[down_right] == WHITE)
            {
                flipPieces.push_back(down_right);
                down_right += 9;
                if (down_right > 63 || down_right % 8 == 0 || boardArr[down_right] == EMPTY)
                {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[down_right] == BLACK)
                {
                    // hit a black piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
                    {
                        boardArr[*j] = BLACK;
                    }
                }
            }
        }
        //DOWN-LEFT
        if (tile <= 55 || tile % 8 == 0) {
            while (boardArr[down_left] == WHITE) {
                flipPieces.push_back(down_left);
                down_left += 7;
                if (down_left > 63 || down_left % 8 == 7 || boardArr[down_left] == EMPTY) {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[down_left] == BLACK) {
                    // hit a black piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j) {
                        boardArr[*j] = BLACK;
                    }
                }
            }
        }
        else {
        }
        //UP-RIGHT
        if (!((tile-8 < 0) || (tile % 8 == 7)))
        {
            while (boardArr[up_right] == WHITE)
            {
                flipPieces.push_back(up_right);
                up_right -= 7;
                if (up_right % 8 == 0 || up_right < 0 || boardArr[up_right] == EMPTY)
                {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[up_right] == BLACK)
                {
                    // hit a black piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
                    {
                        boardArr[*j] = BLACK;
                    }
                }
            }
        }
        //UP-LEFT
        if (!((tile-8 < 0) || (tile % 8 == 0)))
        {
            while (boardArr[up_left] == WHITE)
            {
                flipPieces.push_back(up_left);
                up_left -= 9;
                if (up_left < 0 || up_left % 8 == 7 || boardArr[up_left] == EMPTY)
                {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[up_left] == BLACK)
                {
                    // hit a black piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
                    {
                        boardArr[*j] = BLACK;
                    }
                }
            }
        }
    }
    // white pieces turn
    else if (turn % 2 == 0)
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
        if (tile - 8 < 0) {
        }
        else {
            // check up if theres a black piece
            while (boardArr[up] == BLACK) {
                // keeps going up until either hits the edge or finds an empty spot
                flipPieces.push_back(up);
                up -= 8;
                if (up < 0 || boardArr[up] == EMPTY) {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[up] == WHITE) {
                    // hit a white piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j) {
                        boardArr[*j] = WHITE;
                    }
                }
            }
        }

        // if not on the left most column
        // LEFT
        if (tile % 8 == 0) {
        }
        else {
            while (boardArr[left] == 0) {
                flipPieces.push_back(left);
                left -= 1;
                if (left % 8 == 7 || boardArr[left] == EMPTY) {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[left] == WHITE) {
                    // hit a white piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j) {
                        boardArr[*j] = WHITE;
                    }
                }
            }
        }
        //DOWN
        if (tile > 55) {
        }
        else {
            while (boardArr[down] == BLACK) {
                flipPieces.push_back(down);
                down += 8;
                if (down > 63 || boardArr[down] == EMPTY) {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[down] == WHITE) {
                    // hit a white piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j) {
                        boardArr[*j] = WHITE;
                    }
                }
            }
        }
        //RIGHT
        if (tile % 8 == 7) {
        }
        else {
            while (boardArr[right] == BLACK) {
                flipPieces.push_back(right);
                right += 1;
                if (right % 8 == 0 || boardArr[right] == EMPTY) {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[right] == WHITE) {
                    // hit a white piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j) {
                        boardArr[*j] = WHITE;
                    }
                }
            }
        }
        //DOWN-RIGHT
        if (!((tile > 55) || (tile % 8 == 7)))
        {
            while (boardArr[down_right] == BLACK)
            {
                flipPieces.push_back(down_right);
                down_right += 9;
                if (down_right > 63 || down_right % 8 == 0 || boardArr[down_right] == EMPTY)
                {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[down_right] == WHITE)
                {
                    // hit a white piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
                    {
                        boardArr[*j] = WHITE;
                    }
                }
            }
        }

        //DOWN-LEFT
        if (!((tile > 55) || (tile % 8 == 0)))
        {
            while (boardArr[down_left] == 0)
            {
                flipPieces.push_back(down_left);

                down_left += 7;
                if (down_left > 63 || down_left % 8 == 7 || boardArr[down_left] == EMPTY)
                {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[down_left] == 1)
                {
                    // hit a white piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
                    {
                        boardArr[*j] = 1;
                    }
                }
            }
        }
        //UP-RIGHT
        if (!((tile-8 < 0) || (tile % 8 == 7)))
        {
            while (boardArr[up_right] == 0)
            {
                flipPieces.push_back(up_right);
                up_right -= 7;
                if (up_right % 8 == 0 || up_right < 0 || boardArr[up_right] == EMPTY)
                {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[up_right] == 1)
                {
                    // hit a white piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
                    {
                        boardArr[*j] = 1;
                    }
                }
            }
        }
        //UP-LEFT
        if (!((tile-8 < 0) || (tile % 8 == 0)))
        {
            while (boardArr[up_left] == BLACK)
            {
                flipPieces.push_back(up_left);
                up_left -= 9;
                if (up_left < 0 || up_left % 8 == 7 || boardArr[up_left] == EMPTY)
                {
                    flipPieces.clear();
                    break;
                }
                if (boardArr[up_left] == WHITE)
                {
                    // hit a white piece, time to flip over the white pieces
                    for (auto j = flipPieces.begin(); j != flipPieces.end(); ++j)
                    {
                        boardArr[*j] = WHITE;
                    }
                }
            }
        }
    }
}



int OthelloBoard::white_score()
{
    int white_score = 0;
    for (int i = 0;i<64;i++)
    {
        if (boardArr[i] == WHITE)
        {
            white_score++;
        }
    }
    return white_score;
}

int OthelloBoard::black_score()
{
    int black_score = 0;
    for (int i = 0;i<64;i++)
    {
        if (boardArr[i] == BLACK)
        {
            black_score++;
        }
    }
    return black_score;
}

void OthelloBoard::end_score()
{
    int white_score = this->white_score();
    int black_score = this->black_score();

    cout << "White: " << white_score << " Black: " << black_score << endl;
}

string OthelloBoard::calculate_winner()
{
    int white_score = this->white_score();
    int black_score = this->black_score();

    if (white_score > black_score)
    {
        return "white";
    }
    else if (white_score < black_score)
    {
        return "black";
    }
    else if (white_score == black_score)
    {
        return "draw";
    }
}