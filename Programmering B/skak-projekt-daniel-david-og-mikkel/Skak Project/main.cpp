#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include "chess_GUI.h"
using namespace std;

// Random int generator
int randi(int low, int high)
{
    return rand()*float(high-low)/RAND_MAX + low;
}



void print_move(vector<int> mv)
{
    cout << "Move from " << char('A'+mv[1]) << 8-mv[0];
    cout << " to " << char('A'+mv[3]) << 8-mv[2] << endl;
}

// Print all moves in a vector for control purposes
void print_moves(vector<vector<int>> moves)
{
    for(unsigned int k = 0; k<moves.size(); k++)
    {
        print_move(moves[k]);
    }
}

// Find all pieces of given type
vector<vector<int>> find_pieces(vector<vector<int>> board, int type)
{
    // Find pieces and return list with {row, col} positions
    vector<vector<int>> list_pieces;
    for(int r=0; r<int(board.size()); r++)
    {
        for(int c=0; c<int(board[r].size()); c++)
        {
            if( board[r][c] == type)
            {
                list_pieces.push_back({r,c});
            }
        }
    }
    return list_pieces;
}

// TRIN 1 - UDGANGSPUNKT
// Calculate valid moves for a rook piece
vector<vector<int>> valid_moves_rook(vector<vector<int>> board, int pos_r, int pos_c, int color)
{
    vector<vector<int>> moves;      // Each row in this vector is a legal move, e.g. {1,3, 5,7} indicates a move from row 1, col 3 to row 5, col 7
    // The rook going up
    for (int r = pos_r - 1; r >= 0; r--)
    {
        if(color * board[r][pos_c] <= 0)
        {
            moves.push_back ({pos_r,pos_c,r,pos_c});     // If empty or enemy piece, it's a legal move
        }
        if(board[r][pos_c] != EMPTY)
        {
            break;                                      // Not empty: Collision detected, break the loop
        }
    }
    // The rook going down
    for (int r = pos_r + 1; r < 8; r++)
    {
        if(color * board[r][pos_c] <= 0)
        {
            moves.push_back({pos_r,pos_c,r,pos_c});     // If empty or enemy piece, it's a legal move
        }
        if(board[r][pos_c] != EMPTY)
        {
            break;                                      // Not empty: Collision detected, break the loop
        }
    }
    // The rook going right
    for (int c = pos_c + 1; c < 8; c++)
    {
        if(color * board[pos_r][c] <= 0)
        {
            moves.push_back({pos_r,pos_c,pos_r,c});     // If empty or enemy piece, it's a legal move
        }
        if(board[pos_r][c] != EMPTY)
        {
            break;                                      // Not empty: Collision detected, break the loop
        }
    }
    // The rook going left
    for (int c = pos_c - 1; c >=0; c--)
    {
        if(color * board[pos_r][c] <= 0)
        {
            moves.push_back({pos_r,pos_c,pos_r,c});     // If empty or enemy piece, it's a legal move
        }
        if(board[pos_r][c] != EMPTY)
        {
            break;                                      // Not empty: Collision detected, break the loop
        }
    }

    print_moves(moves);
    return moves;
}
//Moves for Pawns
vector<vector<int>> valid_moves_pawn(vector<vector<int>> board, int pos_r, int pos_c, int color)
{
    vector<vector<int>> moves;      // Each row in this vector is a legal move, e.g. {1,3, 5,7} indicates a move from row 1, col 3 to row 5, col 7

    int r=pos_r+1;
    if(board[r][pos_c]== EMPTY)
    {
        moves.push_back({pos_r,pos_c,r,pos_c});
    }

    print_moves(moves);
    return moves;
}

vector<vector<int>> valid_moves_bishop(vector<vector<int>> board, int pos_r, int pos_c, int color)
{
    vector<vector<int>> moves;
    //Top Left
    for (int c = pos_c - 1; c >=0; c--)
    {
        int change = pos_c - c;
        int r = pos_r + change;
        if(color * board[r][c] <= 0)
        {
            moves.push_back({pos_r,pos_c,r,c});     // If empty or enemy piece, it's a legal move

        }
        if(board[r][c] != EMPTY)
        {
            break;                                      // Not empty: Collision detected, break the loop
        }
        //Top
        /*        for (int c = pos_c + 1; c >=0; c++)
                {
                    int change = pos_c - c;
                    int r = pos_r + change;
                    if(color * board[r][c] <= 0)
                    {
                        moves.push_back({pos_r,pos_c,r,c});     // If empty or enemy piece, it's a legal move
                    }
                    if(board[c][c] != EMPTY)
                    {
                        break;                                      // Not empty: Collision detected, break the loop
                    }
                }*/
    }
    print_moves(moves);
    return moves;

}

vector<vector<int>> valid_moves_queen(vector<vector<int>> board, int pos_r, int pos_c, int color)
{
    vector<vector<int>>valid_moves_bishop();
    vector<vector<int>> valid_moves_rook();
}

// TRIN 1 SLUT

