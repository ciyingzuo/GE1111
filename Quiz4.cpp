/*
 * Quiz4.cpp
 *
 *  Created on: 6/2/2016
 *      Author: Yingzuo Ci
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string numSigns(double n1, double n2);
void sortvals(double& num1, double& num2);
void showresult(double n1, string s);

int main() {
	//declare variables
	double num_1, num_2;
	cout << "Enter two non-zero values." << endl;
	cin >> num_1 >> num_2;
	//keep ask input value if user inputs 0
	while (num_1 == 0 || num_2 == 0) {
		cout << "Enter two non-zero values." << endl;
		cin >> num_1 >> num_2;
	}

	sortvals(num_1, num_2);
	showresult(num_1, numSigns(num_1, num_2));
}

// let num_1 hold larger value
void sortvals(double& num1, double& num2) {
	if (num1 > num2) {

	} else {
		int n = num1;
		num1 = num2;
		num2 = n;
	}
}

// determine if they are smae sign or opposite
string numSigns(double n1, double n2) {
	if ((n1 > 0 && n2 > 0) || (n1 < 0 && n2 < 0)) {
		return "the same sign";
	} else {
		return "opposite signs";
	}
}

//output information
void showresult(double n1, string s) {
	cout << "The large value is " << n1 << ", they are " << s;
}
