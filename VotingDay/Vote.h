/*

Antikeimenostrafis Programmatismos
Master Chef 2018

Ntaoulas Xristos-Panagiotis / AEM:8208 / ntaoulac@auth.gr
Sifaki Maria-Ioanna / AEM:8241 / mnsifaki@auth.gr

*/

#ifndef VOTE_H_INCLUDED
#define VOTE_H_INCLUDED
#include <iostream>

using namespace std;

class Vote{

    string voted, reason;

public:

    //orismos enos kenou constuctor kai enos constructor me orismata
    Vote(){voted=""; reason="";}
    Vote(string voted, string reason){this->voted=voted; this->reason=reason;}

    //orismos twn setters twn metavlitwn
    void setVoted(string voted){this->voted=voted;}
    void setReason(string reason){this->reason=reason;}

    //orismos twn getters twn metavlitwn
    string getVoted(){return voted;}
    string getReason(){return reason;}

    //orismos tis sunartisis status pou ektipwnei tis times twn metablitwn tis sunartisis ekeini tin stigmi
    void status(){
        cout << "the player voted is: " << voted << " and the reason is: " << reason << endl;
    }

};

#endif // VOTE_H_INCLUDED

