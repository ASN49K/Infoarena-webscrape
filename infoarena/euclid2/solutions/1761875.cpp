//#include "stdafx.h"
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

ifstream fin("streetcrypto.in");
ofstream fout("streetcrypto.out");

long long gcd(long long a, long long b) 
{
	long long r;
	while (b != 0) 
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	unsigned int t, n;
	unsigned long long int i, j, rez = 1, v[55];
	vector<unsigned long long int> prim;
	bool found = false;

	fin >> t;
	for (j = 0; j < t; ++j)
	{
		fin >> n;
		for ( i = 0; i < n; ++i)
		{
			fin >> v[i];
		}

		for (i = 0; i < n - 1; ++i)
		{
			found = false;
			for (j = i + 1; j < n && !found; ++j)
			{
				rez = gcd(v[i], v[j]);
				if (rez != 1)
				{
					prim.push_back(rez);
					found = true;
				}
			}
		}

		rez = gcd(v[0], v[n - 1]);
		if (rez != 1)
			prim.push_back(rez);

		std::sort(prim.begin(), prim.end());
		for (i = 0; i < prim.size(); i++)
		{
			fout << prim[i] << " ";
		}
		prim.clear();
	}

	return 0;
}