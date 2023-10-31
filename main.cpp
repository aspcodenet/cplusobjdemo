#include <iostream>
#include <string>
#include <string.h>
#include  <utility>
#include  <vector>
using namespace std;
#include "player.h"

// Constructor initilization list, why
// inheritance (base class), 
// naming parameter name is same as data member , 
// performance example BELOW!
// non-static const data members,
// initialization of reference members
class CarColor{
public:
    string color;
    CarColor(){
        color = "Undefined";
    }
    CarColor(string color){
        this->color = color;
    }    
    int getPrice(){
        if(color == "red") return 199;
        return 299;
    }
};


class Car {
private:
    int year;
    CarColor color; // This is calling default contructor if not created as 
                    //contructor initializer
    // vehivle id number                     VIN
    const int vin;
    string regno; 
    
public:    
    Car(string regno,int yearIn, CarColor colorIn)
    :color(colorIn),year(yearIn), vin(123)
    {
        //When coming here all allocations are alredy done ()
        this->regno = regno;
    }
    friend ostream &operator<<(ostream &stream, const Car &player); 
};

ostream &operator<<(ostream &stream, const Car &player){
    stream << "***** " << player.regno << " " << player.year <<   "*****" << endl;
    return stream;
}

int main(){


    Player p(1973, "Peter Forsberg");
    Game game;
    game.away = "Toronto";
    game.home = "Colorado";
    game.goalsAway = 3;
    game.goalsHome = 3;
    p.addGame(game);
    //p.

    //p = p + game; // we are adding a game for player p
    





    Car car("ABC123",2013,CarColor("Green"));
    cout << car << " " <<  endl;
    int i = 12;
    int j;
    j = i;

    //
    j = 123;


    // BY DEFAULT THERE IS A  COPY CONSTRUCTOR GENERATED FOR US
    // each time we create a class - 

    //Player p2 {p};
    Player p2 = p; // DEFUALT Copy contrucior - only do SHALLOW COPY
    p2.name[0] = 'S'; 


    p2 = p; // COPY ASSIGNMENT // default copy assignment only do shallow copy
    //WE THOUGHT Peter Forsberg Seter Forsberg
    //WHAT HAPPENED Seter Forsberg Seter Forsberg

    cout << p.name << " " <<  p2.name << endl;
    //Player p2;
    //p2 = p; // copy assignment

    //Car car("ABC123",2013,CarColor("Green"));
    return 0;
}