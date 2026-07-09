#include <fstream>

using namespace std;

int gcd(int a, int b) {
	if (!a) return b;
	int t;
	while (b) {
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}

int main() {
	int a,b,n;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	if (fin.is_open() && fout.is_open()) {
		fin>>n;
		for (int i=0;i<n;i++) {
			fin>>a; fin>>b;
			fout<<gcd(a,b)<<endl;
		}
		return 0;
	}
	else
		return 1;
}