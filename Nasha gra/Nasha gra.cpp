// Nasha gra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

void Past(char a[3][3])
{
	for (int i(1); i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			a[i][j] = (j + 48 + (i - 1) * 3);
		}
	}
}

void Output(char a[3][3])
{
	for (int i(1); i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			cout << "|" << a[i][j] << "|";
		}
		cout << endl;
	}
}

void Begin(char pl[20])
{
	cout << pl << " input your NAME: ";
	cin >> pl;
}

void Perevirka1(char P[3][3], char Player1[20], bool isWin)
{
	for (int i = 1; i <= 3; ++i)
	{
		if ((P[i][1] == 'X') && (P[i][2] == 'X') && (P[i][3] == 'X'))
		{
			isWin = true;
			system("cls");
			Output(P);
			cout << endl << Player1 << ", you WIN\n\n";
			system("pause");
			Past(P);
		}
		if ((P[1][i] == 'X') && (P[2][i] == 'X') && (P[3][i] == 'X'))
		{
			isWin = true;
			system("cls");
			Output(P);
			cout << endl << Player1 << ", you WIN\n\n";
			system("pause");
			Past(P);
		}
	}
	if ((P[1][1] == 'X') && (P[2][2] == 'X') && (P[3][3] == 'X'))
	{
		isWin = true;
		system("cls");
		Output(P);
		cout << endl << Player1 << ", you WIN\n\n";
		system("pause");
		Past(P);
	}
	if ((P[1][3] == 'X') && (P[2][2] == 'X') && (P[3][1] == 'X'))
	{
		isWin = true;
		system("cls");
		Output(P);
		cout << endl << Player1 << ", you WIN\n\n";
		system("pause");
		Past(P);
	}
}

void Perevirka2(char P[3][3], char Player2[20], bool isWin)
{
	for (int i = 1; i <= 3; ++i)
	{
		if ((P[i][1] == 'O') && (P[i][2] == 'O') && (P[i][3] == 'O'))
		{
			isWin = true;
			system("cls");
			Output(P);
			cout << endl << Player2 << ", you WIN\n\n";
			system("pause");
			Past(P);
		}
		if ((P[1][i] == 'O') && (P[2][i] == 'O') && (P[3][i] == 'O'))
		{
			isWin = true;
			system("cls");
			Output(P);
			cout << endl << Player2 << ", you WIN\n\n";
			system("pause");
			Past(P);
		}
	}
	if ((P[1][1] == 'O') && (P[2][2] == 'O') && (P[3][3] == 'O'))
	{
		isWin = true;
		system("cls");
		Output(P); 
		cout << endl << Player2 << ", you WIN\n\n";
		system("pause");
		Past(P);
	}
	if ((P[1][3] == 'O') && (P[2][2] == 'O') && (P[3][1] == 'O'))
	{
		isWin = true;
		system("cls");
		Output(P);
		cout << endl << Player2 << ", you WIN\n\n";
		system("pause");
		Past(P);
	}
}

void PerevirkaN(char P[3][3], int count, bool isN)
{
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			if (P[i][j] == 'X' || P[i][j] == 'O')
			{
				count++;
			}
		}
	}
	if (count == 9)
	{
		isN = true;
		system("cls");
		Output(P);
		cout << "\nIt is NICHYA\n";
		system("pause");
		Past(P);
	}
	count = 0;
}


