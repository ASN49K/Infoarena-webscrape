#include <fstream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;

	return gcd(b, a % b);
}

int main()
{
	ifstream ifs("euclid2.in");
	ofstream ofs("euclid2.out");

	int a, b;
	ifs >> a >> b;
	
	ofs << gcd(a, b) << endl;

	return 0;
}
