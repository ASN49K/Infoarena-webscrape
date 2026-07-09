#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int a, b;

int cmmdc(int a, int b)
{
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	int n = 0; in >> n;
	for (int i = 1; i <= n; ++i) {
		in >> a >> b;
		out << cmmdc(a, b);
	}
}