#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int x, int y)
{
	if (!y)
		return x;
	else return euclid(y, x%y);
}

int main()
{
	int t, a, b;
	f >> t;
	while(t-->0)
	{
		f >> a >> b;
		g << euclid(a, b)<<endl;
	}
	return 0;
}
