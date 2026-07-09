#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	long long int a,b,t,i,r;
	fstream f("euclid.in",ios::in);
	fstream g("euclid.out",ios::out);
	f>>t;
	if(t<=100000&&t>=1)
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		r=a%b;
		while(r!=0)
		{
			a=b;
			b=r;
			r=a%b;
		}
		g<<b<<"\n";
	}
	f.close();
	g.close();
	return 0;
}
