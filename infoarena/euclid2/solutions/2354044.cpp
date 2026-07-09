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
	scanf("%d", &t);
	for(int i = 1;i <= t;i++)  {
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
	}
	return 0;
}
