#ifndef LEAGUEMANAGEMENTSYSTEM_H
#define LEAGUE_MANAGEMENTSYSTEM_H
//#pragma once
#include <string>
#include "Team.h"
using namespace std;

class LeagueManagementSystem {
    private:
        Team* teams = nullptr;
        int teamSize = 0;
        //int teamLastIndex = 0; // index of the right most tean
    public:
        LeagueManagementSystem();
        ~LeagueManagementSystem();
        void addTeam( string name, int year );
        void removeTeam( const string);
        void addPlayer( const string teamName, const string playerName,
        const int jersey, const int salary );
        void removePlayer( const string teamName, const string playerName );
        void transferPlayer( const string playerName,
        const string departTeamName, const string arriveTeamName );
        void showAllTeams() const;
        void showTeam( const string name ) const;
        void showPlayer( const string name ) const;
};
#endif // LEAGUEMANAGEMENTSYSTEM_H
