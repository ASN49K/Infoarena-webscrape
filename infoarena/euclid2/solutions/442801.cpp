#include<fstream>
#include<iostream>
using namespace std;
int t,a,b;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int i;
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		while(a!=b)
		{
			if(a>b)
				a=a-b;
			else
				b=b-a;
		}
		g<<a<<"\n";
	}
	f.close();
	g.close();
}
