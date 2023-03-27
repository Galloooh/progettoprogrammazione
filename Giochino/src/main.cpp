#include <iostream>
#include <ncurses.h>
#include "map.hpp"
#include "character.hpp"
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

    Map map = Map(dim_colonna, dim_riga);
    Character player = Character(dim_colonna/2, dim_riga-2); // istanza il personaggio

    int c;
    while (true) {
        c = getch();
        switch(c) {
            case 'a':
                player.moveLeft();
                break;
            case 'd':
                player.moveRight();
                break;
            case 'space':
                player.jump();
                break;
            case 's':
                player.fall();
                break;
            default:
                break;
        }

        // Ri-disegna la mappa e il personaggio
        map.draw(player.x_pos, player.y_pos, 'P');
        player.display();
        refresh();
        usleep(refreshspeed*1000);
    }

    endwin();
}