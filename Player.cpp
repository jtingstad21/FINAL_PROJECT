#include "Player.h"

Player::Player()
{
	name = "Ed";
}

Player::Player(string n)
{
	name = n;
}

int Player::getScore()
{
	return score;
}

int Player::getPNum()
{
	return pNum;
}

string Player::getName()
{
	return name;
}
void Player::setScore(double s)
{
	if (s > 0)
		score = s;
}

Player Player::newPlayer(string n)
{
	pNum++;
	Player p1(n);
	cout << "Welcome, " << p1.getName() << endl;
	playerList.push_back(p1);
	return p1;
}

string Player::getWord()
{
	//get random word
	srand(time(0));
	int index = rand() % (3000);
	string w = wordList.at(index);
	
	return w;
}

void Player::fillList(vector<string>& v)
{
	ifstream list;
	string word;

	list.open("words.txt");
	if (list.fail())
	{
		cout << "Can't open file" << endl;
	}

	while (list >> word)
	{
		v.push_back(word);
	}
}

void Player::findWinner(vector<Player> p)
{
	double temp = 99999999999999;
	string n;
	double newScore;

	for (int i = 0; i < p.size(); i++)
	{
		if (temp > p.at(i).getScore())
		{
			newScore = p.at(i).getScore();
			n = p.at(i).getName();
		}
	}

	cout << "The winner is: " << n << "!" << endl;
}

void Player::scrambleWord(string & s)
{
	int x = s.length();
	for (int y = x; y > 0; y--)
	{
		int pos = rand() % x;
		char temp = s[y - 1];
		s[y - 1] = s[pos];
		s[pos] = temp;
	}
}

void Player::userTurn(Player p, vector<string> v)
{
	int numCorrect = 0;
	srand(time(0));
	string userGuess;
	time_t start, end;
	time(&start);

	for (int i = 0; i < 10; i++)
	{
		int random = (rand() % v.size());
		string Word, wordScramble;
		Word = v.at(random);
		string oWord = Word;
		scrambleWord(Word);
		cout << Word << endl;
		cin >> userGuess;
		while (numCorrect < 10)
		{
			if (userGuess == oWord)
			{
				numCorrect++;
			}
			else
			{
				cout << "Incorrect, guess again: " << endl;
				cin >> userGuess;
			}
		}
	}
	time(&end);
	double diff = difftime(end, start);
	p.setScore(diff);
}