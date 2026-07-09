#include <fstream>

using namespace std;

int main() {
	int a,b,n;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>n;
	while (n--) {
		fin>>a; fin>>b;
		int t;
		while (b) {
			t=b;
			b=a%b;
			a=t;
		}
		if (a) fout<<a<<endl;
		else fout<<b<<endl;
	}
	return 0;
}
