#include "TeamCompetition.h"

using namespace std;

int TeamCompetition::compete(Team &team1, Team &team2){

    team1.setWins(0);
    team2.setWins(0);
    int counter=0; //metritis apo 0 ews 2, gia tin loupa twn triwn girwn
    float tech1=0, tech2=0; //h mesh texnikh katartisi twn 5 paiktwn gia kathe omada antistoixa
    float fat1=0, fat2=0;  //h mesh kourasi twn 5 paiktwn gia kathe omada antistoixa
    int position[5];  //5 tuxaioi arithmoi apo 0 ews 10, gia tin epilogi 5 tuxaiwn paiktwn
    int temp1=0;  //oi nikes tis prwtis omadas stous 3 gurous

    for (counter=0;counter<3;counter++){

        rounds[counter].setId(counter);
        rounds[counter].setDuration(rand()%61);

        position[0]=rand()%11;
        team1.getPlayers()->compete();
        team2.getPlayers()->compete();
        tech1=tech1 + team1.getPlayers()->getTechnique();
        tech2=tech2 + team2.getPlayers()->getTechnique();
        fat1=fat1 + team1.getPlayers()->getFatigue();
        fat2=fat2 + team2.getPlayers()->getFatigue();

        for(int i=1;i<5;i++){
            do{position[i]=rand()%11;}
            while(position[i]!=position[i-1]);
            (team1.getPlayers()+position[i])->compete();
            (team2.getPlayers()+position[i])->compete();
            tech1=tech1 + (team1.getPlayers()+position[i])->getTechnique();
            tech2=tech2 + (team2.getPlayers()+position[i])->getTechnique();
            fat1=fat1 + (team1.getPlayers()+position[i])->getFatigue();
            fat2=fat2 + (team2.getPlayers()+position[i])->getFatigue();
        }

        tech1=tech1/5;
        tech2=tech2/5;
        fat1=fat1/5;
        fat2=fat2/5;

        if(tech1>tech2){
            rounds[counter].setWinner(team1.getColor());
            temp1++;
        }else if(tech1<tech2){
            rounds[counter].setWinner(team2.getColor());
        }else{
            if(fat1<fat2){
                rounds[counter].setWinner(team1.getColor());
                temp1++;
            }else{
                rounds[counter].setWinner(team2.getColor());
            }
        }
    }


    if(temp1>=2){
        int w=team1.getWins();
        team1.setWins(w++);
        int s=team1.getSupplies();
        team1.setSupplies(s+foodAward.getBonusSupplies());
        winner = "Red Team";
        return 1;
    }else{
        int w=team2.getWins();
        team2.setWins(w++);
        int s=team2.getSupplies();
        team2.setSupplies(s+foodAward.getBonusSupplies());
        winner = "Blue Team";
        return 0;
    }


}

