#include <iostream>
#include <ncurses.h>
#include "map.hpp"
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
const int dim_colonna = 70;
const int dim_riga = 25;
const int refreshspeed = 100; // velocità di refresh dello schermo

int main(){
    
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();
    refresh();
    
    Map map = Map (dim_colonna, dim_riga);
    
    endwin();
}
