/* 	Programmer: JianKun Zhang, Yingzuo Ci
 Filename: HW4.cpp
 Objective: Problem P4.25 from CFE Textbook
 Output: String.
 Equation: Given in textbook
 Function: main()
 Date: 5/18/2016
 */

#include <cmath>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// returns two integer, first integer for x, second integer for y
int main() {
	srand(time(0));
	//define x, y and t
	int x = 0, y = 0, t;
	cout << "Enter times" << endl;
	// user inputs t
	cin >> t;
	// check if the input is valid
	if (cin.fail()) {
		cout << "Please enter a integer greater than 0" << endl;
		return 0;
	}

	// this loop randomly choose x or y to increase or decrease by one,
	for (int i = 0; i < t; i++) {
		int n = rand() % 100;
		if (n < 25) {
			x++;
		} else if (n < 50) {
			x--;
		} else if (n < 75) {
			y++;
		} else {
			y--;
		}
	}
	cout <<"The position after "<<t<<" times is (" << x << ", " << y << ").";
	return 0;
}
