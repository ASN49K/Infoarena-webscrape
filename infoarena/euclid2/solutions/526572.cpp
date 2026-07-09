#include<iostream>
#include<fstream>
using namespace std;
int main (void)
{
	int i,a,b,t,r;
	fstream f,g;
	f.open("euclid2.in",ios::in);
	g.open("euclid2.out",ios::out);
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		while (b)
		{
		r=a%b;
		a=b;
		b=r;
	
		}
			g<<a<<endl;
	}
	f.close();
	g.close();
}	