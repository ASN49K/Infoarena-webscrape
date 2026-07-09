#include <fstream>

int T, a, b;

int gcd( int a, int b );


int main()
{
	std::ifstream ifs("euclid2.in");
	std::ofstream ofs("euclid2.out");

	ifs >> T;

	for ( ; T; --T) {
		ifs >> a >> b;
		ofs << gcd(a, b) << "\n";
	}

	ifs.close();
	ofs.close();

	return 0;
}

// @pre a, b positive integers
int gcd( int a, int b)
{
	// base case (stop recursion)
	if (!b) {	
		return a;
	}else {
		return gcd(b, a % b);
	}
}