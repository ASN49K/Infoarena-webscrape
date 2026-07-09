#include <fstream>
using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int n, s, x;

int xorsum()
{
	s = 0; in >> n;
	while(n--) in >> x, s ^= x;
	return s;
}

int main()
{
	int t; in >> t;
	while(t--) out << (xorsum() ? "DA\n" : "NU\n");
	return 0;
}