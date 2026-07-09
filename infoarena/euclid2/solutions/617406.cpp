#include <iostream>
#include <fstream>

using namespace std;

long long int m,p;
int n;


int gcd (long long int a, long long int b)
{
	if (!b) return a;
	return gcd (b, a % b);
}

int main ()
{	
	ifstream finput ("euclid2.in");
	finput>>n;
	ofstream foutput ("euclid2.out");
	for (int i = 1; i<=n; i++) 
		{
			finput>>m>>p;
			foutput<<gcd(m,p)<<'/n';
		}
	return 0;
}
