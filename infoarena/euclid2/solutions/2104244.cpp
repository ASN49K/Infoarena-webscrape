#include<fstream>
#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int n = 0;
	f >> n;
	for (int i = 0; i < n; i++)
	{
		int x1 = 0, x2 = 0;
		f >> x1 >> x2;
		int d = gcd(x1, x2);
		g << d << endl;
	}
	f.close();
	g.close();
	return 0;
}