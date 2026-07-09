#include <fstream>
using namespace std;

fstream in	("euclid2.in");
ofstream out("euclid2.out");

int Euclid(int a, int b)
{
	if (!b)
		return a;
	return Euclid(b, a%b);
}
int main()
{
	int T;
	in >> T;
	while (T--)
	{
		int a, b;
		in >> a >> b;

		out << Euclid(a,b) << endl;
	}
}