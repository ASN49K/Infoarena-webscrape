#include <bits/stdc++.h>

using namespace std;

int euclid(int a, int b)
{
        if(b == 0) return 0;
        int r = a % b;
        while(r != 0)
        {
                a = b;
                b = r;
                r = a % b;
        }
        return b;
}

int T, a, b;

int main()
{
        freopen("euclid2.in", "r", stdin);
        freopen("euclid2.out", "w", stdout);
        scanf("%d", &T);
        for(int i = 1; i <= T; ++i)
        {
                scanf("%d %d", &a, &b);
                printf("%d\n", euclid(a, b));
        }
        return 0;
}
