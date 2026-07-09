// 1. Euclid's Algorithm.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int t, i, a, b, remainder=1;

int gcd(int a, int b)
{
    if (!b) 
		return a;
    return gcd(b, a % b);
}

int main()
{
	fin>>t;
	for (i=1; i<=t; i++) {
		fin>>a>>b;
		fout<<gcd(a,b);
	}
	return 0;
}

