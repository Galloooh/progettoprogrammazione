//
//  map.cpp
//  main
//
//  Created by Francesco Esposito on 22/03/23.
//

#include "map.hpp"
#include <ncurses.h>
Map::Map(int colonna, int riga)
{
           // Inizializza la libreria ncurses
    initscr();
    
    // Disegna il rettangolo
    int x = 0;
    int y = 0;
    int width = colonna;
    int height = riga;
    int corner_char = '+';
    int vertical_char = '|';
    int horizontal_char = '-';
    
    // Disegna la cornice del rettangolo
    mvaddch(y, x, corner_char);
    mvaddch(y + height - 1, x, corner_char);
    mvaddch(y, x + width - 1, corner_char);
    mvaddch(y + height - 1, x + width - 1, corner_char);
    for (int i = x + 1; i < x + width - 1; i++) {
        mvaddch(y, i, horizontal_char);
        mvaddch(y + height - 1, i, horizontal_char);
    }
    for (int i = y + 1; i < y + height - 1; i++) {
        mvaddch(i, x, vertical_char);
        mvaddch(i, x + width - 1, vertical_char);
    }
    
    // Aggiorna lo schermo
    refresh(); 
}


