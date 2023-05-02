#include <iostream>
#include "game.hpp"
#include <ncurses.h>
const int dim_colonna = 70;
const int dim_riga = 25;


int main(){


    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();
    refresh();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    game Game = game (dim_colonna, dim_riga);


	while(Game.gamerunning()){
		Game.setEnemy();
		Game.setCharacter();
		refresh();
	}
    endwin();

}
