/*
 * Challenge1.cpp
 *
 *  Created on: 2016Äê6ÔÂ1ÈÕ
 *      Author: HUNTE
 */

#include <iostream>
#include <ctime>
#include<cmath>
#include<cstdlib>
using namespace std;

int main() {
	srand(time(0));
	int i;
	int r1 = rand() % 21;
	int r2 = rand() % 21;
	cout << "Two integer is " << r1 <<
	" and " << r2 << endl;
	cin >> i;
	if (i == r1 + r2) {
		cout << "Gratz" << endl;
	} else {
		cout << "The answer is wrong!"<<endl;
	}

}
