#include <fstream>

using namespace std;

int gcd(int a, int b) {
	if (!a) return b;
	return gcd(b,a%b);
}

int main() {
	int a,b,n;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>n;
	for (int i=0;i<n;i++) {
		fin>>a; fin>>b;
		fout<<gcd(a,b)<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}