#include <iostream>
#include <fstream>

using namespace std;

const char iname[] = "euclid2.in";
const char oname[] = "euclid2.out";

ifstream fin(iname);
ofstream fout(oname);

int t, i, x, y;

inline int euclid(int a, int b)
{
	if(!b)
		return a;
	else
		return euclid(b, a % b);
}

int main()
{
	fin >> t;
	for(i = 1; i <= t; i ++)
	{
		fin >> x >> y;
		fout << euclid(x, y) << "\n";
	}
	return 0;
}