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
	nemico = Character(dim_colonna/3, dim_riga-2);
}

bool game::gamerunning(){
	return true;
}

bool parrying = false;

int c;
//personaggio è due volte più veloce di nemico
void game::setCharacter(){

	timeout(500);

    c = getch();

    					mappa.draw(personaggio.x_pos, personaggio.y_pos, 'P');
        		        mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
        		        personaggio.display();
    		switch(c) {
    	            case 'a':
    	                personaggio.moveLeft();
    	                personaggio.moveLeft();

    	                break;
    	            case 'd':
    	                personaggio.moveRight();
    	                personaggio.moveRight();

    	                break;
    	            case 'w':
    	                personaggio.jump();
    	                personaggio.display();
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                usleep(100000);
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                personaggio.jump();
    	                personaggio.display();
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
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                usleep(100000);
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                personaggio.fall();
    	                personaggio.display();
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                usleep(100000);
    	                mappa.canc(personaggio.x_pos, personaggio.y_pos, 'P');
    	                personaggio.fall();
    	                break;
    	            case 'e':
    	            	personaggio.displayAtt();
    	                usleep(300000);
    	                break;
    	            case 'p':
    	            	personaggio.displayParry();
    	            	parrying=true;
    	            	usleep(300000);
    	            	break;
    	            default:
    	                break;
    	        }

}

void game::setEnemy(){

	nemico.displayEnemy();

	if( nemico.x_pos == (personaggio.x_pos-6) ){
		int i=0;
		while(i<6){
			nemico.displayLaser();
			nemico.moveLaserRight();
			usleep(100000);
		    mappa.canc(nemico.x_pos, nemico.y_pos, '-');
		    i++;
		}

	//assegnazione danno
	if( nemico.x_pos == personaggio.x_pos && ( parrying == false )){
		nemico.danno();
	}
	else {
		printw("colpo deviato");
	}
    mappa.canc(nemico.x_pos, nemico.y_pos, '-');
    //spostamento nemico
    nemico.moveLeft();
    nemico.moveLeft();
	nemico.displayEnemy();

	}


	else if(personaggio.x_pos>nemico.x_pos){
	nemico.moveRight();
	}
	else if(personaggio.x_pos<nemico.x_pos){
	nemico.moveLeft();
	}
	parrying = false;
}




