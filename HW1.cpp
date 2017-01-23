/* 	Programmer: JianKun Zhang, Yingzuo Ci
	Filename: HW1.cpp
	Objective: Problem P2.26 from CFE Textbook
			   Calculate the liquid temperature for pipe clip
	Input: Thermistor resistance R
	Output: Liquid temperature T
	Equation: Given in textbook
	Function: main()
	Date: 5/12/2016
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// declaring variables and initializing Ri, Ti, b with the given value.
	// calculating T
	// User inputs R
	double Ri = 1075, Ti = 85, b = 3969, R;
	cout<<"please enter Resistance"<<endl;
	cin>>R;

	double e = 2.71828;
	// Calculating T
	double T = ((b * Ti) / ((Ti * (log(R / Ri) / log(e))) + b)) - 273;
	cout<<"The liquid temperature is "<<T<<"¡ãC."<<endl;
	return 0;
}
