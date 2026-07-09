#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int euclid (int a, int b)
{
	if (!b)
		return a;
	return euclid(b, a % b);
}

int main (int argc, char const *argv[])
{
	ifstream in ("euclid2.in");
	ofstream out ("euclid2.out");
	int n; in >> n;
	for (; n; --n)
	{
		int x, y; in >> x >> y;
		out << euclid(x, y) << '\n';
	}
	in.close();
	out.close();
	
	return 0;
}
