/*

Antikeimenostrafis Programmatismos
Master Chef 2018

Ntaoulas Xristos-Panagiotis / AEM:8208 / ntaoulac@auth.gr
Sifaki Maria-Ioanna / AEM:8241 / mnsifaki@auth.gr

*/

#ifndef IMMUNITYAWARD_H_INCLUDED
#define IMMUNITYAWARD_H_INCLUDED

#include "Award.h"

using namespace std;

class ImmunityAward : public Award{

    int votes;

public:

    ImmunityAward(){votes = 0;}
    ImmunityAward(string n, bool s) : Award(n,s) { votes = s ? 2 : 1;}

    void setVotes(int val){votes = val;}
    int getVotes(){return votes;}

    void status(){Award::status(); cout << "Votes: " << votes << endl << endl; }
};

#endif // IMMUNITYAWARD_H_INCLUDED
