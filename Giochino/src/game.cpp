/*
 * game.cpp
 *
 *  Created on: 27 apr 2023
 *      Author: francesco
 */
#include "game.hpp"



game::game(int dim_colonna, int dim_riga){
    mappa = Map(dim_colonna, dim_riga);
	personaggio = Character(dim_colonna/2, dim_riga-2); // istanza il personaggio
	nemico = Character(dim_colonna/2, dim_riga-2);
}

int c;

void game::moveCharacter(){

	timeout(1000);

    c = getch();

    		switch(c) {
    	            case 'a':
    	                personaggio.moveLeft();
    	                break;
    	            case 'd':
    	                personaggio.moveRight();
    	                break;
    	            case 'w':
    	                personaggio.jump();
    	                personaggio.display();
    	                refresh();
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                usleep(100000);
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                personaggio.jump();
    	                personaggio.display();
    	                refresh();
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                usleep(100000);
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                personaggio.jump();
    	                //intervallo di spostamento
    	                int ch;
    					ch = getch();
    					if(ch == 100){
    						personaggio.moveRight();
    					}
    					if(ch == 97){
    						personaggio.moveLeft();
    					}

    	                //intervallo di spostamento
    	                //ritorno a terra
    					personaggio.fall();
    					personaggio.display();
    	                refresh();
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                usleep(100000);
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                personaggio.fall();
    	                personaggio.display();
    	                refresh();
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                usleep(100000);
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                personaggio.fall();
    	                break;
    	            case 'e':
    	            	personaggio.displayAtt();
    	            	refresh();
    	                usleep(300000);
    	                break;
    	            case 'p':
    	            	personaggio.displayParry();
    	            	refresh();
    	            	usleep(300000);
    	            	break;
    	            default:
    	                break;
    	        }

    				mappa.draw(personaggio.x_pos, personaggio.y_pos, 'P');
    		        mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    		        personaggio.display();
    		        refresh();
    		        usleep(1000);

    		        mappa.draw(nemico.x_pos, nemico.y_pos, 'S');
    		        mappa.canc(nemico.x_pos, nemico.y_pos, 'S');
    		        nemico.displayEnemy();
    		        nemico.moveLeft();
    		        refresh();
}



