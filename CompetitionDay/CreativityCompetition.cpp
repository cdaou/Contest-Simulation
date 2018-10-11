#include "CreativityCompetition.h"
#include "Round.h"

using namespace std;

void CreativityCompetition::compete(Team &team1, Team &team2){

    int maxTechnique=-1 , maxIndex=-1; //to megalitero pososto tis texnikis katartisis & i thesi ston pinaka twn paiktwn ston opoio brethike
    int playerIndex; //metritis gia thn loupa ston pinaka twn 22 paiktwn
    float technique; //apothikeuetai proswrina i texnikh katartisi tou ekastote
    Round round1;

    int id=getId();
    round1.setId(id++);
    round1.setDuration(rand()%61);


    for(int i=0; i<11; i++ ){

        P[i]=(team1.getPlayers()+i);
        P[i+11]=(team2.getPlayers()+(i+11));
    }

    for(playerIndex=0; playerIndex<22; playerIndex++){

        technique=P[playerIndex]->getTechnique();

        if(technique>maxTechnique){
            maxTechnique=technique;
            maxIndex=playerIndex;
        }
    }

    cout << endl << "The winner of the creativity competition is: " << endl;


    if(maxIndex<11){

        float tech=(team1.getPlayers()+maxIndex)->getTechnique();
        tech=tech+tech*(excursionAward.getTechniqueBonus())/100;
        (team1.getPlayers()+maxIndex)->setTechnique(tech);

        float pop=(team1.getPlayers()+maxIndex)->getPopularity();
        pop=pop+pop*(excursionAward.getPopularityPenalty())/100;
        (team1.getPlayers()+maxIndex)->setPopularity(pop);

        (team1.getPlayers()+maxIndex)->status();

        winner=(team1.getPlayers()+maxIndex)->getName();

    }else{

        float tech=(team2.getPlayers()+(maxIndex-11))->getTechnique();
        tech=tech+tech*(excursionAward.getTechniqueBonus())/100;
        (team2.getPlayers()+(maxIndex-11))->setTechnique(tech);

        float pop=(team2.getPlayers()+(maxIndex-11))->getPopularity();
        pop=pop+pop*(excursionAward.getPopularityPenalty())/100;
        (team2.getPlayers()+(maxIndex-11))->setPopularity(pop);

        (team2.getPlayers()+(maxIndex-11))->status();

        winner=(team2.getPlayers()+(maxIndex-11))->getName();

    }

    round1.setWinner(winner);

}
