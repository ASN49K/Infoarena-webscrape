#include<iostream>
#include<fstream>
using namespace std;
int main (void)
{
	int i,a,b,t;
	fstream f,g;
	f.open("euclid2.in",ios::in);
	g.open("euclid2.out",ios::out);
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		while (a!=b)
			if (a>b)
				a=a-b;
			else
				b=b-a;
			g<<b<<endl;
			
	}
	f.close();
	g.close();
}	