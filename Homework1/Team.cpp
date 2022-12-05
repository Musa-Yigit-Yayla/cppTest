#include "Team.h"
#include "Player.h"
#include <string>
#include <iostream>

using namespace std;
/*class Team{
private:
        string name;
        Player* players = new Player[1];
        int playersLength = 1;
        int playersLastIndex = 0; //for players array last index
        int foundationYear = 0;
public:*/
        Team::Team(string n, int fy): name(n), foundationYear(fy){

        }
        Team::Team(){

        }
        Team::~Team(){

        }
        string Team::getName() const{
            return this->name;
        }
        int Team::getFoundationYear() const{
            return this->foundationYear;
        }
        bool Team::addPlayer(Player player){
            if(this->playersLength == 0){
                this->players = new Player[1];
                this->players[0] = player;
                this->playersLength = 1;
                std::cout << "Added player " << player.getName() << " to the team " << this->name << "." << endl;
                return true;
            }
            else{
                //check whether we already have the same jersey number in the team
                Player* currPlayers = this->players;
                for(int i = 0; i < this->playersLength; i++){
                    if((currPlayers++)->getJersey() == player.getJersey()){
                        cout << "Cannot add player jersey number " << player.getJersey() << " already exists in team " << this->name << "." << endl;
                        return false;
                    }
                }

                //if(playersLastIndex >= playersLength){
                    //double the size of players array
                Player* newPlayers = new Player[this->playersLength + 1];
                    //copy elements
                for(int i = 0; i < this->playersLength; i++ ){
                    newPlayers[i] = players[i];
                }
                newPlayers[this->playersLength] = player;
                delete[] players; // may need to remove !!!
                this->players = newPlayers;
                this->playersLength++; // MAY NEED TO REMOVE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
                std::cout << "Added player " << player.getName() << " to the team " << this->name << "." << endl;
                return true;
            }
        }
        Player* Team::removePlayer(string name){
            Player* returnValue = nullptr;
            bool isRemoved = false;
            for(int i = 0; i < this->playersLength; i++){
                int comparison = name.compare(this->players[i].getName());
                if(comparison == 0){
                    isRemoved = true;
                    //shift elements
                    returnValue = &players[i]; // MAY GIVE WRONG RESULTS !!!!!!!!
                    for(int j = i; j < this->playersLength - 1; j++){
                        this->players[j] = this->players[j + 1];
                    }
                    break;
                }
                else if(i == this->playersLength - 1){
                    std::cout << "Cannot remove player. Player " << name << " does not exist." << endl;
                }
            }
            if(isRemoved){
                Player* newPlayers = new Player[this->playersLength - 1];
                for(int i = 0; i < this->playersLength - 1; i++){
                    newPlayers[i] = this->players[i];
                }
                delete[] this->players;
                this->players = newPlayers;
                this->playersLength--;
                std::cout << "Removed player " << name << "from team " << this->name << "." << endl;

            }
            return returnValue;
        }
        Player* Team::getPlayer(string name) const{ // MAY NEED TO REMOVE CONST
            Player* returnValue = nullptr;
            for(int i = 0; i < playersLength; i++){
                if(players[i].getName() == name){
                    returnValue = &players[i];
                }
            }
            return returnValue;
        }
        int Team::getPlayersLength() const{
            return this->playersLength;
        }
        int Team::getTotalSalary() const{
            int sum = 0;
            for(int i = 0; i < playersLength; i++){
                sum += players[i].getSalary();
            }
            return sum;
        }
        Player* Team::getPlayers() const{
            return this->players;
        }
        void Team::setPlayers(Player* newPlayers, int length){
            delete[] this->players;
            this->players = newPlayers;
            this->playersLength = length;
        }
//};
