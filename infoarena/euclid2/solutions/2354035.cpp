#include <bits/stdc++.h>

using namespace std;

inline int gcd(int a, int b)  {
    int r = 0;
    while(b)  {
        int r = b;
        b = a % b;
        a = r;
    }
    return a;
}

int main()  {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
	int t, a, b;
	cin >> t;
	while(t--)  {
        cin >> a >> b;
        cout << gcd(a, b);
	}
	return 0;
}
