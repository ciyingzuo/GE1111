/*
 * Quiz5.cpp
 *
 *  Created on: 6/7/2016
 *      Author: Yingzuo Ci
 */

#include<fstream>
#include<iostream>
#include<cmath>

using namespace std;

int main() {

	//set out file
	ofstream of;
	of.open("fibonums.txt");

	//create array and initial first two value
	float a[15];
	a[0] = 0.0;
	a[1] = 1.0;

	//initialize the rest of array
	for (int i = 2; i < 15; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}

	//write the file
	for (int n = 0; n < 15; n++) {
		of << a[n] << endl;
	}

	of.close();
	//set the input file
	ifstream ifile;
	ifile.open("fibonums.txt");

	//define two variables
	float x, k;
	int c = 0;

	//input the value
	cout << "Enter the value you are looking for" << endl;
	cin >> x;

	//show the result of search
	while (ifile >> k) {
		c++;
		if (k == x) {
			cout << "This value is in the file" << endl;
			break;
		} else if (c == 15) {
			cout << "This value is not in the file" << endl;
		}
	}
	ifile.close();
}

