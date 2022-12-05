#include "LeagueManagementSystem.h"
#include "Player.h"
#include "Team.h"
#include <string>
#include <iostream>

using namespace std;

//class LeagueManagementSystem{

//private:
    //Team* teams = new Team[1];
    //int teamSize = 1;
    //int teamLastIndex = 0; // last index of the last team

//public:
        LeagueManagementSystem::LeagueManagementSystem(){
            teams = new Team[0];
        }
        LeagueManagementSystem::~LeagueManagementSystem(){

        }
        void LeagueManagementSystem::addTeam(string name, int year){
            //check each team whether we have the team already

            for(int i = 0; i < teamSize; i++){
                //int x = name.compare("hello");
                int comparison = name.compare("" + (this->teams[i].getName()));
                if(comparison == 0){
                    cout << "Cannot add team. Team " << name << " already exists" << endl;
                    return;
                }
            }

            Team newTeam(name, year);
          //if(teamLastIndex >= teamSize){
            //increment the size of players array
            Team* newTeams = new Team[this->teamSize + 1]; // Might be problematic !!!
            //copy elements

            for(int i = 0; i < teamSize; i++ ){
                newTeams[i] = this->teams[i]; // might be problematic !!!
            }
            //delete[] teams; // may need to remove !!!
                // able to add the team
                newTeams[(this->teamSize)] = newTeam;

                std::cout << "Added team " << newTeam.getName() << endl;

                delete[] this->teams;
                this->teams = newTeams;
                this->teamSize++;
                /*Team* tPtr = teams;
                delete[] teams;
                tPtr = newTeams;
                this->teams[++teamSize] = newTeam;*/
        }

        //}
        void LeagueManagementSystem::removeTeam( const string name ){
            //Team* returnValue;
            //returnValue = nullptr;
            bool isRemoved = false;
            //1-) find the index of the element to be removed
            //2-) shift the elements until then

            //for(int i = 0; i < this->teamSize; i++){
                /*int comparison = name.compare(this->teams[i].getName());
                if(comparison == 0){
                    //retrieve the index
                    isRemoved = true;
                    //removedIndex = i;
                    for(int j = i; j < this->teamSize; j++){
                        if(j != this->teamSize - 1){
                            this->teams[j] = this->teams[j + 1];
                        }
                        else{
                            //delete (&this->teams[j]);
                            Team* teamPtr = &(this->teams[j]);
                            delete teamPtr;

                        }
                    }
                    break;
                }
            }*/
            /*int j = removedIndex;
            while(j < this->teamSize && removedIndex != -1){
                this->teams[j] = this->teams[j + 1];
                j++;
            }*/
            for(int i = 0; i < this->teamSize; i++){
                    int comparison = name.compare("" + (this->teams[i].getName()));
                    if(comparison == 0){

                        //this->teams[i] = nullptr;
                        isRemoved =  true;
                        //returnValue = (teams[i]);
                        //teams[i] = nullptr;
                        //shift elements
                        for(int j = i; j < this->teamSize - 1; j++){
                            teams[j] = teams[j + 1]; // might be problematic !!!
                        }
                        //return returnValue;
                    }
            }
            //Create a smaller array, copy the elements then finally delete the original array. Subsequently pass the newArray as the original's pointer

            if(isRemoved){
                Team* newTeams = new Team[this->teamSize - 1];
                for(int i = 0; i < this->teamSize - 1; i++){
                    newTeams[i] = teams[i];
                }
                delete[] this->teams;
                this->teams = newTeams;
                this->teamSize--;
                std::cout << "Removed team " << name << "." << endl;
            }
            else{
                std::cout << "Cannot remove team. Team " << name << " does not exist." << endl;
            }
        }

        void LeagueManagementSystem::addPlayer (const string teamName, const string playerName,
        const int jersey, const int salary ){
            Player* newPlayer = new Player(teamName, playerName, jersey, salary);
            bool added = false;
            //find the corresponding team
            for(int i = 0; i < teamSize; i++){
                int comparison = teamName.compare(this->teams[i].getName());
                if(comparison == 0){
                    added = teams[i].addPlayer(*newPlayer);
                    break;
                }
                else if(i == this->teamSize -1){
                    std::cout << "Cannot add player " << (*newPlayer).getName() << ". Team " << teamName << " does not exist." << endl;
                    delete newPlayer;
                }
            }


        }
        void LeagueManagementSystem::removePlayer( const string teamName, const string playerName ){
            for(int i = 0; i < teamSize; i++){
                if(teams[i].getName() == teamName){
                    teams[i].removePlayer(playerName);
                    break;
                }
                else if(i == teamSize - 1){
                    std::cout << "Cannot remove player " << playerName << ". Team " << teamName << " does not exist." << endl;
                }
            }
        }
        void LeagueManagementSystem::transferPlayer( const string playerName,
        const string departTeamName, const string arriveTeamName ){

            //Check whether both teams exist in LMS

            Team* departTeam = nullptr;
            Team* arriveTeam = nullptr;

            for(int i = 0; i < this->teamSize; i++){
                Team curr = this->teams[i];
                string currName = curr.getName();
                int comparison1 = currName.compare(departTeamName);
                if(comparison1 == 0){
                    departTeam = &curr;
                }
                int comparison2 = currName.compare(arriveTeamName);
                if (comparison2 == 0){
                    arriveTeam = &curr;
                }
                else if(i == this->teamSize -1){
                    if(departTeam == NULL){
                        std::cout << "Cannot transfer player. Team" <<  departTeamName << "does not exist." << endl;
                        return;
                    }
                    else if(arriveTeam == NULL){
                        std::cout << "Cannot transfer player. Team" <<  arriveTeam->getName() << "does not exist." << endl;
                        return;
                    }
                }
            }
            //check whether player exists in departTeam
            Player* departPlayer = departTeam->getPlayer(playerName);
            Player* departPlayers = departTeam->getPlayers();
            Player* arrivePlayers = arriveTeam->getPlayers();

            if(departPlayer == NULL){
                std::cout << "Cannot transfer player. Player " << playerName << " does not exist." << endl;
                return;
            }

            //check whether jersey exists in arrive team
            for(int i = 0; i < arriveTeam->getPlayersLength(); i++){
                Player curr =  arrivePlayers[i];
                int jersey = departPlayer->getJersey();
                //cout << "HELLOOOOOO" << playerName << endl;
                if( jersey == curr.getJersey() ){
                    //std::cout << "CURRJERSEY" << (curr.getName()) << endl;
                    std::cout << "Cannot transfer player. Jersey number " << jersey << " already exists in team " << arriveTeamName << endl;
                    return;
                }
            }
            //shift the elements of depart team

            Player* newDepartPlayers = new Player[departTeam->getPlayersLength() - 1];
            Player* newArrivePlayers = new Player[arriveTeam->getPlayersLength() + 1];
            for(int i = 0; i < departTeam->getPlayersLength(); i++){
                if(departPlayers[i].getJersey() == departPlayer->getJersey()){
                    for(int j = i; j < departTeam->getPlayersLength() - 1; j++){
                        departPlayers[j] = departPlayers[j + 1];
                    }
                    for(int j = 0; j < departTeam->getPlayersLength() - 1; j++){
                        newDepartPlayers[i] = departPlayers[i];
                    }
                    departTeam->setPlayers(newDepartPlayers, departTeam->getPlayersLength() - 1); // set the new Players to the depart team object
                    break;
                }
            }
            //change the array of arrive players
            for(int j = 0; j < arriveTeam->getPlayersLength(); j++){
                newArrivePlayers[j] = arrivePlayers[j];
            }
            newArrivePlayers[arriveTeam->getPlayersLength()] = *departPlayer;
            arriveTeam->setPlayers(newArrivePlayers, arriveTeam->getPlayersLength() + 1);

            std::cout << "Transferred player " << departPlayer->getName() << " from team " << departTeamName << " to team " << arriveTeam->getName() << "." << endl;
        }
        void LeagueManagementSystem::showAllTeams() const{
            cout << endl;
            cout << "Teams in the league management system:" << endl;
            if(teamSize == 0){
                cout << "None";
            }
            for(int i = 0; i < teamSize; i++){
                Team curr = teams[i];
                cout << curr.getName() << ", " << curr.getFoundationYear() << ", " << curr.getPlayersLength() << " players, " << curr.getTotalSalary() << endl;
            }
        }
        void LeagueManagementSystem::showTeam( const string name ) const{
            for(int i = 0; i < this->teamSize; i++){
                Team curr = this->teams[i];
                if(curr.getName() == name){
                    std::cout << curr.getName() << ", " << curr.getFoundationYear() << ", " << curr.getPlayersLength() << " players, " << curr.getTotalSalary() << " total salary.\nPlayers" << endl;
                    Player* players = curr.getPlayers();
                    for(int i = 0; i < curr.getPlayersLength(); i++){
                        std::cout << players[i].toString() << endl;
                    }

                }
                else if(i == this->teamSize - 1){
                    std::cout << "Team " << name << " does not exist.";
                }
            }
        }
        void LeagueManagementSystem::showPlayer( const string name ) const{
            for(int i = 0; i < teamSize; i++){
                Player* currPlayers = teams[i].getPlayers();
                for(int j = 0; i < teams[j].getPlayersLength(); j++){
                    //check each player to ensure whether we have the corresponding player
                    int comparison = name.compare(currPlayers[j].getName());
                    if(comparison == 0){
                        cout << currPlayers[i].toString();
                        return;
                    }
                }
            }
            cout << "Player " << name << " does not exist." << endl;
        }

//};
