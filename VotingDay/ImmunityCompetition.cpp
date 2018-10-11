/*

Antikeimenostrafis Programmatismos
Master Chef 2018

Ntaoulas Xristos-Panagiotis / AEM:8208 / ntaoulac@auth.gr
Sifaki Maria-Ioanna / AEM:8241 / mnsifaki@auth.gr

*/

#include "ImmunityCompetition.h"

using namespace std;

void ImmunityCompetition::compete(Team &team)
{

    int maxIndex = -1;
    float maxValue = -1;

    for(int i = 0; i < 11; i++)
    {
        Player player = team.getPlayers()[i];

        if (player.getAge() != 0)
        {
            player.setVotes(1);
            float value = 0.75 * player.getTechnique() + 0.25 * (100-player.getFatigue());
            cout << "Player: " + player.getName();
            cout << " Technique: " << player.getTechnique();
            cout << " Fatigue: " << player.getFatigue();
            cout << " Value: "  << value << endl;

            if (maxValue < value)
            {
                maxValue = value;
                maxIndex = i;
            }
        }
    }

    winner = team.getPlayers()[maxIndex].getName();

    team.getPlayers()[maxIndex].setWins(team.getPlayers()[maxIndex].getWins() + 1);
    team.getPlayers()[maxIndex].setImmunity(true);
    team.getPlayers()[maxIndex].setVotes(team.getPlayers()[maxIndex].getVotes() + immunityAward.getVotes());
    team.getPlayers()[maxIndex].status();

    cout << "Immunity Competition Finished." << endl;

    status();
}
