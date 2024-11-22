#ifndef GAME_H
#define GAME_H

#include <vector>
#include <ncurses.h>

using VEC = std::vector<int>;
using MATRIX = std::vector<VEC>;

extern int M, N, MAX;
extern MATRIX grid;
extern MATRIX next_grid;

void init_game();
int count_live_neighbors(int x, int y);
void update_subregion(int start_row, int end_row, int start_col, int end_col);
void display_grid();
void handle_input(int& delay);

#endif // GAME_H