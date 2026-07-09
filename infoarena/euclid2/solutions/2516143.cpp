#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b;
        c = gcd(a, b);
        cout << c << "\n";
    }
}
