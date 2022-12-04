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
            return name;
        }
        int Team::getFoundationYear() const{
            return foundationYear;
        }
        void Team::addPlayer(Player player){
            if(this->playersLength == 0){
                this->players = new Player[1];
                this->players[0] = player;
                this->playersLength = 1;
                std::cout << "Added player " << player.getName() << " to the team " << this->name << "." << endl;
            }
            else{
                //check whether we already have the same jersey number in the team
                Player* currPlayers = this->players;
                for(int i = 0; i < this->playersLength; i++){
                    if((currPlayers++)->getJersey() == player.getJersey()){
                        cout << "Cannot add player jersey number " << player.getJersey() << " already exists." << endl;
                        return;
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


                std::cout << "Added player " << player.getName() << " to the team " << this->name << "." << endl;
            }
        }
        Player* Team::removePlayer(string name){
            Player* returnValue;
            for(int i = 0; i < this->playersLength; i++){
                int comparison = name.compare(this->players[i].getName());
                if(comparison == 0){
                    returnValue = &players[i];
                    //players[i] = nullptr;
                    //shift elements
                    for(int j = i; j < playersLength - 1; j++){
                        players[j] = players[j + 1]; // might be problematic !!!
                    }
                    this->playersLength--;
                    return returnValue;
                }
            }
            return nullptr;
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
            return playersLength;
        }
        int Team::getTotalSalary() const{
            int sum = 0;
            for(int i = 0; i < playersLength; i++){
                sum += players[i].getSalary();
            }
            return sum;
        }
        Player* Team::getPlayers() const{
            return players;
        }
//};
