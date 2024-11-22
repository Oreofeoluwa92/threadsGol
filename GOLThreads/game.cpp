#include "game.h"
#include <cstdlib>
#include <ctime>
#include <string>

MATRIX grid;
MATRIX next_grid;
  

void init_game() {
    grid = MATRIX(M, VEC(M, 0));
    next_grid = MATRIX(M, VEC(M, 0));

    // Initialize with random live cells
    srand(time(nullptr));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

int count_live_neighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int nx = (x + i + M) % M;
            int ny = (y + j + M) % M;
            count += grid[nx][ny];
        }
    }
    return count;
}

void update_subregion(int start_row, int end_row, int start_col, int end_col) {
    for (int i = start_row; i < end_row; i++) {
        for (int j = start_col; j < end_col; j++) {
            int live_neighbors = count_live_neighbors(i, j);
            if (grid[i][j] == 1) {
                next_grid[i][j] = (live_neighbors == 2 || live_neighbors == 3) ? 1 : 0;
            }
            else {
                next_grid[i][j] = (live_neighbors == 3) ? 1 : 0;
            }
        }
    }
}

void display_grid() {
    clear();
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            mvaddch(i, j * 2, grid[i][j] ? 'X' : ' ');
        }
    }
    refresh();
}

