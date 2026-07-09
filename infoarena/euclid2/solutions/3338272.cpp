#include <fstream>

using namespace std;

int gcd(int aa, int bb)
{
	if (bb == 0) return aa;

	return gcd(bb, aa % bb);
}

int main()
{
	ifstream ifs("euclid2.in");
	ofstream ofs("euclid2.out");

	int aa, bb, nn;
	ifs >> nn;

	for (int ii = 0; ii < nn; ++ii)
	{
		ifs >> aa >> bb;

		ofs << gcd(aa, bb) << endl;
	}

	return 0;
}
