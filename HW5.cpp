/*
 * HW5.cpp
 *
 *  Created on: 2016Äê5ÔÂ19ÈÕ
 *      Author: HUNTE
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double B, L, T, x;
	int n;
	double cross(double b, double l, double t, double x, int n);
	cin >> B >> L >> T >> x >> n;
	cout<<fixed<<showpoint<<setprecision(5);
	cout << cross(B, L, T, x, n);
}



double y(double b, double l, double t, double x, double z) {
	return (b / 2) * (1 - pow(((x * 2) / l), 2)) * (1 - pow((z / t), 2));
}



double cross(double b, double l, double t, double x, int n) {
	double area(double y1, double y2, double v);
	double y(double b, double l, double t, double x, double z);
	double total = 0.0;
	double z = 0.0;
	for (int i = 1; i <= n; i++) {
			total += area(y(b, l, t, x, z), y(b, l, t, x, z - (t / n)),
					(t / n));
			z -= (t / n);

	}
	return total;
}



double area(double y1, double y2, double h) {
	return ((y1 / 2 + y2 / 2) * h);
}
