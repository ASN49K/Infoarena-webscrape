// https://infoarena.ro/problema/euclid2

#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T;
int a, b;

int main() {
	fin >> T;

	for(int i = 0; i < T; i++) {
		fin >> a >> b;

		while(a != b) {
			if(a > b) {
				a -= b;
			} else {
				b -= a;
			}
		}

		fout << a << endl;
	}

	return 0;
}
