#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<set>
#include<fstream>
#define N 2*1e3
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	long long a, b ,n;
	f >> n;
	for (int i = 0; i < n; ++i) {
		f >> a >> b;
		g << gcd(a,b)<<"\n";
	}
	return 0;
}