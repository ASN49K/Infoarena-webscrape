#include <fstream>

int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a%b);
}

int main() {
	std::ifstream fin("euclid2.in");
	std::ofstream fout("euclid2.out");
	int t;
	fin>>t;
	while(t--) {
		int a, b;
		fin>>a>>b;
		if(a<b) std::swap(a, b);
		fout<<gcd(a, b)<<"\n";
	}
}