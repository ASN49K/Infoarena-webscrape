#include <bits/stdc++.h>

using namespace std;

int N, a, b;

int GCD(int a, int b)
{
    int r = b;
    while (a % b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    ios_base::sync_with_stdio(false);

    cin >> N;
    while (N--)
    {
        cin >> a >> b;
        cout << GCD(a, b) << "\n";
    }
    return 0;
}
