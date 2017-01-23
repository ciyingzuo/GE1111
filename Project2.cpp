/*
 * Prject2.cpp
 *
 *  Created on: 2016Äê6ÔÂ21ÈÕ
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
	// Declare functions
	void wsg(int maximum, int minimum);
	void storm();
	void burst();
	void removeTag();

	// Declare variables
	int max, min;
	string s, b;

	// User input
	cout << "Enter max and minimum wind speed" << endl;
	cin >> max >> min;
	wsg(max, min);
	cout << "Enable storm?" << endl;
	cin >> s;

	// Microbursts will enable only if user enable storm and microbursts
	if (s == "yes") {
		storm();
		cout << "Enable burst?" << endl;
		cin >> b;
		if (b == "yes") {
			burst();
		}
	}
	removeTag();
}

// Generate wind speed file
// Include time, wind speed, and weather tag in each line
// " N" for normal
void wsg(int maximum, int minimum) {
	void removeTag(string fileName);
	srand(time(0));
	of.open("Wind speed.txt");
	for (int i = 0; i <= 3600; i = i + 10) {
		double speed = minimum
				+ (rand() % (maximum * 100 - minimum * 100 + 1) / 100.0);
		of << i << " " << speed << " N" << endl;
	}
	of.close();
}

// modify the data to have storm
// " S" for storm
void storm() {
	srand(time(0));
	int s = 1000;
	int time;
	double speed;
	char state;
	inf.open("Wind speed.txt");
	of.open("Wind speed storm.txt");
	int count = 0;

	// Read the file and create a new file
	while (inf >> time >> speed >> state) {
		s = rand() % 1000;
		if (s < 5) {
			count = 30;
		}
		if (count > 0) {
			of << time << " " << speed + 10.0 << " S" << endl;
			count--;
		} else {
			of << time << " " << speed << " " << state << endl;
		}
	}
	inf.close();
	of.close();
}

// Modify the data to have microbursts
// " B" for microburst
void burst() {
	srand(time(0));
	int b = 100;
	int time;
	double speed;
	double max = 0;
	double min = 1000;
	char state;
	inf.open("Wind speed storm.txt");
	of.open("Wind speed storm with burst.txt");
	int count = 0;

	// Read the file and create a new file
	while (inf >> time >> speed >> state) {
		b = rand() % 100;
		if ((b < 1) && (state == 'S')) {
			count = 6;
		}
		if ((count > 0) && (state == 'S')) {
			of << time << " " << speed + 50.0 << " B" << endl;
			count--;
		} else if (count > 0) {
			of << time << " " << speed << " " << state << endl;
			count--;
		} else {
			of << time << " " << speed << " " << state << endl;
		}
	}
	inf.close();
	of.close();
}

// Remove tag and time from the data
void removeTag() {
	int time;
	double speed;
	char state;
	inf.open("Wind speed.txt");
	of.open("Wind speed No tag.txt");
	while (inf >> time >> speed >> state) {
		of << speed << endl;
	}
	inf.close();
	of.close();
	inf.open("Wind speed storm.txt");
	of.open("Wind speed storm No tag.txt");
	while (inf >> time >> speed >> state) {
		of << speed << endl;
	}
	inf.close();
	of.close();
	inf.open("Wind speed storm with burst.txt");
	of.open("Wind speed storm with burst No tag.txt");
	while (inf >> time >> speed >> state) {
		of << speed << endl;
	}
	inf.close();
	of.close();
}
