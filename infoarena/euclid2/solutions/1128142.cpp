//#include "infoarena.h"
#include <fstream>
#include <cstring>
#include <cmath>
extern int muie;

#ifdef INFOARENA_H
namespace euclid2 {
#endif

unsigned gcd(unsigned x, unsigned y)
{
	if (y == 0)
		return x;

	return gcd(y, x%y);
}

int main()
{
	std::ifstream in("euclid2.in");
	std::ofstream out("euclid2.out");
	unsigned N;
	in >> N;
	for (unsigned i = 0; i < N; ++i)
	{
		int a, b;
		in >> a >> b;
		out << gcd(a, b) << '\n';
	}

	return 0;
}

#ifdef INFOARENA_H
}
#endif