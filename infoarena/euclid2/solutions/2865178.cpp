#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define dbg(x) cout << #x <<": " << x << "\n";
using ll = long long;

const string myf = "file";
ifstream fin(myf + ".in");
ofstream fout(myf + ".out");

int a, b;
int gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {

	fin >> a >> b;
	fout << gcd(a, b);

	fin.close();
	fout.close();
	return 0;
}