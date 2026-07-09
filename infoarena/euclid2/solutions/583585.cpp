#include <fstream>

using namespace std;

fstream fi;
fstream fo;
long long a, b, r;
long long n;

int main()
{
	fi.open("euclid2.in",ios::in);
	fo.open("euclid2.out",ios::out);
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
		fo << a << endl;
	}
	fi.close();
	fo.close();
	return 0;
}