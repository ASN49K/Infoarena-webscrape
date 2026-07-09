#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
	int T;
	in >> T;
	while (T--)
	{
		long a, b, r;
		in >> a >> b;

		do
		{
			r = a%b;
			a = b;
			b = r;
		} while (r);
		out << a << '\n';
	}
}