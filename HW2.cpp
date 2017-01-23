/* 	Programmer: JianKun Zhang, Yingzuo Ci
 Filename: HW2.cpp
 Objective: Problem P3.30 from CFE Textbook
 Input: int cl, ol, OR, il, ir, dl, dr, mu. String gear.
 Output: String.
 Equation: Given in textbook
 Function: main()
 Date: 5/17/2016
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
	string gear;
	int cl, ol, OR, il, ir, dl, dr, mu;
	bool right_open, left_open;
	right_open = false;
	left_open = false;

	cout
			<< "Please input the lock state, in order of master unlock, child lock, "
			<< endl;
	cout << "outside left handler, outside right handler, inside left handler, "
			<< endl;
	cout << "inside right handler, left dash board, right dash board and gear, "
			<< endl;
	cout << "0 represent unlock, 1 represent lock, separate by space." << endl;

	cin >> mu >> cl >> ol >> OR >> il >> ir >> dl >> dr >> gear;

	if (gear == "p" && mu) {
		if (!cl && (ol || il || dl)) {
			left_open = true;
		}
		if (!cl && (OR || ir || dr)) {
			right_open = true;
		}
		if (left_open) {
			cout << "Left door open" << endl;
		}
		if (right_open) {
			cout << "Right door open" << endl;
		}
		if (!right_open && !left_open) {
			cout << "Both door closed" << endl;
		}
	}
}

