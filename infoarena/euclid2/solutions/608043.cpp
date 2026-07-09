#include <fstream>

int gcd( int a, int b );

int main()
{
	int i;
	int T;
	int a, b;

	std::ifstream ifs("euclid2.in");
	std::ofstream ofs("euclid2.out");

	ifs >> T;

	for (i = 0; i < T; i++) {
		ifs >> a >> b;

		ofs << gcd(a, b) << std::endl;
	}

	ifs.close();
	ofs.close();

	return 0;
}

// @pre a, b positive integers
int gcd( int a, int b)
{
	// base case (stop recursion)
	if (b == 0) {	
		return a;
	}else {
		return gcd(b, a % b);
	}
}