// TRIN 2 - UDGANGSPUNKT
// Evaluate and score a board position
float eval_pos(vector<vector<int>> board)
{

    float sum = 0;
    for(int r=0; r<board.size(); r++)
    {
        for(int c=0; c<board[r].size(); c++)
        {
            switch (board[r][c])
            {
            //Hvid sum
            case W_PAWN:
                sum++;
                break;
            case W_ROOK:
                sum+=5;
                break;
            case W_KNIGHT:
                sum+=3;
                break;
            case W_BISHOP:
                sum+=3;
                break;
            case W_QUEEN:
                sum+=9;
                break;

            //Sort sum
            case B_PAWN:
                sum--;
                break;
            case B_ROOK:
                sum-=5;
                break;
            case B_KNIGHT:
                sum-=3;
                break;
            case B_BISHOP:
                sum-=3;
                break;
            case B_QUEEN:
                sum-=9;
                break;
            }
        }
    }
    cout << "Board Evaluation: " << sum << endl;
    return sum;
}
// TRIN 2 SLUT

// TRIN 3 - UDGANGSPUNKT
vector<int> findBestMove(vector<vector<int>> board, vector<vector<int>> moves_list,int color)
{
    int maxScore = -1000;
    vector<int> bestMove, currentMove;
    vector<vector<int>> tmpBoard = board;

    for (unsigned int i = 0; i<moves_list.size(); i++)
    {
        currentMove = moves_list[i];

        // Move the piece on temporary board
        tmpBoard[currentMove[2]][currentMove[3]] = tmpBoard[currentMove[0]][currentMove[1]];
        tmpBoard[currentMove[0]][currentMove[1]] = EMPTY;

        int score = eval_pos(tmpBoard);

        if(color*score > maxScore)
        {
            maxScore = color*score;
            bestMove = currentMove;
        }

        tmpBoard = board;
    }

    return bestMove;
}
//TRIN 3 - SLUT

// COM MOVE - UDGANGSPUNKT

// Calculate computer move
vector<int> calc_com_move(vector<vector<int>> board)
{
    vector<vector<int>> COM_list;
    vector<vector<int>> current_pieces;

    float score = eval_pos(board);                              // Evaluate current position

    //The brain to make the Rook moves
    current_pieces = find_pieces(board,COM * W_ROOK);
    for(int k=0; k<current_pieces.size(); k++)
    {
        vector<vector<int>> move_list = valid_moves_rook(board,current_pieces[k][0],current_pieces[k][1], COM);
        COM_list.insert(COM_list.end(),move_list.begin(),move_list.end());
    }

    //The brain to make the Pawn moves
    current_pieces = find_pieces(board,COM * W_PAWN);
    for(int k=0; k<current_pieces.size(); k++)
    {
        vector<vector<int>> move_list = valid_moves_pawn(board,current_pieces[k][0],current_pieces[k][1], COM);
        COM_list.insert(COM_list.end(),move_list.begin(),move_list.end());
    }

    //The brain to make the Bishop moves
    current_pieces = find_pieces(board,COM * W_BISHOP);
    for(int k=0; k<current_pieces.size(); k++)
    {
        vector<vector<int>> move_list = valid_moves_bishop(board,current_pieces[k][0],current_pieces[k][1], COM);
        COM_list.insert(COM_list.end(),move_list.begin(),move_list.end());
    }

    int n = COM_list.size(); //n is a list over the pieces the computer can move
    if(n == 0)
    {
        cout << "The computer found no pieces to move!" << endl;
        exit(0);
    }
    print_moves(COM_list);
    vector<int> mv = findBestMove(board, COM_list, COM);

    /*    vector<int> mv = COM_list[randi(0,n)];                      // Choose random piece
        mv.push_back(randi(0,8));                                   // Choose random end location
        mv.push_back(randi(0,8));*/
    return mv;
}
// COM MOVE - SLUT
int main()
{
    int win_size = 10*70;   // (8+2) x (8+2) squares of 70 pixels
    srand(time(NULL));      // Initialize random generator
    rand();

    // TRIN 0 - ØVELSE STARTER HER
    vector<vector<int>> board(8,vector<int>(8,0));
    //Black pieces
    //  board[0][0]=B_ROOK;
    board[3][4]=B_BISHOP;
    /* board[0][2]=B_KNIGHT;
     board[0][3]=B_QUEEN;
     board[0][4]=B_KING;
     board[0][5]=B_KNIGHT;
     board[0][6]=B_BISHOP;
     board[0][7]=B_ROOK;
     board[1] = vector<int>(8,B_PAWN);

     //White pieces
      board[7][0]=W_ROOK;
      board[7][1]=W_BISHOP;
      board[7][2]=W_KNIGHT;
      board[7][3]=W_QUEEN;
      board[7][4]=W_KING;
      board[7][5]=W_KNIGHT;
      board[7][6]=W_BISHOP;*/
    board[7][7]=W_ROOK;
    // board[6] = vector<int>(8,W_PAWN);


    // TRIN 0 - ØVELSE SLUTTER HER

//  Initialize window and chess board
    Fl_Double_Window win(win_size,win_size,"Chess");
    win.color(WIN_COLOR);
    chess_GUI chess_board(win_size,board);
    win.end();
    win.show();

    return(Fl::run());
    eval_pos(board);
    return 0;
}
