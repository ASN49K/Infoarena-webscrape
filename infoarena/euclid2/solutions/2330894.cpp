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
	int T,a,b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f >> T;
	for (int i = 0; i < T; i++)
	{
		f >> a;
		f >> b;
		g << cmmdc(a, b) << endl;
	}
	return 0;
}