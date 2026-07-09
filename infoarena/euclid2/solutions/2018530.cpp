
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long n, x, y;

long long gcd(long long a, long long b) {
	long long r;
	if (a >= b) {
		while (a > 1) {
			r = a%b;
			a = b;
			b = r;
		}
		return a;
	}
	else
	{
		while (b > 1) {
			r = b%a;
			b = a;
			a = r;
		}
		return b;
	}
}

void read() {
	fin >> x >> y;
}

void write() {
	for (int i = 0; i < n; i++) {
		read();
		fout << gcd(x, y) << "\n";
	}
}

int main(){
	read();
	write();
	fin.close();
	fout.close();
    return 0;
}

