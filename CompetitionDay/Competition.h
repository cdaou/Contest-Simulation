#ifndef COMPETITION_H_INCLUDED
#define COMPETITION_H_INCLUDED

#include <iostream>
#include <string>

#include "Team.h"

using namespace std;

class Competition{

protected:
    int id;
    string name;
    string winner;

public:

    //Dimiourgia twn klasewn arxikwn sinthikwn kai telikwn sinthikwn
    Competition(){id=0; name=""; winner="";}
    Competition(int id, string name){this->id=id; this->name=name;}
    ~Competition(){};

    //Dimiourgia twn setters olwn twn metablitwn
    void setId(int id){this->id=id;}
    void setName(string name){this->name=name;}
    void setWinner(string winner){this->winner=winner;}

    //Dimiourgia twn getters olwn twn metablitwn
    int getId(){return id;};
    string getName(){return name;}
    string getWinner(){return winner;}

    //Dimiourgia tis sunartisis status pou ektupwnei tis times twn metablitwn tis klasis ekeini tin wra
    void status(){cout << " ID: " <<  id << endl << " Name: " << name <<  endl << " Winner: " << winner << endl;}
};

#endif // COMPETITION_H_INCLUDED
