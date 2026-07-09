#include <cstdio>
#include <iostream>
#include <fstream>
#include <list>
#include <limits.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <string.h>

using namespace std;

void swap(int &a, int&b)
{
	if (a==b) return;
	a = a^b;
	b = a^b;
	a = b^a;
}
int euclid(int a, int b)
{	
	if (a>b) swap(a,b);
	int k = b%a;
	while (k!=0)
	{		
		b = a;
		a = k;
		k = b%a;
	}
	return a;
}
int main()
{
	FILE* f =  fopen("euclid2.in","r");
	FILE* g = fopen("euclid2.out","w+");
	int T;
	fscanf(f,"%d",&T);
	for (int i=0;i<T;i++)
	{
		int a,b;
		fscanf(f,"%d %d", &a,&b);
		int c = euclid(a,b);
		fprintf(g,"%d\n",c);
	}
	fclose(f);
	fclose(g);
}