/*
 * HW9.cpp
 *
 *  Created on: 6/2/2016
 *      Author: Jiankun Zhang & Yingzuo Ci
 */

#include <iostream>
#include <string>
using namespace std;
bool equals(int a[], int a_size, int b[], int b_size);

int main() {
	// create 3 arrays
	int a[3] = { 1, 2, 3 };
	int b[3] = { 1, 2, 3 };
	int c[3] = { 1, 1, 2 };
	// test if they are equal
	equals(a, 3, b, 3);
	equals(a, 3, c, 3);
	equals(b, 3, c, 3);
}

// return true if two array is exactly equal
bool equals(int a[], int a_size, int b[], int b_size) {
	if (a_size == b_size) {
		for (int i = 0; i < a_size; i++) {
			if (a[i] == b[i]) {
				if (i == a_size - 1) {
					cout << "Yes" << endl;
					return true;
				}
			} else {
				cout << "No" << endl;
				return false;
				break;
			}
		}
	} else {
		cout << "No" << endl;
		return false;
	}
}