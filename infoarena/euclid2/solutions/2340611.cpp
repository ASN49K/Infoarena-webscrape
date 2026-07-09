// Algoritmul lui Euclid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int t;
	int a, b;
	cin >> t;
	while (t-- != 0) {
		cin >> a >> b;
		int aux;
		while (b) {
			aux = a % b;
			a = b;
			b = aux;
		}
		cout << a << '\n';
	}

}
