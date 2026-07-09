#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int gcd1(int a, int b)
{
    while(a != b)
    {
        if(a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }

    return a;
}

int gcd2(int a, int b)
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

int gcd3(int a, int b)
{
    if(b == 0) return a;

    gcd3(b, a % b);
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

        cout << gcd2(a, b);
    }

    //auto e = clock();

    //auto t = 1000.0 * (e - s) / CLOCKS_PER_SEC;

    //cout << "" << t << "ms" << endl;
}
