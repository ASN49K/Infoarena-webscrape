// AlgoritmEuclid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	if (a % b != 0)
	{
		gcd(b, a%b);
	}
	else
		return b;
}

int main()
{
	int n, a, b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f >> n;
	for (int i = 1; i <= n; i ++)
	{
		f >> a >> b;
		g << gcd(a, b)<<"\n";
	}
	f.close();
	g.close();
    return 0;
}