int main()
{
	cout << "***Krestiki noliki***\n" << endl;
	cout << "Enter your number:\n '1' - if you want to play: Player1 vs Player2\n";
	cout << " '2' - if you want to play: Player1 vs CPU   ";
	int temp;
	do
	{
		cin >> temp;
		if (temp == 1)
		{
			system("cls");
			cout << "***Krestiki noliki***\n Player1 vs Player2\n" << endl;
			char Player1[20] = "Player1";
			char Player2[20] = "Player2";
			Begin(Player1);
			Begin(Player2);

			char P[3][3];
			Past(P);
			Output(P);

			int count = 0;
			int pl1 = 0, pl2 = 0;
			bool isWin = false;
			bool isN = false;
			int g = 0;
			for (int r = 1;; ++r)
			{
				do
				{
					system("cls");
					if (r >= 2)
						cout << Player2 << " choosed number " << pl2 << endl;
					cout << Player1 << ", you are 'X', your choice (enter your number(1-9): \n\n";
					Output(P);
					cout << endl;
					cin >> pl1;

					for (int i(1); i <= 3; ++i)
					{
						for (int j = 1; j <= 3; ++j)
						{
							if (pl1 == (j + (i - 1) * 3))
							{
								if (P[i][j] != 'X' && P[i][j] != 'O')
								{
									P[i][j] = 'X';
									g = 1;
								}
							}
						}
					}
				} while (pl1 > 9 || pl1 < 1 || g == 0);
			g = 0;
				Output(P);

				Perevirka1(P, Player1, isWin);
				PerevirkaN(P, count, isN);
				if (isWin || isN)
					break;

				do
				{
					system("cls");
					cout << Player1 << " choose number " << pl1 << endl;
					cout << Player2 << ", you are 'O', your choice (enter your number(1-9): \n\n";
					Output(P);
					cout << endl;
					cin >> pl2;

					for (int i(1); i <= 3; ++i)
					{
						for (int j = 1; j <= 3; ++j)
						{
							if (pl2 == (j + (i - 1) * 3))
							{
								if (P[i][j] != 'X' && P[i][j] != 'O')
								{
									P[i][j] = 'O';
									g = 1;
								}
							}
						}
					}
				} while (pl2 > 9 || pl2 < 1 || g == 0);
				g = 0;
				Output(P);

				Perevirka2(P, Player2, isWin);
				PerevirkaN(P, count, isN);
				if (isWin || isN)
					break;
			}
		}

		else if (temp == 2)
		{
			system("cls");
			cout << "***Krestiki noliki***\n Player1 vs CPU\n" << endl;
			char Player1[20] = "Player1";
			char Player2[20] = "CPU";
			Begin(Player1);

			char P[3][3];
			Past(P);
			Output(P);

			int count = 0;
			int pl1 = 0, pl2 = 0;
			bool isWin = false;
			bool isN = false;
			int g = 0;
			for (int r = 1;; ++r)
			{
				do
				{
					system("cls");
					if (r >= 2)
						cout << Player2 << " choosed number " << pl2 << endl;
					cout << Player1 << ", you are 'X', your choice (enter your number(1-9): \n\n";
					Output(P);
					cout << endl;
					cin >> pl1;

					for (int i(1); i <= 3; ++i)
					{
						for (int j = 1; j <= 3; ++j)
						{
							if (pl1 == (j + (i - 1) * 3))
							{
								if (P[i][j] != 'X' && P[i][j] != 'O')
								{
									P[i][j] = 'X';
									g = 1;
								}
							}
						}
					}
				} while (pl1 > 9 || pl1 < 1 || g == 0);
				g = 0;
				Output(P);

				Perevirka1(P, Player1, isWin);
				PerevirkaN(P, count, isN);
				if (isWin || isN)
					break;

				do
				{
					system("cls");
					srand(time(0));
					pl2 = rand() % 10;

					for (int i(1); i <= 3; ++i)
					{
						for (int j = 1; j <= 3; ++j)
						{
							if (pl2 == (j + (i - 1) * 3))
							{
								if (P[i][j] != 'X' && P[i][j] != 'O')
								{
									P[i][j] = 'O';
									g = 1;
								}
							}
						}
					}
				} while (pl2 > 9 || pl2 < 1 || g == 0);
				g = 0;
				
				Output(P);

				Perevirka2(P, Player2, isWin);
				PerevirkaN(P, count, isN);
				if (isWin || isN)
					break;
			}
		}

		else
			cout << "Incorrect number, input another one correct: ";
	}
	while (temp != 1 || temp != 2);
	system("pause");
	return 0;
} 