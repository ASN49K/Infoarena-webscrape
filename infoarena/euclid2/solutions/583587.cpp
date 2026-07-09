#include <fstream>

using namespace std;

ifstream fi;
ofstream fo;
int a, b, r;
int n;

int main()
{
	fi.open("euclid2.in");
	fo.open("euclid2.out");
	fi >> n;
	for (int i=1; i<=n; i++)
	{
		fi >> a >> b;
		while (b != 0)
		{
			r = b;
			b = a % b;
			a = r;
		}
		fo << a << "\n";
	}
	fi.close();
	fo.close();
	return 0;
}