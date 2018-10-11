#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

class Team{

    string color;
    int wins;
    int supplies;
    Player *players;

public:

    Team(){color = ""; wins = 0; supplies = 0; players = new Player[11];}
    Team(string color);
    ~Team(){delete [] players; cout << "Team " << color << " is destroyed." << endl;}

    string getColor(){return color;}
    int getWins(){return wins;}
    int getSupplies(){return supplies;}
    Player* getPlayers(){return players;}

    void setColor(string val){color = val;}
    void setWins(int val){wins = val;}
    void setSupplies(int val){supplies = val;}

    void teamWorks();
    void teamEats();
    void teamSocializes();
    void teamSleeps();
    int getNumberOfPlayers();
    void status(bool playerInformation);
};

#endif // TEAM_H_INCLUDED
