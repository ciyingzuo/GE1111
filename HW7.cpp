/*
 * HW7.cpp
 *
 *  Created on: 5/31/2016
 *      Author: Jiankun Zhang, Yingzuo Ci
 */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool t(double t, int& rejected_t);
bool p(double p, int& rejected_p);
bool d(double d, int& rejected_d);

int main() {
	// declare and initial variables
	int number, rejected_t, rejected_p, rejected_d, total_rejected, total_batches;
	total_batches = 0;
	rejected_t = 0;
	rejected_p = 0;
	rejected_d = 0;
	total_rejected = 0;
	double temperature, pressure, dwell_time;

	ifstream infile; /* sets up for input file */
	ofstream outfile; /* sets up for output file */
	infile.open("SUTURES.txt");
	outfile.open("SUTURES_RESULT.txt");
	outfile << "Jiankun Zhang & Yingzuo Ci" << endl;
	outfile << "Acceptable batches:" << endl;

	// loop analyze the data
	while (infile >> number >> temperature >> pressure >> dwell_time) {
		total_batches++;
		if (p(pressure, rejected_p) && d(dwell_time, rejected_d)
				&& t(temperature, rejected_t)) {
			outfile << number << endl;
		} else {
			total_rejected++;
		}
	}

	// output the result
	outfile << rejected_t << " batches were reject because Temperature, is "
			<< (double) rejected_t / (double) total_batches * 100 << "%" << endl;
	outfile << rejected_p << " batches were reject because Pressure, is "
			<< (double) rejected_p / (double) total_batches * 100 << "%" << endl;
	outfile << rejected_d << " batches were reject because Dwell time, is "
			<< (double) rejected_d / (double) total_batches * 100 << "%" << endl;
	outfile << "Total " << total_rejected << " batches were rejected, is "
			<< (double) total_rejected / (double) total_batches * 100 << "%" << endl;
}

// return true if the batche's temperature is acceptable
bool t(double t, int& rejected_t) {
	if (t <= 170 && t >= 150) {
		return true;
	} else {
		rejected_t++;
		return false;
	}
}

// return true if the batche's pressure is acceptable
bool p(double p, int& rejected_p) {
	if (p <= 70 && p >= 60) {
		return true;
	} else {
		rejected_p++;
		return false;
	}
}

// return true if the batche's dwell time is acceptable
bool d(double d, int& rejected_d) {
	if (d >= 2 && d <= 2.25) {
		return true;
	} else {
		rejected_d++;
		return false;
	}
}
