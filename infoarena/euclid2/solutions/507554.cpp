#include <iostream>
#include<stdio.h>
using namespace std;

/*long cmmdc (long a, long b)
{
	long r=b;
	while (r)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}*/

int main()
{
	long x,y,t,i;
	//ifstream f ("euclid2.in");
	freopen("euclid2.in","r",stdin);
	//ofstream g ("euclid2.out");
	freopen("euclid2.out","w",stdout);
	cin>>t;
	for (i=0;i<t;++i)
	{
		cin>>x>>y;
		while (y>0)
		{
			int r=x%y;
			x=y;
			y=r;
		}
		cout<<y<<endl;
	}
	//g.close();
}
