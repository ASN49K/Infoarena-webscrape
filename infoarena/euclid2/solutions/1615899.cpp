// Algoritmul lui euclid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("euclid1.txt");
	ofstream fout("euclid2.txt");
	int n, i, t, a, b;
	fin >> n;
	for (i = 1; i <= n; i++)
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

