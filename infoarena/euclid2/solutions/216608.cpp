#include <fstream>
using namespace std;
int main()
{
	int a,b;
	ifstream f("euclid2.in");
	f>>a>>b;
	f.close();
	while (a!=b)
	{
		if (a>b) a-=b;
		else
			b-=a;
	}
	ofstream g("euclid2.out");
	g<<a;
	g.close();
	return 0;
}