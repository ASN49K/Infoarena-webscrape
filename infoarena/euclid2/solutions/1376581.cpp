#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f;
ofstream g;
int main()
{
	int T, a, b, i, j, x;
	f.open("euclid2.in");
	f >> T;
	x = 0;
	g.open("euclid2.out");
	for (i = 1; i <= T; i++)
	{
		f >> a >> b;
		
		for (j = 1; j <= a; j++)
		{
			if (a%j == 0 && b%j == 0)
				x = j;
		}
		g << x << endl;
		
		
	}
	g.close();
	f.close();
	return 0;
}