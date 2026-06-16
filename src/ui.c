#include <stdio.h>
#include <ncurses.h>

#include "ui.h"

WINDOW *win_header;
WINDOW *win_dir;
WINDOW *win_playlist;
WINDOW *win_nowPlaying;
WINDOW *win_controls;

void initCurses() {
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);

	if (has_colors()) {
		start_color();
		init_pair(1, COLOR_CYAN, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_BLACK);
		init_pair(4, COLOR_WHITE, COLOR_BLACK);
		init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	}
	//getch();
	endwin();
}

void drawUi() {
	int rows, cols;
	getmaxyx(stdscr, rows, cols);

	int dirWidth = cols / 3;
	int playlistWidth = dirWidth - cols;
	int contentRows = rows - 6;

	win_header = newwin(2, cols, 0, 0);
	win_dir = newwin(contentRows, dirWidth, 2, 0);
	win_playlist = newwin(contentRows, playlistWidth, 2, dirWidth);
	win_nowPlaying = newwin(2, cols, rows - 4, 0);
	win_controls = newwin(2, cols, rows - 2, 0);
}

void drawHeader() {
	wbkgd(win_header, COLOR_PAIR(1));
	wattron(win_header, A_BOLD | COLOR_PAIR(1));
	mvwprintw(win_header, 0, 2, " My Music Player");
	mvwprintw(win_header, 0, COLS - 12, "[Vol: 80%]");
	wattroff(win_header, A_BOLD);
	wrefresh(win_header);
}

void drawProgressBar() {

}

void drawPlaylist() {

}

void drawDir() {

}

void drawControls() {

}
