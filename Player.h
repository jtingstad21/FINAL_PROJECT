#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <time.h>
#include <cstdlib>
using namespace std;


class Player
{
private:
	int pNum = 0;
	double score = NULL;
	string name;
	vector <string> wordList;
	vector <Player> playerList;

public:
	Player();
	Player(string n);
	int getScore();
	int getPNum();
	string getName();
	void setScore(double s);

	Player newPlayer(string n);
	string getWord();
	static void fillList(vector<string>& v);
	static void findWinner(vector<Player> p);
	static void scrambleWord(string& s);
	static void userTurn(Player p, vector<string> v);
};