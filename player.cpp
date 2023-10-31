#include <string.h>
#include "player.h"

Player::Player(int year, char *name):year(year)
{
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
}

Player::Player(const Player &other):year(other.year){
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name,other.name);
}


void Player::addGame(Game game){
    games.push_back(game);
}



//  Player& Player::operator=(const Player& other) // copy assignment
//  {
//      return *this = Player(other);
//  }




Player::~Player(){
    delete []name;
}

