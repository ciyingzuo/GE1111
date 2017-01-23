/* 	Programmer: JianKun Zhang, Yingzuo Ci
 Filename: HW3.cpp
 Objective: Problem P3.30 from CFE Textbook
 Input: Mass m.
 Output: Velocity v..
 Equation: Given in textbook
 Function: main(), v(double m).
 Date: 5/17/2016
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	// declare variables mass
	double mass;
	cout << "Please enter the mass" << endl;
	// inputs mass
	cin >> mass;
	// declare function v
	int v(double m);
	// return the result of the greatest speed,
	// if no speed matches, return the reason
	if (mass <= 0) {
		cout << "Mass can not smaller or equal to 0!" << endl;
	} else {
		if (v(mass) == -1) {
			cout << "Too heavy!" << endl;
		} else {
			cout << "The greatest velocity is " << v(mass) << endl;
		}
	}

}

// return the value of speed, if none of speed matches, return -1
int v(double m) {
	// define the length and speed.
	int r = 3;
	int v1 = 1;
	int v2 = 10;
	int v3 = 20;
	int v4 = 40;

	//calculate and compare the speed
	if (((m * v4 * v4) / r) <= 60) {
		return v4;
	} else if (((m * v3 * v3) / r) <= 60) {
		return v3;
	} else if (((m * v2 * v2) / r) <= 60) {
		return v2;
	} else if (((m * v1 * v1) / r) <= 60) {
		return v1;
	} else {
		return -1;
	}

}
