#include<iostream>
#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
	long r,a,b;
	int t,i;
int main(void)
{ 
	f>>t;
	for(i=0;i<t;i++)
	{
		f>>a;
		f>>b;
		r=a%b;
		while(r)
		{
			a=b;
			b=r;
			r=a%b;
		}
		g<<b;
		if(i!=t-1) g<<endl;
	}
	return 0;
}
