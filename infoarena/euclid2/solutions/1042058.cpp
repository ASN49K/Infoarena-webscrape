#include <iostream>
#include <cstdio>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main(int argc, char ** argv)
{
	int T, A, B;

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	cin >> T;
	for(; T; T--) {
		cin >> A >> B;
		cout << GCD(A, B);
	}
	
	return 0;
}