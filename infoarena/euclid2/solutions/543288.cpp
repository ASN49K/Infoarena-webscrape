#include <iostream>
#include <fstream.h>

using namespace std;

int cmmdc(int a, int b)
{
	while(a != b)
		if(a > b)
			a -= b;
		else
			b -= a;
		
	return a;
}

int main()
{
	ifstream f ("euclid2.in");
	ofstream g ("euclid2.out");
	
	int n, a, b;
	f >> n;
	for(int i = 0; i < n; i ++)
	{
		f >> a >> b;
		g << cmmdc(a, b) << endl;
	}
}
