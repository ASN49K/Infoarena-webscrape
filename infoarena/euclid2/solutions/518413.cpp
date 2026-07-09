#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int vec[100][100];

int euclid(int a, int b)
{
	if (a==b)
		return a;
	if(a>b && vec[a][b]) return vec[a][b];
	if(b>a && vec[b][a]) return vec[b][a];
	
	if(a>b)
		vec[a][b] = euclid(a-b,b);
	else
		vec[b][a] = euclid(b-a,a);
}


int main()
{
	int a,x,y;
	f>>a;
	for(int i=1; i<=a; i++)
	{
		f>>x>>y;
		g<<euclid(x,y);
	}
	return 0;
}