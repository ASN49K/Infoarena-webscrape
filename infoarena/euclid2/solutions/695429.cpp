#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream g("euclid2.in");
	ofstream h("euclid2.out");
	int n, a, b;
	g>>n;
	for(int i=1;i<=n;i++)
	{
		g>>a>>b;
		while(a&&b)
		{
			if(a>=b)
				a%=b;
			else b%=a;
		}
		if(a)
			h<<a;
		else h<<b;
		h<<"\n";
	}
}