#include <fstream>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
int gcd(long long a,long long b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
int main()
{
	long long n;
	long long a;
	long long b;
	ifstream myf;
	myf.open("euclid2.in");
	ofstream op;
	op.open("euclid2.out");
	myf >> n;
	while (n)
	{
		myf >> a >> b;
		int p = gcd(a,b);
		op << p << endl;
		n--;
	}
	return 0;
}
