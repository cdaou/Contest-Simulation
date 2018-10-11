/*

Antikeimenostrafis Programmatismos
Master Chef 2018

Ntaoulas Xristos-Panagiotis / AEM:8208 / ntaoulac@auth.gr
Sifaki Maria-Ioanna / AEM:8241 / mnsifaki@auth.gr

*/

#ifndef COMPETITION_H_INCLUDED
#define COMPETITION_H_INCLUDED

#include <string>
#include <iostream>
#include "Player.h"
#include "Team.h"
#include "ImmunityAward.h"

using namespace std;

class Competition{

protected:
    int id;
    string name;
    string winner;

public:

    Competition(){id = 0; name = "";}
    Competition(int i, string n){id = i; name = n;}
    ~Competition(){cout << "Competition with id " << id << " and name " << name << " is destroyed." << endl;}

    void setName(string s){name = s;}
    void setId(int id){this->id = id;}
    void setWinner(string w){winner = w;}

    int getId(){return id;}
    string getName(){return name;}
    string getWinner(){return winner;}

    void status(){cout << "Competition Id: " << id << endl; cout << "Competition Name: " << name << endl; cout << "Winner: " << winner << endl;}
};


#endif // COMPETITION_H_INCLUDED
