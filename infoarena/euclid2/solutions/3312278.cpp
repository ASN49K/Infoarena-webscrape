#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
long long cmmdc(long long a, long long b)
{
	int r;
	while (b != 0)
	{
		r = a & b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	long long a, b,n;
	in >> n;
	while (n--)
	{
		in >> a >> b;
		out << cmmdc(a, b);
	}



}