#include <iostream>
#include <string>
#include <string.h>
#include  <utility>
#include  <vector>
using namespace std;

// Constructor initilization list, why
// inheritance (base class), 
// naming parameter name is same as data member , 
// performance example BELOW!
// non-static const data members,initialization of reference members
//  
//1. CarColor 
//2. 


class CarColor{
public:
    string color;
    CarColor(){
        color = "Undefined";
    }
    CarColor(string color):color(color){
    }    
    int getPrice(){
        if(color == "red") return 199;
        return 299;
    }
};

class Car {
private:
    char regno[20]; //should use string I know, trying to make a point
    int year;
    CarColor color; // This is calling default contructor if not created as 
                    //contructor initializer

public:    
    Car(const char *regno,int year, CarColor color)
    {
        strcpy(this->regno,regno);
        this->year = year;
        this->color = color; // vs :color(color) - default contructor called
    }
};

class Game{
public:
    string home;
    string away;
    int goalsHome;
    int goalsAway;
};

class Player{
private:
    vector<Game> games;
public:
    Player &operator+(const Game &game){
        games.push_back(game);
    }
    void addGame(Game game){
        games.push_back(game);
    }
    int year;
    char *name;
    
    Player(int year, char *name):year(year)
    {
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
    }

    // Player(const Player &other):year(other.year){
    //     this->name = new char[strlen(other.name)+1];
    //     strcpy(this->name,other.name);

    // }

    //Destructor...
    // Player::~Player(){
    //     delete []name;
    // }

    // Player& operator=(const Player& other) // copy assignment
    // {
    //     return *this = Player(other);
    // }

    // Player(Player&& other):year(other.year),
    //  name(std::exchange(other.name, nullptr)){}

    // Player& operator=(Player&& other) noexcept // move assignment
    // {
    //     std::swap(name, other.name);
    //     year = other.year;
    //     return *this;
    // }
};

// ostream &operator<<(ostream &stream, const Player &player){
//     stream << "***** " << player.name <<   "*****" << endl;
//     return stream;
// }

//Rules of three
// If a class requires a user-defined destructor, 
// a user-defined copy constructor, 
// or a user-defined copy assignment operator, it almost certainly requires all three.

//Rules of five
// add move constructor and move assignment as well!

typedef enum{
    GAMEOBJECT_SNAKEHEAD,
    GAMEOBJECT_SNAKEBODY,
    GAMEOBJECT_FOOD,
    GAMEOBJECT_EMPTY
} GAMEOBJECT;

#define COLS 20
#define ROWS 40
class ScreenMatrix{

    GAMEOBJECT m_data[COLS][ROWS]{};
public:
    ScreenMatrix(){
        memset(m_data,GAMEOBJECT_EMPTY,sizeof(GAMEOBJECT) * COLS *ROWS);
    }
    GAMEOBJECT &operator()(int col,int row){
        return m_data[col][row];
    }

} ;



int main(){
    Car car("ABC123",1999,CarColor("Green"));



    Player p1(100,"Stefan");
    Player p2 = p1; // Copy by value - vad kopieras???
    p2.name[0] = 'N';
    //p1 = p2; //Copy assignment
    cout << p1.name << " " << p2.name << endl;



    ScreenMatrix screen;
    screen(12,13) = GAMEOBJECT_FOOD;


    Game g1{"Dif", "AIK",3,3}; // curly braces initialization
    p1.addGame(g1);

    Game g2{"Dif", "Whatever",1,3};
    p1 = p1 + g2;

    //cout << p1 << endl;


    return 0;
}