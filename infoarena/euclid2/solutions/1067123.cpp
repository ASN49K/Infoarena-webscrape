#include <fstream>
using namespace std;
int main()
{
	ifstream f("cmmdc.in");
	ofstream g("cmmdc.out");
	int a, b,r;

		f >> a >> b;
		while (b)
		{
			r = a%b;
			a = b;
			b = r;

		}
		g << a;
	}
	return 0;
}
