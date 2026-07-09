#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main ()
{
	ifstream in("euclid2.in");
	ofstream out ("euclid2.out");
	int i,n,a,b,r;
	in>>n;
	for (i=1;i<=n;i++)
	{
		in>>a>>b;
		while (b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		out<<a<<"\n";
	}	
	return 0;
}