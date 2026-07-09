#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	int t, n, i, x, sx;
	ifstream f("nim.in");
	ofstream g("nim.out");
	f >> t;
	while(t)
	{
		f >> n;
		for ( i = 0, sx = 0; i < n; i++)
		{
			f >> x;
			sx ^= x;
		}
		if ( sx == 0 )
			g << "NU" << endl;
		else
			g << "DA" << endl;
		t--;
	}
	f.close();
	g.close();
	return 0;
}