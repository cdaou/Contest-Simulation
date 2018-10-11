#ifndef IMMUNITYCOMPETITION_H_INCLUDED
#define IMMUNITYCOMPETITION_H_INCLUDED

#include "Competition.h"
#include "ImmunityAward.h"
#include <cstdlib>

using namespace std;

class ImmunityCompetition : public Competition{

    ImmunityAward immunityAward;
    Player* p;

public:

    //Dimiourgia twn klasewn arxikwn sinthikwn kai telikwn sinthikwn
    ImmunityCompetition(){immunityAward=ImmunityAward();}
    ImmunityCompetition(int id, string name, ImmunityAward immunityAward) : Competition(id, name) {this->immunityAward=immunityAward;}
    ~ImmunityCompetition(){delete p;};

    //Dimiourgia twn setters olwn twn metablitwn
    void setImmunityAward(ImmunityAward immunityAward){this->immunityAward=immunityAward;}

    //Dimiourgia twn getters olwn twn metablitwn
    ImmunityAward getImmunityAward(){return immunityAward;}

    //Dimiourgia tis sunartisis status pou ektupwnei tis times twn metablitwn tis klasis ekeini tin wra
    void status(){
        cout << "Competition Status: " << endl;
        Competition::status();
        cout << endl << "Immunity Award Status: " << endl;
        immunityAward.status();
    }

    void compete(Team &team);
};

#endif // IMMUNITYCOMPETITION_H_INCLUDED
