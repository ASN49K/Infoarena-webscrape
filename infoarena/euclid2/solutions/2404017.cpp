#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");


int main() {
	
	int t;
	int a,b;
	fin >> t;
	for ( ; t > 0; --t) {
	fin >> a >> b;
	fout << __gcd(a,b) << "\n";
	}
}	
