#include <bits/stdc++.h>

using namespace std;

inline int gcd(int a, int b)  {
    int r = 0;
    while(b)  {
        int r = b;
        b = a % b;
        a = b;
    }
    return a;
}

int main()  {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
	int a, b;
	cout << gcd(a, b);
	return 0;
}
