/*
cel mai lung subsir comun infoarena programare dinamica
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

#define IN_FILE "cmlsc.in"
#define OUT_FILE "cmlsc.out"
ifstream f(IN_FILE);
ofstream g(OUT_FILE);

//variables
WI x;
class sir
{
public:int lenght;
public:VI a;
};
sir a, b;
VI aux;
//other functions
void reading()
{
	f >> a.lenght >> b.lenght;
	a.a.RS(a.lenght);
	b.a.RS(b.lenght);
	FORN(i, a.lenght)
	{
		f >> a.a[i];
	}
	FORN(i, b.lenght)
	{
		f >> b.a[i];
	}
	f.close();
}
void solving()
{
	x.RS(a.lenght + 1, VI(b.lenght + 1));
	FORN(i, a.lenght)
	{
		FORN(j, b.lenght)
		{
			if (a.a[i] == b.a[j])
			{
				x[i + 1][j + 1] = x[i][j] + 1;
			}
			else
			{
				x[i + 1][j + 1] = max(x[i][j + 1], x[i + 1][j]);
			}
		}
	}
	int i = a.lenght, j = b.lenght;
	while (i > 0)
	{
		if (a.a[i - 1] == b.a[j - 1])
		{
			aux.push_back(a.a[i]);
			--i;
			--j;
		}
		else if (x[i - 1][j] > x[i][j - 1])
		{
			--i;
		}
		else
		{
			--j;
		}
	}
}
void write_data()
{
	g << x[a.lenght][b.lenght] << "\n";
	FORD(i, x[a.lenght][b.lenght] - 1, 0)
	{
		g << aux[i] << " ";
	}
}
int main()
{
	reading();
	solving();
	write_data();
}
