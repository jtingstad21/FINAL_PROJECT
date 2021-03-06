// source_code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Game.h"
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

vector<Player> pList;
static vector<string> wList;

int main()
{
	cout << "How many players would you like to enter?" << endl;
	int players;
	cin >> players;

	string playerName;
	for (int i = 0; i < players; i++)
	{
		cout << "Enter name for player " << i + 1 << endl;
		cin >> playerName;
		Player p(playerName);
		pList.push_back(p);
	}
	Player::fillList(wList);
	srand(time(0));

	for (int i = 0; i < players; i++)
	{
		cout << "Type 'Y' when ready: " << endl;
		char ready;
		cin >> ready;
		if (ready == 'Y' | ready == 'y')
		{
			Player::userTurn(pList.at(i), wList);
		}
	}

	Player::findWinner(pList);


    return 0;
}

