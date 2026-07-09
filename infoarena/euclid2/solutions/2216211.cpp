#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long euclid(long a, long b)
{
	if (b == 0)
		return a;
	else
		return euclid(b, a%b);

}
int main()
{
	int n;
	long a, b;
	f >> n;
	for (int i = 1; i <= n; i++)
	{
		f >> a;
		f >> b;
		g << euclid(a, b) << "\n";
	
	}
}