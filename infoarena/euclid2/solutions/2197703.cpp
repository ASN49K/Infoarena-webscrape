#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
int t,a,b;

int cmmdc(int a,int b)
{
	if (!b)
		return a;
	return cmmdc(b,a%b);
}

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
	f>>t;
	for (t;t;--t)
	{
		f>>a>>b;
	    g<<cmmdc(a,b)<<'\n';
	}

	return 0;
}