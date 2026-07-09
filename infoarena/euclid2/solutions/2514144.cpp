#include <fstream>

int euclid(int a, int b) {
	int r = a % b;

	while (r) {
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

int main()
{
	std::ifstream fin("euclid2.in");
	std::ofstream fout("euclid2.out");
	
	int n;
	fin >> n;
	while (n--) {
		int a, b;
		fin >> a >> b;

		fout << euclid(a, b) << "\n";
	}
	

	fin.close(), fout.close();

	return 0;
}