/*

Antikeimenostrafis Programmatismos
Master Chef 2018

Ntaoulas Xristos-Panagiotis / AEM:8208 / ntaoulac@auth.gr
Sifaki Maria-Ioanna / AEM:8241 / mnsifaki@auth.gr

*/

#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player()
{
    name = "";
    gender = female;
    age = 0;
    job = "";
    wins = 0;
    votes = 0;
    technique = 0;
    fatigue = 0;
    popularity = 0;
    candidate = false;
    immunity = false;
}


Player::Player(string n, genderOption g, int a)
{
    setName(n);
    setGender(g);
    setAge(a);
    setJob("Cook");
    setWins(0);
    setVotes(1);
    setTechnique(20 + (rand() % 60));
    setFatigue(rand() % 100);
    setPopularity(rand() % 100);
    setCandidate(false);
    setImmunity(false);
}

Player::~Player()
{
    cout << "Player " << name << " is destroyed." << endl;
}

string Player::getName()
{
    return name;
}

genderOption Player::getGender()
{
    return gender;
}

int Player::getAge()
{
    return age;
}

string Player::getJob()
{
    return job;
}

int Player::getWins()
{
    return wins;
}

int Player::getVotes()
{
    return votes;
}

float Player::getTechnique()
{
    return technique;
}

float Player::getFatigue()
{
    return fatigue;
}

float Player::getPopularity()
{
    return popularity;
}

bool Player::getCandidate()
{
    return candidate;
}

bool Player::getImmunity()
{
    return immunity;
}

void Player::setName(string val)
{
    name = val;
}

void Player::setGender(genderOption val)
{
    gender = val;
}

void Player::setAge(int val)
{
    if (val >= 18)
        age = val;
    else
        cout << "Age must be an integer >= 18." << endl;
}

void Player::setWins(int val)
{
    if (val >= 0)
        wins = val;
    else
        cout << "Wins must be a zero or positive number." << endl;
}

void Player::setVotes(int val)
{
    if (val >= 0)
        votes = val;
    else
        cout << "Votes must be a zero or positive number." << endl;
}

void Player::setJob(string val)
{
    job = val;
}

void Player::setTechnique(float val)
{
    if (val >= 0 && val <= 100)
        technique = val;
    else
        cout << "Technique is a percentage, thus it takes values [0, 100]." << endl;
}

void Player::setFatigue(float val)
{
    if (val >= 0 && val <= 100)
        fatigue = val;
    else
        cout << "Fatigue is a percentage, thus it takes values [0, 100]." << endl;
}

void Player::setPopularity(float val)
{
    if (val >= 0 && val <= 100)
        popularity = val;
    else
        cout << "Popularity is a percentage, thus it takes values [0, 100]." << endl;
}

void Player::setCandidate(bool val)
{
    candidate = val;
}

void Player::setImmunity(bool val)
{
    immunity = val;
}

void Player::work()
{
    float value = 20 + (((float) rand()) / (float) RAND_MAX)*20;
    fatigue += value;
    technique *= 1.05;
    if (fatigue > 100)
        fatigue = 100;
    if (technique > 100)
        technique = 100;
}

void Player::socialize()
{
    float value = -10 + (((float) rand()) / (float) RAND_MAX)*20;
    popularity += value;
    if (popularity < 0)
        popularity = 0;
    else if (popularity > 100)
        popularity = 100;
}

void Player::practice()
{
    technique += 5;

    if (technique > 100)
        technique = 100;
}

void Player::sleep()
{
    fatigue *= 0.5;
}

void Player::compete()
{
    float value = 10 + (((float) rand()) / (float) RAND_MAX)*10;
    fatigue += value;

    if (fatigue > 100)
        fatigue = 100;
}

void Player::status()
{
    cout << "Name: " << name << endl;
    cout << "Gender: ";
    if (gender == male)
        cout << "Male";
    else
        cout << "Female";
    cout << endl;
    cout << "Age: " << age << endl;
    cout << "Job: " << job << endl;
    cout << "Wins: " << wins << endl;
    cout << "Votes: " << votes << endl;
    cout << "Technique: " << technique << endl;
    cout << "Fatigue: " << fatigue << endl;
    cout << "Popularity: " << popularity << endl;
    cout << "Candidate: ";
    if (candidate == 0)
        cout << "false\n" ;
    else
        cout << "true\n";

    cout << "Immunity: ";
    if (immunity == 0)
        cout << "false";
    else
        cout << "true";
    cout << endl << endl;
}
