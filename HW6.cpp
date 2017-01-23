/*
 * HW6.cpp
 *
 *  Created on: 2016Äê5ÔÂ25ÈÕ
 *      Author: HUNTE
 */

#include<cmath>
#include<cstdlib>
#include<iostream>
#include<ctime>
int dice_roll();
int det(int t, int& total);
void game(int& balance, int& max, int wager, int& win, int& lose, int& times, int& total);
using namespace std;

int main() {
	//declare wager seed total win lose balance max times
	int wager, seed, total, win, lose, balance, max, times;
	max = 1000;
	balance = 1000;
	win = 0;
	lose = 0;
	total = 0;
	times = 0;
	// user input seed
	cout << "Enter seed" << endl;
	cin >> seed;
	cout << "Seed is " << seed << endl;
	srand(seed);
	//user input wager
	cout << "Enter wager" << endl;
	cin >> wager;
	cout << "Wager is " << wager << endl;
	game(balance, max, wager, win, lose, times, total);
	cout << "You're busted" << endl;
	cout << "You run " << times << " times with initial balance 1000$" << endl;
	cout << "The highest amount money you have is " << max << " dollars"
			<< endl;
	system("pause");

}

//loop function of the game
void game(int& balance, int& max, int wager, int& win, int& lose, int& times, int& total)
{
	for (int i = 0; balance >= 0; i++) {
		if (balance >= max) {
			max = balance;
		}
		int state = det(dice_roll(), total);
		if (state == 0) {
			balance += wager;
			win++;
			times++;
		} else if (state == 1) {
			balance -= wager;
			lose++;
			times++;
		}
	}
}

//roll the dice and return the total points
int dice_roll() {
	int a = rand() % 6 + 1;
	int b = rand() % 6 + 1;
	int total = a + b;
	cout << "Dice one is " << a << " point" << endl;
	cout << "Dice two is " << b << " point" << endl;
	cout << "Total " << total << " point" << endl;
	return total;
}

//determine whats next, return 0 if player win, 1 for lose, 2 for keep rolling
int det(int t, int& total) {
	if (total == 0) {
		if (t == 7 || t == 11) {
			return 0;
		} else if (t == 2 || t == 3 || t == 12) {
			return 1;
		} else {
			total = t;
			return 2;
		}
	} else {
		if (t == 7) {
			total = 0;
			return 1;
		} else if (t == total) {
			total = 0;
			return 0;
		} else {
			return 2;
		}
	}
}
