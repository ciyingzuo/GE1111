/*
 * ProjectHelp.cpp
 *
 *  Created on: 2016Äê6ÔÂ22ÈÕ
 *      Author: HUNTE
 */
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

ofstream of;
ifstream inf;

int main() {
	int time;
	double speed;
	char state;
	inf.open("wind speed storm with burst.txt");
	of.open("wind speed storm with burst1.txt");
	while(inf>>time>>speed>>state){
		of<<speed<<endl;
	}
	inf.close();
	of.close();
}
