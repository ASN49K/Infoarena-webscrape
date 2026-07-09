// infoarena.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
int computeCmmdc(int a, int b);

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int t, a, b;
	scanf("%d", &t);
	for (; t; t--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", computeCmmdc(a, b));
	}
	return 0;
}

int computeCmmdc(int a, int b)
{
	while (a%b != 0)
	{
		int aux = b;
		b = a % b;
		a = aux;
	}
	return b;
}

