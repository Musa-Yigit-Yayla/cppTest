#include <string>
#include "Player.h"
#include "Team.h"
//class Player{
/*private:
    string name;
    int jersey;
    int salary;
    string teamName;

public:*/
using namespace std;

    Player::Player(string tn, string n, int j, int s): teamName(n), name(n), jersey(j), salary(s){

    }
    Player::Player(){

    }
    Player::~Player(){

    }
    void Player::setTeamName(string tn){
      teamName = tn;
    }
    void Player::setName(string n){
        name = n;
    }
    void Player::setJersey(int j){
        jersey = j;
    }
    void Player::setSalary(int s){
        salary = s;
    }
    string Player::getTeamName() const{
        return teamName;
    }
    string Player::getName() const{
        return name;
    }
    int Player::getJersey() const{
        return jersey;
    }
    int Player::getSalary() const{
        return salary;
    }
    string Player::toString() const{
        return this->name + (" " + std::to_string(this->jersey)) + (" " + std::to_string(this->salary)) + " " + this->teamName;
    }
//};


