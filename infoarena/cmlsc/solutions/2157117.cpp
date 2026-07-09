// Cel_mai_lung_sir_comun.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n, m, a[1025], b[1025], i, j, c[1025], dimMax;

	dimMax = 0;

	ifstream fin("cmlsc.in");
	ofstream out("cmlsc.out");

	fin >> n >> m;
	for (i = 0; i < n; i++)
	{
		fin >> a[i];
	}
	for (i = 0; i < m; i++)
	{
		fin >> b[i];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i] == b[j])
			{
				c[dimMax++] = a[i];
			}
		}
	}

	out << dimMax << "\n";

	for (i = 0; i < dimMax; i++)
	{
		out << c[i] << " ";
	}
    return 0;
}

