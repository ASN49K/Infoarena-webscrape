#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
	int a,x,y;
	f>>a;
	for(int i=1; i<=a; i++)
	{
		f>>x>>y;
		while(x!=y)
		{
			if(x>y) 
				x -= y;
			else
				y -= x;
		}
		g<<x<<'\n';
	}
	return 0;
}