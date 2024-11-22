#include "game.h"
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

bool auto_advance = false;
int M, N, MAX;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " M N MAX" << std::endl;
        return 1;
    }

    M = std::atoi(argv[1]);
    N = std::atoi(argv[2]);
    MAX = std::atoi(argv[3]);

    if (M % N != 0) {
        std::cerr << "M must be divisible by N" << std::endl;
        return 1;
    }

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(0);  // Non-blocking input
   start_color();
   use_default_colors();
    nodelay(stdscr, TRUE);
    init_game();

    int sub_size = M / N;
    std::vector<std::thread> threads(N * N);
    int delay = 100;  // milliseconds
  
    int gen = 0;
while (gen < MAX) {
    // Create and run threads
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int thread_id = i * N + j;
            int start_row = i * sub_size;
            int end_row = (i + 1) * sub_size;
            int start_col = j * sub_size;
            int end_col = (j + 1) * sub_size;
            threads[thread_id] = std::thread(update_subregion, start_row, end_row, start_col, end_col);
        }
    }

    // Wait for threads
    for (auto& t : threads) {
        t.join();
    }

    // Update display
     erase();
    display_grid();
    mvprintw(M, 0, "Generation: %d ", gen + 1);
    refresh();

    // Handle input
    int ch = getch();
    if (ch == 'q') {
        break;
    } else if (ch == 'n' && !auto_advance) {
        std::swap(grid, next_grid);
        gen++;
        continue;
    } else if (ch == 'a') {
        auto_advance = !auto_advance;
    }

     if (auto_advance) {
        napms(delay);  // More efficient than sleep_for
        std::swap(grid, next_grid);
        gen++;
    }
}


    // Clean up ncurses
    endwin();
    return 0;
}


