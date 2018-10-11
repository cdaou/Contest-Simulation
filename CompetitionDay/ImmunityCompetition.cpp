#include "ImmunityCompetition.h"
#include "Round.h"

using namespace std;

void ImmunityCompetition::compete(Team &team){

    float maxRate=-1; //to megalitero pososto tou sindiasmou texnikis katartisis kai mi kourasis
    int index=-1;  //o paiktis (diladi i thesi tou ston pinaka) ston opoio anikei to megalitero pososto
    Round round1;

    int id=getId();
    round1.setId(id++);
    round1.setDuration(rand()%61);

    for(int i=0;i<11;i++){
        p=team.getPlayers()+i;
        float temp=(p->getTechnique())*0.75 + (100-(p->getFatigue()))*0.25;
        if (temp>maxRate){
            maxRate=temp;
            index=i;
        }
    }

    cout << endl << "The maximun rate is: " << maxRate << endl;
    cout << endl << "The winner of the immunity competition is: " << endl;
    (team.getPlayers()+index)->status();

    winner=(team.getPlayers()+index)->getName();
    round1.setWinner(winner);
}
