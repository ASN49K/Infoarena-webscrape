// Euclid.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "stdio.h"


FILE *f=fopen("euclid2.in", "r");
FILE *g=fopen("euclid2.out", "w");

int t;
int aa, bb;


int euclid(int a, int b)
{
	if (!b) return a;
	euclid(b, a%b);
}


void program()
{
	fscanf(f, "%d", &t);
	for (int i=1; i<=t; i++)
	{
		fscanf(f, "%d%d", &aa, &bb);
		fprintf(g, "%d\n", euclid(aa, bb));
	}
}


int main()
{
	program();
	return 0;
}

