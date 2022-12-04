#ifndef PLAYER_H
#define PLAYER_H
//#pragma once
#include "Team.h"
#include <string>

using namespace std;

class Player{
public:
    Player(string, string, int, int);
    Player();
    ~Player();
    void setTeamName(string);
    void setName(string);
    void setJersey(int);
    void setSalary(int);
    string getTeamName() const;
    string getName() const;
    int getJersey() const;
    int getSalary() const;
    string toString() const;

private:
    string teamName;
    string name;
    int jersey;
    int salary;
};

#endif // PLAYER_H
