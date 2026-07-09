#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	long long int a,b,T,i,r;
	fstream f("euclid.in",ios::in);
	fstream g("euclid.out",ios::out);
	f>>T;
	for(i=1;i<=T;i++)
	{
		f>>a>>b;
		r=a%b;
		while(r!=0)
		{
			a=b;
			b=r;
			r=a%b;
		}
		g<<b<<endl;
	}
	f.close();
	g.close();
	return 0;
}