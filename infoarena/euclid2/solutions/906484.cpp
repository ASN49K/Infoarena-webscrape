#include <fstream>
using namespace std;
const char iname[] = "euclid2.in";
const char oname[] = "euclid2.out";
ifstream fin(iname);
ofstream fout(oname);
int Q, a, b;
inline int Euclid(int &x, int &y)
{
	if (x == 0) return y;
	while (y)
	{
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}
int main()
{
	fin >> Q;
	while (Q--)
	{
		fin >> a >> b;
		fout << Euclid(a, b) << '\n';
	}
	return 0;
}
