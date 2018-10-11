#include "Team.h"
#include "TeamCompetition.h"
#include "ImmunityCompetition.h"
#include "CreativityCompetition.h"
#include "FoodAward.h"
#include "ImmunityAward.h"
#include "ExcursionAward.h"

using namespace std;

// Index 0 = Red Team, Index 1 = Blue Team
Team teams[2] = { Team("Red"), Team("Blue")};
int competitionId = 1;
int loserTeam = -1;
string CreativityCompetition::ingredients[10]={"makaronia", "garides", "kokkini saltsa", "alati", "ouzo", "kremmidi", "ladi", "kubo laxanikwn Maggie", "piperi", "basiliko"};

void menu();
void normalDay();
void teamCompetitionDay();
void immunityCompetitionDay();
void creativityCompetitionDay();

int main()
{
    menu();

    return 0;
}

void menu()
{
    int choice = -1;

    while(choice != 0)
    {
        cout << endl << "1.Normal Day." << endl;
        cout << "2.Team Competition Day." << endl;
        cout << "3.Immunity Competition Day." << endl;
        cout << "4.Creativity Competition Day." << endl;
        cout << "0.Quit" << endl;

        cin >> choice;

        switch(choice)
        {

        case 1:
            normalDay();
            break;
        case 2:
            teamCompetitionDay();
            break;
        case 3:
            immunityCompetitionDay();
            break;
        case 4:
            creativityCompetitionDay();
            break;
        case 0:
            break;
        default:
            cout << "Incorrect Input. Choose between 1 and 3. Press 0 to quit." << endl;

        }
    }
}

void normalDay()
{

    cout << endl << "--" << endl;
    cout << "This is a normal day in the Master Chef Game." ;
    cout << endl << "--" << endl;

    for(int i=0;i<2;i++){
        cout << endl;
        teams[i].teamEats();
        teams[i].teamWorks();
        teams[i].teamEats();
        teams[i].teamSleeps();
        teams[i].teamSocializes();
    }
}

void teamCompetitionDay()
{

    cout << endl << "--" << endl;
    cout << "This is a Team Competition day in the Master Chef Game.";
    cout << endl << "--" << endl;

    cout << endl << "The day starts with the players eating breakfast and doing houseworks: " << endl;
    for(int i=0;i<2;i++){
        cout << endl;
        teams[i].teamEats();
        teams[i].teamWorks();
    }

    FoodAward foodAward=FoodAward("Food Award", false);

    TeamCompetition teamComp=TeamCompetition(competitionId++, "Team Competition", foodAward);

    loserTeam = teamComp.compete(teams[0], teams[1]);

    cout << endl << "--" << endl;
    teamComp.status();
    cout <<  "--" << endl;

    cout << endl <<"The day ends with the players of the two groups eating and sleeping as a group, while their popularity is affected during the day." << endl;
    for(int i=0;i<2;i++){
        cout << endl;
        teams[i].teamEats();
        teams[i].teamSocializes();
        teams[i].teamSleeps();
    }
}

void immunityCompetitionDay()
{

    cout << endl << "--" << endl;
    cout << "This is a Immunity Competition day in the Master Chef Game." ;
    cout << endl << "--" << endl;

    if(loserTeam == -1){
        cout << "Team Competition must be done first. Please, try again!" << endl;
        return;
    }

    cout << endl << "The day starts with the players eating breakfast and doing houseworks: " << endl;
    for(int i=0;i<2;i++){
        cout << endl;
        teams[i].teamEats();
        teams[i].teamWorks();
    }

    ImmunityAward immunityAward=ImmunityAward("Immunity Award", true);

    ImmunityCompetition immunityComp = ImmunityCompetition(competitionId++, "Immunity Competition", immunityAward);

    immunityComp.compete(teams[loserTeam]);

    cout << endl << "--" << endl;
    immunityComp.status();
    cout << "--" << endl;

    cout << endl << "The day ends with the players of the two groups eating and sleeping as a group, while their popularity is affected during the day." << endl;
    for(int i=0;i<2;i++){
        cout << endl;
        teams[i].teamEats();
        teams[i].teamSocializes();
        teams[i].teamSleeps();
    }
}

void creativityCompetitionDay()
{
    cout << endl << "--" << endl;
    cout << "This is a Creativity Competition day in the Master Chef Game.";
    cout << endl << "--" << endl;

    cout << endl << "The day starts with the players eating breakfast and doing houseworks: " << endl;
    for(int i=0;i<2;i++){
        cout << endl;
        teams[i].teamEats();
        teams[i].teamWorks();
    }


    ExcursionAward excursionAward = ExcursionAward("Excursion Award", true);

    CreativityCompetition creativityComp = CreativityCompetition(competitionId++, "Creativity Competition", excursionAward);

    creativityComp.compete(teams[0], teams[1]);

    cout << endl << "--";
    creativityComp.status();
    cout << endl << "--" << endl;

    cout << endl << "The day ends with the players of the two groups eating and sleeping as a group, while their popularity is affected during the day." << endl;
    for(int i=0;i<2;i++){
        cout << endl;
        teams[i].teamEats();
        teams[i].teamSocializes();
        teams[i].teamSleeps();
    }
}
