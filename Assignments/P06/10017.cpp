// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 11/02/2020
// Problem 10017

#include<iostream>
#include <bits/stdc++.h>

using namespace std;

#define A 1
#define B 2
#define C 3

#define MAXDISKS 251
#define MAXPEGS 4

int nDisks, nLastMove, steps;
bool pegs[MAXPEGS][MAXDISKS], stepsReached;


void printStatus()
{
	if (steps > nLastMove)
	{
		stepsReached = true;
		return;
	}

	for (int i = A; i <= C; i++)
	{
		cout << (char) ('A' + i - 1) << "=>";

		bool printSpace = false;
		for (int j = nDisks; j >= 1; j--)
			if (pegs[i][j])
			{
				if (printSpace == false)
				{
					cout << "  ";
					printSpace = true;
				}

				cout << " " << j;
			}

		cout << "\n";
	}

	cout << "\n";

	steps++;
}


void move(int n, int from, int middle, int to)
{
	pegs[from][n] = false;
	pegs[to][n] = true;

	printStatus();
}

void hanoi(int n, int from, int middle, int to)
{
	if (stepsReached)
		return;

	if (n == 1)
	{
		move(n, from, middle, to);
		return;
	}
	else
	{
		hanoi(n - 1, from, to, middle);
		move(n, from, middle, to);
		hanoi(n - 1, middle, from, to);
	}
}

int main(int argc, char const *argv[])
{
	int cases = 1;

	while (cin >> nDisks >> nLastMove, nDisks || nLastMove)
	{
		cout << "Problem #" << cases++ << "\n\n";

		steps = 0;
		stepsReached = false;

		for (int i = 1; i < MAXPEGS; i++)
			for (int j = 1; j <= nDisks; j++)
				pegs[i][j] = false;
		for (int i = 1; i <= nDisks; i++)
			pegs[1][i] = true;

		printStatus();

		hanoi(nDisks, A, B, C);
	}

	return 0;
}