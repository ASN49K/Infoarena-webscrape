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
int main() {
	long long a, b ,n;
	f >> n;
	for (int i = 0; i < n; ++i) {
		f >> a >> b;
		while (a != b) {
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		g << b<<"\n";
	}
	return 0;
}