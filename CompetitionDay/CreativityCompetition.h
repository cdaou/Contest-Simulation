#ifndef CREATIVITYCOMPETITION_H_INCLUDED
#define CREATIVITYCOMPETITION_H_INCLUDED

#include "Competition.h"
#include "ExcursionAward.h"
#include <cstdlib>

using namespace std;

class CreativityCompetition : public Competition{

    ExcursionAward excursionAward;
    static string ingredients[10];
    Player* P[22];

public:

    //Dimiourgia twn klasewn arxikwn sinthikwn kai telikwn sinthikwn
    CreativityCompetition(){excursionAward=ExcursionAward(); }
    CreativityCompetition(int id, string name, ExcursionAward excursionAward) : Competition(id, name) {this->excursionAward=excursionAward;};
    ~CreativityCompetition(){delete [] P; cout << endl << "Temporary table for all players is destroyed." << endl;};

    //Dimiourgia twn setters olwn twn metablitwn
    void setExcursionAward(ExcursionAward excursionAward){this->excursionAward=excursionAward;}
    void setIngredients(string ingredients[10]){
        for(int i=0;i<11;i++){
          this->ingredients[i]=ingredients[i];
        }
    }

    //Dimiourgia twn getters olwn twn metablitwn
    ExcursionAward getExcursionAward(){return excursionAward;}
    string* ing=ingredients;
    string* getIngredients(){return ing;}

    //Dimiourgia tis sunartisis status pou ektupwnei tis times twn metablitwn tis klasis ekeini tin wra
    void status(){
        cout << endl << "Competition Status: " << endl;
        Competition::status();
        cout << endl << "Creativity Award Status: " << endl;
        excursionAward.status();
        cout << endl << "The ingredients are: " << endl;
        for(int i=0;i<10;i++){
            cout << " " << ingredients[i] << ",";

        }
    }

    void compete(Team &team1, Team &team2);
};

#endif // CREATIVITYCOMPETITION_H_INCLUDED
