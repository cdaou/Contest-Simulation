#ifndef TEAMCOMPETITION_H_INCLUDED
#define TEAMCOMPETITION_H_INCLUDED

#include "Competition.h"
#include "FoodAward.h"
#include "Round.h"
#include <cstdlib>

using namespace std;

class TeamCompetition : public Competition{

    FoodAward foodAward;
    Round rounds[3];

public:

    //Dimiourgia twn klasewn arxikwn sinthikwn kai telikwn sinthikwn
    TeamCompetition(){foodAward=FoodAward(); rounds[3]=Round();}
    TeamCompetition(int id, string name, FoodAward foodAward) : Competition(id, name) {this->foodAward=foodAward;}
    ~TeamCompetition(){};

    //Dimiourgia twn setters olwn twn metablitwn
    void setFoodAward(FoodAward foodAward){this->foodAward=foodAward;}
    void setRound(Round rounds[3]){
        for(int i=0;i<4;i++){
            this->rounds[i]=rounds[i];
        }
    }

    //Dimiourgia twn getters olwn twn metablitwn
    FoodAward getFoodAward(){return foodAward;}
    Round* r=rounds;
    Round *getRound(){return r;}

    //Dimiourgia tis sunartisis status pou ektupwnei tis times twn metablitwn tis klasis ekeini tin wra
    void status(){
        cout << "Competition Status: " << endl;
        Competition::status();
        cout << endl << "Food Award Status: " << endl;
        foodAward.status();
        for(int i=0;i<3;i++){
            cout << endl << "The winner of round " << i+1 << " is the " << rounds[i].getWinner() << " team" << endl;
        }
        cout << endl << "The winner of the competition is the " << winner << endl;

    }

    int compete(Team &team1, Team &team2);
};

#endif // TEAMCOMPETITION_H_INCLUDED
