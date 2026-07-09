#include <fstream>
using namespace std;

int euclid (int, int);

int main ()
{
	ifstream f ("euclid2.in");
	ofstream g ("euclid2.out");
	int n, a, b;

	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> a >> b;
		g << euclid (a, b);
	}
	f.close ();
	g.close ();
}

int euclid (int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return euclid (b, a % b);
}