/*
 * character.hpp
 *
 *  Created on: 27 mar 2023
 *      Author: francesco
 */

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_


class Character {
public:
	Character();
    Character(int x, int y);
    void moveLeft();
    void moveRight();
    void moveLaserRight();
    void jump();
    void fall();
    void display();
    void displayAtt();
    void displayParry();
    void displayEnemy();
    void displayLaser();
    void danno();

    int x_pos, y_pos;
};



#endif /* CHARACTER_HPP_ */
