#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
	long t,i,a,b,m;
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		do{
			m=a%b;
			a=b;
			b=m;
		}while(b!=0);
		g<<a<<'\n';
	}
	f.close(); g.close();
}
