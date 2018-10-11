/*

Antikeimenostrafis Programmatismos
Master Chef 2018

Ntaoulas Xristos-Panagiotis / AEM:8208 / ntaoulac@auth.gr
Sifaki Maria-Ioanna / AEM:8241 / mnsifaki@auth.gr

*/

#include "Team.h"

using namespace std;

Team::Team(string s)
{
    color = s;

    if (s == "Red")
        players = new Player[11] {Player("Marios", male, 30), Player("Tsikilis", male, 34),Player("Nikoleta", female, 23),Player("Chambos", male, 30),Player("Gogo", female, 27),Player("Konstantinos", male, 52),Player("Giorgos", male, 36),Player("Ilektra", female, 28), Player("Glossidis", male, 24),Player("Savvas", male, 28), Player("Tzortzis",male,25)};
    else
        players = new Player[11] {Player("Selim", male, 39), Player("Nikol", female, 22), Player("Timoleon", male, 28), Player("Vasilis", male, 26), Player("Magky", female, 35), Player("Argyris", male, 25), Player("Maia", female, 45),Player("Symeonidis", male, 24), Player("Christina", female, 20),Player("Seferidis", male, 23), Player("Argyroudi", female, 21)};

}

int Team::getNumberOfPlayers()
{
    int result = 0;

    for (int i = 0; i < 11; i++)
        if (players[i].getAge() != 0)
            result++;

    return result;
}

void Team::setCandidate(string player){

    for (int i = 0; i < 10; i++){

        if (player == players[i].getName()){
            players[i].setCandidate(true);
            players[i].status();
            break;
        }

    }

}

void Team::removePlayer(int index)
{
    Player p;
    players[index] = p;
}

void Team::status(bool playerInformation)
{

    cout << "Color: " << color << endl;

    if (playerInformation)
    {
        cout << endl << "Players:" << endl;
        for (int playerIndex = 0; playerIndex < 11; playerIndex++)
            if (players[playerIndex].getAge() != 0)
                players[playerIndex].status();
    }
    cout << endl << endl;
}
