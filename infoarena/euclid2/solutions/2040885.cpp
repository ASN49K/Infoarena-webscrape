//============================================================================
// Name        : Euclid2.cpp
// Author      : Lucian
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
using namespace std;

int main() {

	ifstream f("euclid2.in");
	ofstream g("euclid2.out");

	int n;
	f >> n;

	int i;
	for (i=1;i<=n;i++)
	{
		int a,b,r;
		f >> a >> b;
		while (b)
		{
			r = a % b;
			a = b;
			b = r;
		}
		g << a << '\n';
	}

	f.close();
	g.close();

	return 0;
}
