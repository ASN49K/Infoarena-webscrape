#include<iostream>
#include<fstream>
using namespace std;

int euclid(int a, int b)
{
	if (b == 0)
		return a;
	else
		return euclid(b, a%b);
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int t, a, b;
	f >> t;
	for (int i = 1; i <= t; i++)
	{
		f >> a >> b;
		g << euclid(a, b) << endl;
	}
	g.close();
	f.close();
}