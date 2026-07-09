#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("euclid2.in" );
	ofstream fout("euclid2.out");
	unsigned t, a, b, r;
	fin >> t;
	while (t--){
		fin >> a >> b;
		r = a%b;
		while (r) r = (a = b) % (b = r);
		fout << b << "\n";
	}

	fin.close();
	fout.close();
	return 0;
}