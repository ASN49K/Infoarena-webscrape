
#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a, int b)
{
	if (b)
		return cmmdc(b, a%b);
	else return a;
}
int main()
{
	int n, i, a, b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f >> n;
	for (i = 0; i < n; i++)
	{
		f >> a; f >> b;
		if (a == 1 || b == 1 || a-b==1 || b-a==1)
			g << 1<<'\n';
		else g << cmmdc(a, b) <<'\n';
	}
}

