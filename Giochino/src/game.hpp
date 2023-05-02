/*
 * game.hpp
 *
 *  Created on: 27 apr 2023
 *      Author: francesco
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "character.hpp"
#include "map.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>



class game {
public:
	game (int colonna, int riga);
	void setCharacter();
	void setEnemy();
	bool gamerunning();
	void resetMoves();
	Map mappa;
	Character personaggio;
	Character nemico;
};

#endif /* GAME_HPP_ */
