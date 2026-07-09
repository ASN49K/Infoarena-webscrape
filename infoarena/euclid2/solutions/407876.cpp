#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	long t,i,a,b,r;
	fstream f("euclid2.in",ios::in), g("euclid2.out",ios::out);
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		do{
			r=a%b;
			a=b;
			b=r;
		}while(b!=0);
		g<<a<<'\n';
	}
	f.close(); g.close();
}
