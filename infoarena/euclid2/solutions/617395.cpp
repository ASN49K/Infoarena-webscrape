#include <iostream>
#include <fstream>

using namespace std;

int n;
int a [],b [];


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
	for (int i = 1; i<=n; i++) 
		{
			finput>>a[i]>>b[i];
		}
	ofstream foutput ("euclid2.out");
	for (int i = 1; i<=n;i++) foutput<<gcd(a[i],b[i]);
	return 0;
}
