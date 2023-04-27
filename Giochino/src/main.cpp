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

    game Game = game (dim_colonna, dim_riga);


	while(true){
		Game.moveCharacter();
	}
    endwin();

}
