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
            int removedIndex = -1;
            //1-) find the index of the element to be removed
            //2-) shift the elements until then

            for(int i = 0; i < this->teamSize; i++){
                int comparison = name.compare(this->teams[i].getName());
                if(comparison == 0){
                    //retrieve the index
                    isRemoved = true;
                    removedIndex = i;
                }
            }
            for(int j = removedIndex; j < this->teamSize - 1 && removedIndex != -1; j++){ // MIGHT BE PROBLEMATIC
                this->teams[j] = this->teams[j + 1];
            }
            /*for(int i = 0; i < this->teamSize; i++){
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
            }*/
            //Create a smaller array, copy the elements then finally delete the original array. Subsequently pass the newArray as the original's pointer
            /*Team* newTeams = new Team[this->teamSize - 1];
            for(int i = 0; i < this->teamSize - 1; i++){
                newTeams[i] = teams[i];
            }
            delete[] this->teams;
            this->teams = newTeams;*/
            this->teamSize--;
            if(isRemoved){
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
                    teams[i].addPlayer(*newPlayer);
                    added = true;
                }
            }
            if(!added){
                std::cout << "Cannot add player " << (*newPlayer).getName() << ". Team " << teamName << " does not exist.";
                //delete newPlayer;
            }

        }
        void LeagueManagementSystem::removePlayer( const string teamName, const string playerName ){
            for(int i = 0; i < teamSize; i++){
                if(teams[i].getName() == teamName){
                    teams[i].removePlayer(playerName);
                    break;
                }
            }
        }
        void LeagueManagementSystem::transferPlayer( const string playerName,
        const string departTeamName, const string arriveTeamName ){
            Player transferPlayer;
            for(int i = 0; i < teamSize; i++){
                if(teams[i].getName() == departTeamName){
                    transferPlayer = *teams[i].removePlayer(playerName);
                }
            }
            for(int i = 0; i < teamSize; i++){
                if(teams[i].getName() == arriveTeamName){
                    teams[i].addPlayer(transferPlayer);
                }
            }

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
            for(int i = 0; i < teamSize; i++){
                Team curr = teams[i];
                if(curr.getName() == name){
                    cout << curr.getName() << ", " + curr.getFoundationYear() << ", " + curr.getPlayersLength() << " players, " << curr.getTotalSalary() << endl;
                }
            }
        }
        void LeagueManagementSystem::showPlayer( const string name ) const{
            for(int i = 0; i < teamSize; i++){
                    Player* curr = teams[i].getPlayer(name);
                if(curr->getName() == name){
                    cout << curr->toString();
                }
            }
        }

//};
