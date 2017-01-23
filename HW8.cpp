/*
 * HW8.cpp
 *
 *  Created on: 2016Äê6ÔÂ1ÈÕ
 *      Author: Jiankun Zhang, Yingzuo Ci
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main(void) {
	// create a array
	int a[20];
	srand(time(0));
	// fill the array
	for (int i = 0; i < 20; i++) {
		a[i] = rand() % 100;
		cout<<a[i]<<endl;
	}
	//sort the data in array
	for(int n = 0; n <20; n++)
	{
		sort(a, a+20);
		cout<<a[n]<<endl;
	}
}

