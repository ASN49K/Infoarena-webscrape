// Algoritmul lui Euclid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

FILE* fin, * fout;

ll T;
ll a, b;

ll GCD(ll a, ll b)
{
	ll r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void Read()
{
	fin = fopen("euclid2.in", "r");
	fout = fopen("euclid2.out", "w");
}

void Solve()
{
	fscanf(fin, "%lld", &T);
	for (; T; T--)
	{
		fscanf(fin, "%lld %lld", &a, &b);
		fprintf(fout, "%lld \n", GCD(a, b));
	}
}

int main()
{
	Read();
	Solve();
	return 0;
}