#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
#define endl '\n'
int main()
{
	int a, b;
	cin >> a >> b;
	while (a != b) {
		if (a > b)a = a - b;
		else b = b - a;
	}
	cout << a;
}