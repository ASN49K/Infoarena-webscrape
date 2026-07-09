#include <iostream>
#include <fstream>

using namespace std;

int n,m,p;


int gcd (int a, int b)
{
	int p;

	while (b != 0)
	{
		p = a % b;
		a = b;
		b = p;
	}
	return b;
}

int main ()
{	
	ifstream finput ("euclid2.in");
	finput>>n;
	ofstream foutput ("euclid2.out");
	for (int i = 1; i<=n; i++) 
		{
			finput>>m>>p;
			foutput<<gcd(m,p);
		}
	return 0;
}
