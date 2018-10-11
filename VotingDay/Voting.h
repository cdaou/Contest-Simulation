/*

Antikeimenostrafis Programmatismos
Master Chef 2018

Ntaoulas Xristos-Panagiotis / AEM:8208 / ntaoulac@auth.gr
Sifaki Maria-Ioanna / AEM:8241 / mnsifaki@auth.gr

*/

#ifndef VOTING_H_INCLUDED
#define VOTING_H_INCLUDED
#include "Vote.h"
#include "Team.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


class Voting{

    static vector<Vote> votes; //orismos enos statikou dianismatos gia tis psifous (vector)
    static map<string, int> results; //orismos enos statikou xarti gia ta apotelesmata twn psifwn (map)

public:

    static void votingProcess(Team &team); //orismos tis statikis sunartisis votingProcess

};



#endif // VOTING_H_INCLUDED

