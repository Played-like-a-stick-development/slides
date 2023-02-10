#include <curses.h>
#include <ncurses.h>
#include <string>

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main(int argc, char *argv[]) {
	WINDOW *window_one;
	WINDOW *window_two;
	int ch;

	initscr();
	cbreak();

	keypad(stdscr, TRUE);

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_WHITE, COLOR_RED);

	printw("Press F1 to exit");
	refresh();
	window_one = create_newwin(LINES, COLS, 0, 0);
	window_two = create_newwin(LINES, COLS / 2, 0, COLS / 2);

	std::string message = "Test";

	wmove(window_one, LINES / 2, COLS / 4 - (message.size() / 2));
	wprintw(window_one, "%s", message.c_str());
	wrefresh(window_one);
	wmove(window_two, LINES / 2, COLS / 4 - (message.size() / 2));
	wprintw(window_two, "%s", message.c_str());
	wrefresh(window_two);

	while((ch = getch()) != KEY_F(1)) {
		switch(ch) {}
	}

	endwin();
	return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx) {
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);
        wbkgd(local_win, COLOR_PAIR(1));

	wrefresh(local_win);
	return local_win;
}

void destroy_win(WINDOW *local_win) {
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}
