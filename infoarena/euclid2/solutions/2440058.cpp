#include <fstream>
using namespace std;
ifstream in("cmmdc.in");
ofstream out("cmmdc.out");
long cmmdc(long a, long b)
{
	long r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	long q;
	in >> q;
	for (int i = 1; i <= q; i++)
	{
		long a, b;
		in >> a >> b;
		int z = cmmdc(a, b);
		out << z << '\n';
	}
	return 0;
}