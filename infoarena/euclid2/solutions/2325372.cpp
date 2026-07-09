// euclid2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<fstream>

using namespace std;
int cmmdc(int a, int b)
{
	if (!b) return a;
	return cmmdc(b, a % b);
}

int main()
{
	ifstream f1("euclid2.in");
	ofstream f2("euclid2.out");
	int t, a, b;
	f1 >> t;
	
	for (int i = 0; i < t; i++)
	{
		f1 >> a >> b;
		f2 << cmmdc(a, b);
	}
	f1.close();
	f2.close();
}

