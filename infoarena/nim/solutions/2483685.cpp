#include <iostream>
#include <cstdio>
#include <climits>
#include <climits>
#include <vector>
#include <assert.h>
#define MAXN 20
#define maxim 10000000

using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int n, x; cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        int xorsum = 0;

        for(int j = 0; j < x; j++)
        {
            xorsum ^= x;
        }

        if(xorsum) cout << "DA\n";
        else cout << "NU\n";
    }
}
