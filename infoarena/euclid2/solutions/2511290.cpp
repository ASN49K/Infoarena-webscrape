#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");    
int main()
{
	long long a, r, b;
	int i, nr;
	f >> nr;
	for (i = 1; i <= nr; i++)
	{
		f >> a >> b;
		while (b != 0)
		{
			r = a % b;
			a = b; b = r;
		}
		g << a << "\n";
	}
	return 0;
}
