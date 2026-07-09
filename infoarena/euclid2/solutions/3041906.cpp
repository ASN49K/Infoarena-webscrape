#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
	int T,i;
	long int x,y;
	f>>T;
	for(i=1;i<=T;i++)
	{
		f>>x>>y;
		while(x!=0)
		{
			int t=y%x;
			y=x;
			x=t;
		}
		g<<y<<endl;
	}
}
