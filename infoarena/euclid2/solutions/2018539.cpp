

#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long n;

long long gcd(long long a, long long b) {
	long long r;
	if (a >= b) {
		while (b!=0) {
			r = a%b;
			a = b;
			b = r;
		}
		return a;
	}
	else
	{
		while (a!=0) {
			r = b%a;
			b = a;
			a = r;
		}
		return b;
	}
}

void read(long long &t, long long &s) {
	fin >> t >> s;
}

void write() {
	fin >> n;
	long long x, y;
	for (int i = 0; i < n; i++) {
		read(x, y);
		fout << gcd(x, y) << "\n";
	}
}

int main(){
	write();
    return 0;
}

