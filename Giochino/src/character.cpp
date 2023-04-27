#include <ncurses.h>
#include "character.hpp"
#include <unistd.h>
const int dim_colonna = 70;
const int dim_riga = 25;

Character::Character(){
	x_pos=1;
	y_pos=1;
}

Character::Character(int x, int y) {
    x_pos = x;
    y_pos = y;
}

void Character::moveLeft() {
    if (x_pos > 2) { // controlla che il personaggio non vada fuori dalla cornice
        x_pos--;
    }
}

void Character::moveRight() {
    if (x_pos < dim_colonna - 2) { // controlla che il personaggio non vada fuori dalla cornice
        x_pos++;
    }
}

void Character::jump() {
    if (y_pos > 2) { // controlla che il personaggio non vada fuori dalla cornice
        y_pos--;
        y_pos--;// il personaggio salta di due blocchi
    }

}


void Character::fall() {
    if (y_pos < dim_riga - 2) { // controlla che il personaggio non vada fuori dalla cornice
        y_pos++;
        y_pos++;

    }
}

void Character::display() {
    mvaddch(y_pos, x_pos, 'P');
    mvaddch(y_pos, x_pos - 1, ' '); // cancella il carattere precedente
    mvaddch(y_pos , x_pos + 1, ' '); // cancella il carattere precedente
    mvaddch(y_pos + 2 , x_pos , ' '); // cancella il carattere precedente

}
void Character::displayEnemy() {
    mvaddch(y_pos, x_pos, 'S');
    mvaddch(y_pos, x_pos - 1, ' '); // cancella il carattere precedente
    mvaddch(y_pos , x_pos + 1, ' '); // cancella il carattere precedente
    mvaddch(y_pos + 2 , x_pos , ' '); // cancella il carattere precedente

}
void Character::displayAtt() {
    mvaddch(y_pos, x_pos, '/');
    mvaddch(y_pos, x_pos - 1, ' '); // cancella il carattere precedente
    mvaddch(y_pos , x_pos + 1, ' '); // cancella il carattere precedente
    mvaddch(y_pos + 2 , x_pos , ' '); // cancella il carattere precedente

}
void Character::displayParry() {
    mvaddch(y_pos, x_pos, '|');
    mvaddch(y_pos, x_pos - 1, ' '); // cancella il carattere precedente
    mvaddch(y_pos , x_pos + 1, ' '); // cancella il carattere precedente
    mvaddch(y_pos + 2 , x_pos , ' '); // cancella il carattere precedente

}
