// Algoritmul lui euclid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int T, i, t;
		long a, b;
	fin >> T;
	for (i = 1; i <= T; i++)
	{
		fin >> a; fin >> b;
		while (b)
			{
				t = a%b;
				a = b;
				b = t;
			}
		fout <<a<<"\n";
	}
	
    return 0;

}

