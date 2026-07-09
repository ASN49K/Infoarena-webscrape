#include <fstream>
using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int euclid(int x, int y)
{
	if (y==0) return x;
	else return euclid(y, x%y);
}

int main()
{
	int x,y;
	f>>x>>y;

	if (x>=y)
		g<<euclid(x,y);
	else g<<euclid(y,x);
	return 0;
}