#include <ncurses.h>

void init(void) {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void erase (int y, int x) {
    mvaddch(y, x, '#');
}

void game_loop(char main_char, int row, int col, int ch) {
    // Check if the user wishes to play the game
    if(ch == 'q' || ch =='Q') return;
    nodelay(stdscr, TRUE);

    bool state = false;
    // Show the main character on the screen
    mvaddch(row, col, main_char);
    refresh();

    for(;;) {
        ch = getch();
        erase(row, col);

        if(ch == KEY_LEFT) {
            col = col - 1;
        }
        else if(ch == KEY_RIGHT) {
            col = col + 1;
        }
        else if(ch == KEY_UP) {
            row = row - 1;
        }
        else if(ch == KEY_DOWN) {
            row = row + 1;
        }
        else if(ch == 'q' || ch == 'Q') {
            break;
        }
        mvaddch(row, col, main_char);
        refresh();
        main_char = (state ? '<' : '>');
        state = !state;
    }
}


int main() {
    // Define main character symbol and initial position
    int row = 10, col = 10;
    char main_char = '>';

    // Start ncurses
    init();

    // Print a welcome message on screen
    printw("Welcome to the RR game.\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");

    // Wait until the user press a key
    int ch = getch();

    // Clear the screen
    clear();

    // Start the game loop
    game_loop(main_char, row, col, ch);

    // Clear ncurses data structures
    endwin();

    return 0;
}
