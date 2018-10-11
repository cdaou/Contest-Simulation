/*

Antikeimenostrafis Programmatismos
Master Chef 2018

Ntaoulas Xristos-Panagiotis / AEM:8208 / ntaoulac@auth.gr
Sifaki Maria-Ioanna / AEM:8241 / mnsifaki@auth.gr

*/

#include "Voting.h"

//i sinartisi chooseVoted pairnei san orismo to Team pou einai ta stoixeia tis omadas kai twn paiktwn,
//to indexVoter pou einai i thesi tou paikti pou psifizei kai enan pinaka me to score(analuetai parakatw)
int chooseVoted(Vote v[3], Team &team, int indexVoter, float score[11]) {

    Player *player = team.getPlayers(); //metabliti tipou pointer pou deixnei ton pinaka twn paiktwn apo tin klasi Team
    float maxScore = -1; //metabliti pou exei to megisto ap' ton pinaka pou upologisame ta score twn paiktwn
    int indexVoted; // i timi pou epistrefei i sinartisi me tin thesi tou paikti pou prepei na psifistei

    //epanalipsi gia tin epe3ergasia tou kathe paikti
    for(int i=0; i<11; i++){
        string name = (player+i)->getName(); //pairnoume to onoma tou kathe paikti
        //elegxoume wste na min psifistei o idios paiktis pou psifizei kai gia na min uparxei diplotupi psifos
        if( (i!=indexVoter)&&(name != v[0].getVoted())&&(name != v[1].getVoted())&&(name != v[2].getVoted())){
            //elegxoume an autos pou tha psifisoume den exei asulia
            if ((player+i)->getImmunity() != true){
                if(score[i] > maxScore){
                    //upologizoume to megisto score kai kratame ti thesi tou paikti
                    maxScore = score[i];
                    indexVoted = i;
                }
            }
        }
    }
    //epistrefoume ti thesi tou paikti me to megisto score, diladi tou paikti pou prepei na psifistei
    return indexVoted;
}

 void Voting::votingProcess(Team &team){

    Player *player = team.getPlayers(); //metabliti tipou pointer pou deixnei ton pinaka twn paiktwn apo tin klasi Team
    map<string, int>::iterator p; //enas deiktis gia ton xarti
    float score[11]; //enas pinakas 11 thesewn me to score tou kathe paikti
    int indexVoted; //i thesi tou paikti pou prepei na psifistei


    for(int i=0; i<11; i++){
        //gia kathe paikti upologizoume ena score sto opoio upologizetai kata 40% i texniki tou, kata 40% h dimotikotita tou
        //kai kata 20% h mi-kourasi. O paiktis me to megalutero score psifizetai gia apoxorisi, efoson ikanopoiountai oi alles sinthikes.
        score[i] = ((player+i)->getTechnique())*0.4 +  ((player+i)->getPopularity())*0.4 + (100-((player+i)->getFatigue()))*0.2;
    }


    for(int i=0; i<11; i++){

        Vote tempVote[3]; //enas pinakas 3 thesewn gia tis psifous tou kathe paikti (an exei asulia, alliws xrisimopoieitai i mia thesi)

        //enas pinakas 5 thesewn me logous apoxorwsisi
        string reason[5] = {"Exei arxigikes taseis", "Einai marioneta tou eksosti", "Den pairnei tin eu8ini twn piatwn tou", "Einai axristos", "Ta fagita toy einai amixana"};

        indexVoted = chooseVoted(tempVote, team, i, score); //kaleitai i sunartisi chooseVoted, i opoia epistrefei tin thesi tou paikti pou prepei na psifistei
        tempVote[0] = Vote ( (player+indexVoted)->getName(), reason[rand()%5] ) ; //eisagoume tin prwti psifo ston pinaka tempVote
        votes.push_back(tempVote[0]); //eisagoume tin prwti psifo (tempVote[0] sto dianusma

        if( (player+i)->getImmunity() == true ){

            //an o paiktis exei asulia dikaioutai alli 1 i' 2 psifous, opote me ton idio tropo eisagoume tis psifous ston pinaka tempVote
            //kai sti sunexeia sto vector
            indexVoted = chooseVoted(tempVote, team, i, score);
            tempVote[1] = Vote ( (player+indexVoted)->getName(), reason[rand()%5] ) ;
            votes.push_back(tempVote[1]);


            if(rand()%1==0){
                //me tuxaio tropo (an i rand dwsei 0 i' 1) o paiktis me asulia apofasizei na dwsei kai triti psifo
                indexVoted = chooseVoted(tempVote, team, i, score);
                tempVote[2] = Vote ( (player+indexVoted)->getName(), reason[rand()%5] ) ;
                votes.push_back(tempVote[2]);

            }
        }
    }

    //ektipwnoume tis psifous
    cout << "---" << endl ;
    cout << "Contents of vector votes:" << endl;
    for (int i=0 ; i < votes.size(); i++){
        votes[i].status();
    }
    cout << "---" << endl ;

    int max1=-1; //o 1os megistos arithmos psifwn
    int max2=-1; //o 2os megaluteros arithmwn psifwn
    string index1=""; //to onoma tou prwtou ipopsifiou
    string index2=""; //to onoma tou deuterou ipopsifiou


    for (int i=0 ; i < votes.size(); i++){

        p = results.find(votes[i].getVoted());
        //elegxoume an iparxei i ekastote psifos ston xarti me ta apotelesmata

        if (p != results.end()){
            //an iparxei, simainei oti exei psifistei idi estw mia fora, opote apla auksanoume tis psifous tou kata 1
            p->second = p->second + 1;
        }
        else{
            //an den iparxei prosthetoume to onoma tou paikti pou psifistike kai to 1 pou dilwnei tin prwti psifo
            results.insert(pair<string,int>(votes[i].getVoted(), 1));
        }
    }

    for(p=results.begin(); p!=results.end();++p){
        //ektipwnoume tis psifous tou kathe paikti
        cout << "The player " << p->first << " has " << p->second << " vote(s)" << endl;

        //upologizoume ton megisto arithmo psifwn, diladi ton prwto ipopsifio
        if(p->second >= max1){
            //ws prwtos ipopsifios orizetai o teleutaios paiktis(se periptwsi isopsifias stin prwti thesi)
            //tou pinaka pou exei ton megalitero arithmo psifwn
            max1=p->second;
            index1=p->first;
        }
    }
    for(p=results.begin(); p!=results.end();++p){

        if( (p->second >= max2) && (p->second<max1) ){
            //an den uparxei isopsifia me ton megisto arithmo psifwn
            //upologizoume ton deutero megalitero arithmo psifwn kai ton paikti pou to exei
            max2=p->second;
            index2=p->first;
        }else if(p->second==max1 && p->first!=index1){
                //alliws briskoume to onoma enos allou paikti pou exei idio arithmo psifwn me ton prwto ipopsifio
                max2=p->second;
                index2=p->first;
        }
    //se periptwsi idiou arithmou psifwn allwn paiktwn me ton prwto ipopsifio, epilegetai  ws deuteros ipopsifios
    //autos pou einai se megaliteres theseis tou pinaka twn paiktwn.
    //se periptwsi monadikou megistou arithmou psifwn, alla iparksi perissoterwn paiktwn me idio arithmo psifwn me ton deutero
    //megalitero arithmo, epilegetai  ws deuteros ipopsifios autos pou einai se megaliteres theseis tou pinaka twn paiktwn.
    }

    int pos1=-1,pos2=-1; //oi theseis ston pinaka paiktwn tou prwtou kai tou deuterou ipopsifiou
    for(int i=0; i<11; i++){

        //afou entopisoume tous paiktes me basi to onoma energopoioume tin sunartisi setCandidate

        if((player+i)->getName() == index1 ){

            (player+i)->setCandidate(true);
            pos1=i;
        }
        if((player+i)->getName() == index2){

           (player+i)->setCandidate(true);
            pos2=i;
        }
    }

    //elegxoume poios ap' tous dio ipopsifious exei mikroteri texniki
    if( (player+pos1)->getTechnique() < (player+pos2)->getTechnique() ){

        //ektipwnoume to onoma tou paikti pou apoxwrei kai ton afairoume ap' ton pinaka twn paiktwn
        cout << "---" << endl;
        cout << "The loser is " << (player+pos1)->getName() << endl;
        team.removePlayer(pos1);
        cout << endl;

    }else if( (player+pos1)->getTechnique() > (player+pos2)->getTechnique() ){

        //ektipwnoume to onoma tou paikti pou apoxwrei kai ton afairoume ap' ton pinaka twn paiktwn
        cout << "---" << endl;
        cout << "The loser is " << (player+pos2)->getName() << endl;
        team.removePlayer(pos2);
        cout << endl;

    }else{

        if( (player+pos1)->getFatigue() > (player+pos2)->getFatigue() ){
            //se periptwsi idias texnikis katartisis lambanoume upopsin tin kourasi
            //o paiktis me tin megaliteri kourasi feugei
            //ektipwnoume to onoma tou paikti pou apoxwrei kai ton afairoume ap' ton pinaka twn paiktwn
            cout << "---" << endl;
            cout << "The loser is " << (player+pos1)->getName() << endl;
            team.removePlayer(pos1);
            cout << endl;

        }else{

            //ektipwnoume to onoma tou paikti pou apoxwrei kai ton afairoume ap' ton pinaka twn paiktwn
            cout << "---" << endl;
            cout << "The loser is " << (player+pos2)->getName() << endl;
            team.removePlayer(pos2);
            cout << endl;

        }
    }

    //afairoume ola ta stoixeia tou ap' to dianusma kai ton xarti
    votes.clear();
    results.clear();
 }
