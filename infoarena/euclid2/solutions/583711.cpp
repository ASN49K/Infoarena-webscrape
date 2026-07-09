#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
	int d, c, t, h, r;
	fin >> t;
	for(int i = 1; i <= t; i++)
	{
		fin >> d >> c;
	    h = d;
		t = c;
		while(h % t != 0)
		{
			r = h % t;
			h = t;
			t = r;
		}
		fout << t << '\n';
		
	}
	fin.close();
	fout.close();
	return 0;
}

		