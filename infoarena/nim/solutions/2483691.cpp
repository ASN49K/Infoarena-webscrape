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

    int n, x, y; cin >> n;
    int xorsum;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        xorsum = 0;

        for(int j = 0; j < x; j++)
        {
            scanf("%d", &y);
            xorsum ^= y;
        }

        if(xorsum) printf("DA\n");
        else printf("NU\n");
    }
}
