// Algoritmul lui Euclid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	int T;
	long long a, b;
	fin >> T;
	while (T-- != 0) {
		fin >> a >> b;
		int aux;
		while (b) {
			aux = a % b;
			a = b;
			b = aux;
		}
		fout << a << '\n';
	}

}
