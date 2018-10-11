#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

enum genderOption {male, female};

class Player{

    string name;
    genderOption gender;
    int age;
    string job;
	int wins;
    float technique;
    float fatigue;
    float popularity;
    bool candidate;

public:
    Player();
    Player(string n, genderOption g, int a);
    ~Player();

    string getName();
    genderOption getGender();
    int getAge();
    string getJob();
	int getWins();
    float getTechnique();
    float getFatigue();
    float getPopularity();
    bool getCandidate();

    void setName(string val);
    void setGender(genderOption val);
    void setJob(string val);
    void setAge(int val);
	void setWins(int val);
    void setTechnique(float val);
    void setFatigue(float val);
    void setPopularity(float val);
    void setCandidate(bool val);

    void work();
    void sleep();
    void socialize();
    void practice();
    void compete();

    void status();
};


#endif // PLAYER_H_INCLUDED
