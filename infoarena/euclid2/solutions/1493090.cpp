#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");
int euclid(int a, int b)
{
	int r;
	while (b > 0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	int n, a, b;
	int i;
	fi >> n;
	for (i = 1; i <= n; i++)
	{
		fi >> a >> b;
		fo << euclid(a, b)<<"\n";
	}
	return 0;
}