#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	
	long long n,a,b,r;
	
	f>>n;
	
	for(int i=1;i<=n;i++)
	{
		f>>a>>b;
		
		while(b!=0)
		{
			r=a%b;
			a=b;
			b=r;
		}
		g<<a<<"\n";
	}
	
	return 0;
}
			
			