// ConsoleApplication21.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a, int b)
{
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	int t,i,a,b;
	f >> t;
	for (i = 1; i <= t; i++)
	{
		f >> a >> b;
		g << euclid(a, b)<<"\n";
	}
    return 0;
}

