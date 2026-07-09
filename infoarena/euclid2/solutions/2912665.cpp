#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n;
int cmmdc(int x, int y) {
	if (y == 0)
		return x;
	else return cmmdc(y, x % y);
}
void citire() {
	int x, y;
	fin >> n;
	for (int i = 1; i <= n; ++i) {
		fin >> x >> y;
		fout << cmmdc(x, y) << "\n";
	}
}
int main() {
    
	citire();
	return 0;
}