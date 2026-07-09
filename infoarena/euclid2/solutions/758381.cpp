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
	ifstream f("euclid2.in",ios::in);
	ofstream g("euclid2.out",ios::out);
	int T;
	f>>T;
	for (int i=0;i<T;i++)
	{
		int a,b;
		f>>a>>b;
		int c = euclid(a,b);
		g<<c<<endl;
	}
	f.close();
	g.close();
}