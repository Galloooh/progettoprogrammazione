//
//  map.cpp
//  main
//
//  Created by Francesco Esposito on 22/03/23.
//

#include "map.hpp"
#include <ncurses.h>
#include <stdlib.h>
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

    initPattern();
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




    refresh();
}

void Map::initPattern(){
char strcpy( pattern0,    "=============================="
                          "|                            |"
                          "|                            |"
                          "|                            |"
                          "|                            |"
                          "|                            |"
                          "|        ====                |"
                          "|     ===         ===        |"
                          "|   ===           ===        |"
                          "==============================" );
    strcpy( pattern1,     "=============================="
                          "|                            |"
                          "|                            |"
                          "|                            |"
                          "|                    ===     |"
                          "|                            |"
                          "|     ===         ===    === |"
                          "|         ===         ===    |"
                          "|  ===         ===           |"
                          "==============================" );
    strcpy( pattern2,     "=============================="
                          "|                            |"
                          "|                            |"
                          "|                            |"
                          "|                            |"
                          "|                   ===      |"
                          "|        ===      ===        |"
                          "|     ===    ===    ===      |"
                          "|   ===                  === |"
                          "==============================" );
    strcpy( pattern3,     "=============================="
                          "|                            |"
                          "|                            |"
                          "|                 ====       |"
                          "|              ===    ===    |"
                          "|           ===     ==  ==   |"
                          "|          ===               |"
                          "|     ===                    |"
                          "|   ===                      |"
                          "==============================" );
    strcpy( pattern4,     "=============================="
                          "|                            |"
                          "|                            |"
                          "|                            |"
                          "|                  ======    |"
                          "|            ===        ===  |"
                          "|         ===    === ===     |"
                          "|       ===                  |"
                          "|    ====   ===              |"
                          "==============================" );
}
void Map::draw(int x, int y, char c)
{
	addch(pattern0);
    //mvaddch(y, x, c);
    refresh();
}
void Map::canc(int x, int y, char c){
    mvaddch(y , x - 1, ' '); // cancella il carattere precedente
    mvaddch(y , x + 1, ' '); // cancella il carattere precedente
    mvaddch(y + 2 , x, ' '); // cancella il carattere precedente
    mvaddch(y + 1 , x, ' '); // cancella il carattere precedente
    mvaddch(y - 2 , x, ' '); // cancella il carattere precedente
    mvaddch(y - 1 , x, ' '); // cancella il carattere precedente
    refresh();
}




