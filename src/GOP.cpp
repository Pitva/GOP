//============================================================================
// Name        : GOP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Player.h"
#include "Effect.h"
#include "Casselli.h"
#include "Card.h"
#include "Dice.h"
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

const int minCasselli = 50;
const int maxCasselli = 200;

void PrintPlayer(PTR_Player playerArray[], int playerCount)
{
	for (int i = 0; i < playerCount; i++)
	{
		playerArray[i]->PrintPlayer();

		cout << endl;
	}
}

void PrintPath(PTR_Casselli casselliArray[], int casselliCount, PTR_Player playerArray[], int playerCount)
{
	for (int i = 0; i < casselliCount; i++)
	{
		casselliArray[i]->PrintCasselli();

		for (int j = 0; j < playerCount; j++)
		{
			if (playerArray[j]->GetPosition() == i)
			{
				cout << playerArray[j]->GetPawn();
			}
		}

		cout << endl;
	}
}

void ClearTerminal()
{
	for (int i = 0; i < 50; i++)
	{
		cout << endl;
	}
}

void GeneratePath(PTR_Casselli casselli[], int casselliCount, PTR_Effect effects[], int length)
{
	casselli[0] = new Casselli(Innocuo, 0, NULL);

	for (int i = 1; i < casselliCount - 1; i++)
	{
		int randomEffect = rand() % length;
		int casselloType = rand() % 9;

		if (casselloType < 5)
		{
			casselli[i] = new Casselli(Innocuo, i, NULL);
		}
		else if (casselloType > 4 && casselloType < 7)
		{
			casselli[i] = new Casselli(Federicolo, i, effects[randomEffect]);
		}
		else if (casselloType > 6)
		{
			casselli[i] = new Casselli(Carta, i, effects[randomEffect]);
		}
	}

	casselli[casselliCount - 1] = new Casselli(Innocuo, casselliCount - 1, NULL);
}

int main()
{
	Dice dice = Dice();

	int playerCount = 0;
	int effectCount = 0;

	srand(time(NULL));
	int casselliCount = minCasselli + rand() % (maxCasselli - minCasselli) + 1;

	bool countFlag = false;

	while (!countFlag)
	{
		string tempInput;

		cout << "Inserire un numero INTERO di giocatori: ";
		cin >> tempInput;

		playerCount = stoi(tempInput);

		if (playerCount < 2)
		{
			countFlag = false;
		}
		else
		{
			countFlag = true;
		}
	}

	PTR_Player players[playerCount];
	for (int i = 1; i <= playerCount; i++)
	{
		string name;
		char pawn;

		cout << "Inserire il nome del giocatore: " << i << ": ";
		cin >> name;

		cout << "Inserire la pedina desiderata: ";
		cin >> pawn;

		players[i - 1] = new Player(name, pawn);
	}

	PTR_Effect effects[effectCount];
	PTR_Casselli casselli[casselliCount];

	GeneratePath(casselli, casselliCount, effects, effectCount - 1);

	cout << endl;
	PrintPath(casselli, casselliCount, players, playerCount);

	int currentPlayer = 0;
	bool isFinished = false;
	while (!isFinished)
	{
		cout << "E' il turno di " << players[currentPlayer]->GetName() << "." << endl;

		string keyPressed = "";
		cin >> keyPressed;

		int diceNumber = dice.Roll();

		cout << "E' uscito il numero " << diceNumber << "." << endl;

		string roundFinished = "";
		cin >> roundFinished;

		players[currentPlayer]->Move(diceNumber);

		//TODO: aggiungere effetti
		if (casselli[players[currentPlayer]->GetPosition()]->GetType() != Innocuo)
		{
			casselli[players[currentPlayer]->GetPosition()]->GetEffect()->PrintEffect();
			casselli[players[currentPlayer]->GetPosition()]->GetEffect();
		}

		cout << endl;
		PrintPath(casselli, casselliCount, players, playerCount);

		if (players[currentPlayer]->GetPosition() > casselliCount - 1)
		{
			players[currentPlayer]->SetPosition(casselliCount - 1);
			cout << players[currentPlayer]->GetName() << " ha vinto la partita.";
			isFinished = true;
		}

		currentPlayer++;

		if (currentPlayer > playerCount - 1)
		{
			currentPlayer = 0;
		}

		ClearTerminal();
	}

	return 0;
}
