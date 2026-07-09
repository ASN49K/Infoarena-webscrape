#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

using ll = long long;

const string myf = "euclid2";
ifstream fin(myf + ".in");
ofstream fout(myf + ".out");



int t;
int a, b;

int my_gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {

	fin >> t;
	while (t--) {
		fin >> a >> b;
		fout << __gcd(a, b) << "\n";
	}


	fin.close();
	fout.close();
	return 0;
}