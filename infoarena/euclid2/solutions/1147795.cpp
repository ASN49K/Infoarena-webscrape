/*
euclid2 infoarena
*/
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<cstdio>
#include<fstream>
#include<iostream>
#include<ctime>
#include<set>
#include<map>
#include<cmath>

using namespace std;

#define LL long long
#define PII pair<int ,int>
#define PCI pair<char ,int>
#define VB vector <bool>
#define VI vector <int>
#define VC vector <char>
#define WI vector<VI>
#define WC vector<VC>
#define RS resize
#define X first
#define Y second

#define FORN(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REPEAT do
#define UNTIL(x) while((x))

#define IN_FILE "euclid2.in"
#define OUT_FILE "euclid2.out"
ifstream f(IN_FILE);
ofstream g(OUT_FILE);

//variables
int t;
int aux1, aux2;
//other functions
int gcd(int a, int b)
{
	if (a == b)
	{
		return a;
	}
	if (a > b)
	{
		swap(a,b);
	}
	b = b%a;
	if (b == 0)
	{
		return a;
	}
	return gcd(a,b);
}
void reading()
{
	f >> t;
	FORN(i, t)
	{
		f >> aux1 >> aux2;
		g << gcd(aux1,aux2)<<"\n";
	}
}
void solving()
{
}
void write_data()
{
}
int main()
{
	reading();
	solving();
	write_data();
}
