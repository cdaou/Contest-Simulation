#include "Team.h"
#include "Player.h"

using namespace std;

Team::Team(string s)
{
    color = s;
    wins = 0;
    supplies = 11*14;

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

void Team::status(bool playerInformation)
{

    cout << "Color: " << color << endl;
    cout << "Wins: " << wins << endl;
    cout << "Supplies: " << supplies << endl;

    if (playerInformation)
    {
        cout << endl << "Players:" << endl;
        for (int playerIndex = 0; playerIndex < 11; playerIndex++)
            if (players[playerIndex].getAge() != 0)
                players[playerIndex].status();
    }
    cout << endl << endl;
}

void Team::teamWorks()
{
    cout << " ê -Team " << color << " now works." << endl;
    for (int playerIndex = 0; playerIndex < 11; playerIndex++)
        if (players[playerIndex].getAge() != 0)
            players[playerIndex].work();
}

void Team::teamSocializes()
{
    cout << "  -Team " << color << " now socializes." << endl;
    for (int playerIndex = 0; playerIndex < 11; playerIndex++)
        if (players[playerIndex].getAge() != 0)
            players[playerIndex].socialize();
}

void Team::teamEats()
{
    cout << "  -Team " << color << " now eats." << endl;
    for (int playerIndex = 0; playerIndex < 11; playerIndex++)
        if (players[playerIndex].getAge() != 0)
            supplies--;
}

void Team::teamSleeps()
{
    cout << "  -Team " << color << " now sleeps." << endl;
    for (int playerIndex = 0; playerIndex < 11; playerIndex++)
        players[playerIndex].sleep();


}
