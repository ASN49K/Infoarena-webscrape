#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
    int t;

    while(b)
    {
        t = b;

        b = a % b;

        a = t;
    }

    return a;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int T, a, b;

    //auto s = clock();

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d %d", &a, &b);
        //gcd(a, b);
        printf("%d\n", gcd(a, b));
    }

    //auto e = clock();

    //auto t = 1000.0 * (e - s) / CLOCKS_PER_SEC;

    //cout << "" << t << "ms" << endl;
}
