#ifndef CHESS_GUI_H
#define CHESS_GUI_H

#include <vector>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>

// Chess pieces
const int W_KING    = 1;
const int W_QUEEN   = 2;
const int W_ROOK    = 3;
const int W_BISHOP  = 4;
const int W_KNIGHT  = 5;
const int W_PAWN    = 6;
const int EMPTY     = 0;
const int B_KING    = -1;
const int B_QUEEN   = -2;
const int B_ROOK    = -3;
const int B_BISHOP  = -4;
const int B_KNIGHT  = -5;
const int B_PAWN    = -6;

// Black pieces are negative and white are positive
const int BLACK     = -1;
const int WHITE     = 1;

// Player and computer color, PLAYER or COM color times chess piece (e.g. COM*W_KING) is >0 for own pieces and <0 for enemy pieces
const char PLAYER   = WHITE;
const char COM      = BLACK;

// Color of the window background (around the board)
const int WIN_COLOR = FL_LIGHT2;

// Function headers for main.cpp file
void print_move(std::vector<int> mv);
std::vector<int> calc_com_move(std::vector<std::vector<int>> board);

// Chess board widget
class chess_GUI : public Fl_Widget
{
public:
    chess_GUI(int W, std::vector<std::vector<int>> startposition);
    void draw() override;
    int handle(int event) override;
    void update_piece(std::vector<int> mv);

private:
    const int board_size;
    const int s_size;
    const char* int_to_unicode(int i);
    Fl_Double_Window* parent_win;
    std::vector<std::vector<int>> board;
    std::vector<int> click1;
    std::vector<int> click2;
};

#endif // CHESS_GUI.H
