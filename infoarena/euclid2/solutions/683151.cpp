#include<fstream>
using namespace std;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int x,y,z,nr;
	f >> nr;
	for (int i=1;i<=nr;i++)
	{
		f >> x >> y;
		while (y!=0)
		{
			z=x%y;
			x=y;
			y=z;
		}
		g << x << "\n";
	}
	return 0;
}
		