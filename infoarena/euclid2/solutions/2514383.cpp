#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
struct euclid { int a, b; }v[100001];

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
	for (int i = 1; i <= n; ++i)
		in >> v[i].a >> v[i].b;
	for (int i = 1; i <= n; ++i) out << cmmdc(v[i].a, v[i].b) << "\n";
}