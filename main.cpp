#include <iostream>
#include <curses.h>
#include <ncurses.h>
#include <SDL.h>
#include "SDL_video.h"
#include "tracks.cpp"

using namespace std;

WINDOW *create_newwin(int height, int width, int starty, int startx, bool border);
void destroy_win(WINDOW *local_win);
void redraw_listing(WINDOW *local_win, song *index, int count);
void draw_highlighted(WINDOW *local_win, int width, int y, int x, string text);

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;

int main(int argc, char *argv[]) {
	WINDOW *window_one;
	WINDOW *window_two;

	SDL_Window *window = NULL;
	SDL_Surface *screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	} else {
		window = SDL_CreateWindow("Rendered Output", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
		} else {
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);
			SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
			//SDL_Event e; bool quit = false; while(quit == false){ while(SDL_PollEvent( &e )){if(e.type == SDL_QUIT) quit = true;}}
		}
	}

	create_track_data();
	int position = 0;

	song index[] = {track_one, track_two, track_three};

	int ch;

	initscr();
	curs_set(0);
	cbreak();
	raw();
	noecho();

	keypad(stdscr, TRUE);

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_WHITE, COLOR_RED);
	clear();

        refresh();

	window_one = create_newwin(LINES, COLS / 2, 0, 0, false);
	window_two = create_newwin(LINES, COLS / 2, 0, COLS / 2, true);

	string message = "F1 to exit";

	redraw_listing(window_one, index, (int)sizeof(index) / (int)sizeof(index[0]));
	draw_highlighted(window_one, COLS / 2, position, 0, "> " + index[position].name + " by " + index[position].artist + " performed by " + index[position].performers);
	wrefresh(window_one);

	wmove(window_two, LINES / 2, COLS / 4 - (message.size() / 2));
	wprintw(window_two, "%s", message.c_str());
	wrefresh(window_two);

	while((ch = getch()) != KEY_F(1)) {
		switch(ch) 
		{
			case KEY_UP:
				if (position > 0) {
					position--;
					werase(window_one);
					redraw_listing(window_one, index, (int)sizeof(index) / (int)sizeof(index[0]));
					draw_highlighted(window_one, COLS / 2, position, 0, "> " + index[position].name + " by " + index[position].artist + " performed by " + index[position].performers);
					wrefresh(window_one);
				}
				break;
			case 10:
			case 32:
			case KEY_DOWN:
				if (position < (int)sizeof(index) / (int)sizeof(index[0]) - 1) {
					position++;
					werase(window_one);
					redraw_listing(window_one, index, (int)sizeof(index) / (int)sizeof(index[0]));
					draw_highlighted(window_one, COLS / 2, position, 0, "> " + index[position].name + " by " + index[position].artist + " performed by " + index[position].performers);
					wrefresh(window_one);
				}
				break;
		}
	}

	endwin();
	return 0;
}

void redraw_listing(WINDOW *local_win, song *index, int count) {
	for (int i = 0; i < count; i++) {
		wmove(local_win, i, 0);
		wprintw(local_win, "%s by %s performed by %s", (index[i].name).c_str(), (index[i].artist).c_str(), (index[i].performers).c_str());
	}
}

void draw_highlighted(WINDOW *local_win, int width, int y, int x, string text) {
	wattron(local_win, COLOR_PAIR(2));
	wmove(local_win, y, x);
	for (int i = 0; i < width; i++) {
		wprintw(local_win, " ");
	}
	wmove(local_win, y, x);
	wprintw(local_win, "%s", text.c_str());

	wattroff(local_win, COLOR_PAIR(2));
}

WINDOW *create_newwin(int height, int width, int starty, int startx, bool border) {
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	if (border) {
		box(local_win, 0, 0);
	}
	wbkgd(local_win, COLOR_PAIR(1));

	wrefresh(local_win);
	return local_win;
}

void destroy_win(WINDOW *local_win) {
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}
