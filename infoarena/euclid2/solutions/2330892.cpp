#include <iostream>
#include <fstream>

using namespace std;
int cmmdc(int a, int b)
{
	if (b == 0)
		return a;
	return cmmdc(b, a%b);
}

int main()
{
	int n,a,b;
	ifstream f("euclid.in");
	ofstream g("euclid.out");
	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> a;
		f >> b;
		g << cmmdc(a, b) << endl;
	}
	return 0;
}