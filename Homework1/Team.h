#ifndef TEAM_H
#define TEAM_H
//#pragma once
#include <string>
#include "Player.h"

using namespace std;

struct Team;
struct Player;

class Team{
public:
    Team(string, int);
    Team();
    ~Team();
    string getName() const;
    int getFoundationYear() const;
    bool addPlayer(Player);
    Player* removePlayer(string); // pass the player name to check
    Player* getPlayer(string) const;
    int getPlayersLength() const;
    int getTotalSalary() const;
    Player* getPlayers() const;
    void setPlayers(Player*, int);
private:
    string name;
    Player* players = nullptr;
    int playersLength = 0; // length of the players array
    //int playersLastIndex = 0;
    int foundationYear = 0;
};
#endif // TEAM_H
