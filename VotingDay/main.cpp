/*

Antikeimenostrafis Programmatismos
Master Chef 2018

Ntaoulas Xristos-Panagiotis / AEM:8208 / ntaoulac@auth.gr
Sifaki Maria-Ioanna / AEM:8241 / mnsifaki@auth.gr

*/

#include "Player.h"
#include "Team.h"
#include "ImmunityCompetition.h"
#include "Voting.h"

using namespace std;

Team teams[2] = { Team("Red"), Team("Blue")};
int competitionId = 1;
void menu();
void votingDay();
void immunityProcess(int teamChoice);
void votingProcess(int teamChoice);

vector<Vote> Voting::votes;
map<string, int> Voting::results;

int main()
{

    srand(time(NULL));
    menu();

    return 0;
}

void menu()
{
    int choice = -1;

    while(choice != 0)
    {
        cout << "1.Voting Day." << endl;
        cout << "0.Quit" << endl;

        cin >> choice;

        switch(choice)
        {

        case 1:
            votingDay();
            break;
        case 0:
            break;
        default:
            cout << "Incorrect Input. Choose between 1  Press 0 to quit." << endl;

        }
    }
}

void votingDay()
{

    cout << "This is voting process in the Master Chef Game." << endl << endl;

    int teamChoice = -1;
    while (teamChoice != 0 && teamChoice != 1)
    {
        cout << "Choose Team for immunity competition: 0.Red or 1.Blue" << endl;
        cin >> teamChoice;
    }

    immunityProcess(teamChoice);

    Voting::votingProcess(teams[teamChoice]);

}

void immunityProcess(int teamChoice)
{

    cout << "This is immunity process in the Survivor Game for " << teams[teamChoice].getColor() << "." << endl << endl;

    ImmunityAward immunityAward("Immunity Award", true);
    ImmunityCompetition immunityCompetition(competitionId++, "Immunity Competition", immunityAward);
    immunityCompetition.compete(teams[teamChoice]);

}

