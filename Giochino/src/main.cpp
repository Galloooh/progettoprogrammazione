#include <iostream>
#include <ncurses.h>
#include "map.hpp"
#include "character.hpp"
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
const int dim_colonna = 70;
const int dim_riga = 25;
const int refreshspeed = 10; // velocità di refresh dello schermo

int main(){

    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();
    refresh();

    Map map = Map(dim_colonna, dim_riga);
    Character player = Character(dim_colonna/2, dim_riga-2); // istanza il personaggio
    /*
    Character stormtrooper = Character(dim_colonna/2, dim_riga-2);
    */
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
            case 'w':
                player.jump();
                player.display();
                refresh();
                map.canc(player.x_pos, player.y_pos, 'P');
                usleep(100000);
                map.canc(player.x_pos, player.y_pos, 'P');
                player.jump();
                player.display();
                refresh();
                map.canc(player.x_pos, player.y_pos, 'P');
                usleep(100000);
                map.canc(player.x_pos, player.y_pos, 'P');
                player.jump();
                //intervallo di spostamento
                int ch;
				ch = getch();
				if(ch == 100){
					player.moveRight();
				}
				if(ch == 97){
					player.moveLeft();
				}

                //intervallo di spostamento
                //ritorno a terra
                player.fall();
                player.display();
                refresh();
                map.canc(player.x_pos, player.y_pos, 'P');
                usleep(100000);
                map.canc(player.x_pos, player.y_pos, 'P');
                player.fall();
                player.display();
                refresh();
                map.canc(player.x_pos, player.y_pos, 'P');
                usleep(100000);
                map.canc(player.x_pos, player.y_pos, 'P');
                player.fall();
                break;
            case 'e':
            	player.displayAtt();
            	refresh();
                usleep(300000);
                break;
            case 'p':
				player.displayParry();
            	refresh();
            	usleep(300000);
            	break;
            default:
                break;
        }
        
        // Ri-disegna la mappa e il personaggio
        map.draw(player.x_pos, player.y_pos, 'P');
        map.canc(player.x_pos, player.y_pos, 'P');
        player.display();
        refresh();
        usleep(refreshspeed*1000);
    }

    endwin();
}
