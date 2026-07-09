#include <fstream>
#include<stdio.h>

using namespace std;

int main()
{
	long x,y,t,r;
	ifstream f ("euclid2.in");
	freopen("euclid2.out","w",stdout);
	f>>t;
	while (t)
	{
		f>>x>>y;
		while (y>0)
		{
			r=x%y;
			x=y;
			y=r;
		}
		printf("%d\n",x);
		t--;
	}
}
