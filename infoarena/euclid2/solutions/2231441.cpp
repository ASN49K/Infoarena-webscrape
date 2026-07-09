#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t, a, b;

int euclid(int x, int y)
{
	if (!y)
		return x;
	else return euclid(y, x%y);
}

int main()
{
	f >> t;
	for (int i = 0; i < t; ++i)
	{
		f >> a >> b;
		g << euclid(a, b)<<endl;
	}
}
