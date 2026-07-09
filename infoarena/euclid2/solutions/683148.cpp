#include<fstream>
using namespace std;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int x,y,z;
	f >> x >> y;
	while (y!=0)
	{
		z=x%y;
		x=y;
		y=z;
	}
	g << x;
	return 0;
}
		