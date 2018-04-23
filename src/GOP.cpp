//============================================================================
// Name        : GOP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//TODO: impelemntare cotrollo pLyaerOn in stampa
#include "Player.h"
#include "Effect.h"
#include "Casselli.h"
#include "Dice.h"
#include "Rethrow.h"
#include "RethrowTryhard.h"
#include "StepFoward.h"
#include "StepBack.h"
#include "Stop.h"
#include "Swap.h"
#include "Teleport.h"
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int minCasselli = 10;
const int maxCasselli = 20;

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

void GeneratePath(PTR_Casselli casselli[], int casselliCount, PTR_Effect effects[], int effectCount)
{
	casselli[0] = new Casselli(E_Harmless, 0, NULL);

	for (int i = 1; i < casselliCount - 1; i++)
	{
		int randomEffect = rand() % effectCount;
		int casselloType = rand() % 40;

		if (casselloType < 20)
		{
			casselli[i] = new Casselli(E_Harmless, i, NULL);
		}
		else if (casselloType > 19 && casselloType < 29)
		{
			casselli[i] = new Casselli(E_Effect, i, effects[randomEffect]);
		}
		else if (casselloType > 28 && casselloType < 33)
		{
			casselli[i] = new Casselli(E_Stop, i, effects[3]);
		}
		else if (casselloType > 32 && casselloType < 34)
		{
			casselli[i] = new Casselli(E_Swap, i, new Swap("Scambi la tua posizione con quella di un altro giocatore."));
		}
		else if (casselloType > 33 && casselloType < 36)
		{
			casselli[i] = new Casselli(E_Teleport, i, new Teleport("Vieni teleportato in una casella a caso."));
		}
		else if (casselloType > 35)
		{
			casselli[i] = new Casselli(E_Card, i, NULL);
		}
	}

	casselli[casselliCount - 1] = new Casselli(E_Harmless, casselliCount - 1, NULL);
}

void GenerateEffects(PTR_Effect effects[], int effectCount)
{
	effects[0] = new Rethrow("Ritiri il dado.");
	effects[1] = new StepBack("Salti indietro di un valore casuale di caselle.");
	effects[2] = new StepFoward("Salti avanti di un valore casuale di caselle.");
	effects[3] = new Stop("Stai fermo un turno.");
	effects[4] = new RethrowTryhard("Ritiri il dado a 20 facce ma rimani fermo un turno.");;
}

int main()
{
	Dice dice = Dice();

	int playerCount = 0;
	int effectCount = 5;

	srand(time(NULL));
	int casselliCount = minCasselli + rand() % (maxCasselli - minCasselli) + 1;

	bool countFlag = false;

	while (!countFlag)
	{
		int tempInput;

		cout << "Inserire un numero INTERO di giocatori: ";
		cin >> tempInput;

		if (!cin)
		{
			cout << "Il numero di giocatori deve essere di tipo intero. \n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			countFlag = false;
		}
		else
		{
			if (tempInput >= 2)
			{
				playerCount = tempInput;
				countFlag = true;
			}
			else
			{
				cout << "Il numero di giocatori deve maggiore o uguale a 2. \n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
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

	GenerateEffects(effects, effectCount);
	GeneratePath(casselli, casselliCount, effects, effectCount);

	cout << endl;
	PrintPath(casselli, casselliCount, players, playerCount);

	int currentPlayer = 0;
	bool isFinished = false;
	while (!isFinished)
	{
		cout << "E' il turno di " << players[currentPlayer]->GetName() << "." << endl;

		string keyPressed = "";
		cin >> keyPressed;

		if(!players[currentPlayer]->GetStop())
		{
			int diceNumber = dice.Roll();

			cout << "E' uscito il numero " << diceNumber << "." << endl;

			string roundFinished = "";
			cin >> roundFinished;

			players[currentPlayer]->Move(diceNumber);

			if (players[currentPlayer]->GetPosition() >= casselliCount - 1)
			{
				players[currentPlayer]->SetPosition(casselliCount - 1);
				cout << players[currentPlayer]->GetName() << " ha vinto la partita.";
				isFinished = true;
			}

			else if (casselli[players[currentPlayer]->GetPosition()]->GetType() != E_Harmless && casselli[players[currentPlayer]->GetPosition()]->GetType() != E_Card)
			{
				casselli[players[currentPlayer]->GetPosition()]->GetEffect()->PrintEffect();

				string waitToDeploy = "";
				cin >> waitToDeploy;

				if (casselli[players[currentPlayer]->GetPosition()]->GetType() == E_Swap)
				{
					casselli[players[currentPlayer]->GetPosition()]->GetEffect()->Deploy(players[currentPlayer], players[rand() % playerCount], 0);
				}
				else if (casselli[players[currentPlayer]->GetPosition()]->GetType() == E_Teleport)
				{
					casselli[players[currentPlayer]->GetPosition()]->GetEffect()->Deploy(players[currentPlayer], players[currentPlayer], casselliCount - 1);
				}
				else
				{
					casselli[players[currentPlayer]->GetPosition()]->GetEffect()->Deploy(players[currentPlayer], players[currentPlayer], 0);
				}

				//Step-backwards clamp
				if (players[currentPlayer]->GetPosition() < 0)
				{
					players[currentPlayer]->SetPosition(0);
				}

				//Step-forward clamp
				if (players[currentPlayer]->GetPosition() > casselliCount - 1)
				{
					players[currentPlayer]->SetPosition(casselliCount - 1);
				}
			}
			else if (casselli[players[currentPlayer]->GetPosition()]->GetType() == E_Card)
			{
				cout << "Hai pescato un carta dal mazzo.";
				PTR_Effect tmp = effects[rand() % effectCount];

				tmp->PrintEffect();
				tmp->Deploy(players[currentPlayer], players[currentPlayer], 0);
			}

			cout << endl;
			PrintPath(casselli, casselliCount, players, playerCount);
		}
		else
		{
			cout<< "Ha saltato un turno Doc " << players[currentPlayer]->GetName();
			players[currentPlayer]->SetStop(false);
		}
		currentPlayer++;

		if (currentPlayer > playerCount - 1)
		{
			currentPlayer = 0;
		}
	}

	return 0;
}
