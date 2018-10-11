#ifndef EXCURSIONAWARD_H_INCLUDED
#define EXCURSIONAWARD_H_INCLUDED

#include "Award.h"
#include <cstdlib>

using namespace std;

class ExcursionAward : public Award{

    int techniqueBonus;
    int popularityPenalty;

public:

    ExcursionAward(){techniqueBonus = 0; popularityPenalty = 0;}
    ExcursionAward(string n, bool s) : Award(n,s) {techniqueBonus = 5; popularityPenalty =-10;}

    int getTechniqueBonus(){return techniqueBonus;}
    int getPopularityPenalty(){return popularityPenalty;}

    void status(){Award::status(); cout << " Technique Bonus: " << techniqueBonus << endl << " Popularity Penalty: " << popularityPenalty << endl << endl; }

};


#endif // EXCURSIONAWARD_H_INCLUDED
