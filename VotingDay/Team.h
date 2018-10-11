/*

Antikeimenostrafis Programmatismos
Master Chef 2018

Ntaoulas Xristos-Panagiotis / AEM:8208 / ntaoulac@auth.gr
Sifaki Maria-Ioanna / AEM:8241 / mnsifaki@auth.gr

*/

#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

class Team{

    string color;
    Player *players;

public:

    Team(){color = ""; players = new Player[11];}
    Team(string color);
    ~Team(){delete [] players; cout << "Team " << color << " is destroyed." << endl;}

    string getColor(){return color;}
    Player* getPlayers(){return players;}

    void setColor(string val){color = val;}

    int getNumberOfPlayers();
    void setCandidate(string player);
    void removePlayer(int index);
    void status(bool playerInformation);

};

#endif // TEAM_H_INCLUDED
