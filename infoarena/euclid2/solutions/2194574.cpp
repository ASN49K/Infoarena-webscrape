// euclidalg.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t;
pair <int, int> cmd;

inline int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

int main()
{
	in >> t;
	for (int i = 1; i <= t; i++)
	{
		in >> cmd.first >> cmd.second;
		out << gcd(cmd.first, cmd.second) << '\n';
	}

    return 0;
}

