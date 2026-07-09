#include <iostream>
#include <cstdio>
using namespace std;

long cmmdc(long a, long b)
{
    if(b == 0)
        return a;
    return cmmdc(b, a%b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    long a, b;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cout << cmmdc(a, b) << '\n';
    }

    return 0;
}
