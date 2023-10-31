#ifndef __PLAYER_H
#define __PLAYER_H

// MEANING OF HEADER - contain "no code"
// give other cpp files an hint this is how the class look like
// what are the functions, contructors, large
// code -> CPP

#include <string>
#include <vector>
using namespace std;

class Game{
public:
    string home;
    string away;
    int goalsHome;
    int goalsAway;
};


/*
when adding objects in vectors/lists/arrays I like to 
create the object as a new instance with information injected into the constructor 
like myvector.push(new Player(name, team, birthyear))
*/

class Player{
private:
    vector<Game> games;
public:
    void addGame(Game game);

    Player &operator+(const Game &game){
        games.push_back(game);
    }


    int year; //1973 p1   -> p2
    //char *name; // 0x23443 p1 -> p2
    char *name; // 0x23443 p1 -> p2

    Player(int year, char *name);
    Player(const Player &other);

    
//    Player& Player::operator=(const Player& other);


    ~Player();
};



#endif // __PLAYER_H