#include <bits/stdc++.h>
#define maxN 10002
using namespace std;

FILE *fin = freopen("nim.in", "r", stdin);
FILE *fout = freopen("nim.out", "w", stdout);

int t, n, v[maxN];

int ans;

int main()
{
    scanf("%d\n", &t);
    while (t --)
    {
        scanf("%d", &n);
        ans = 0;
        for (int i = 1; i <= n; ++ i)
        {
            scanf("%d", &v[i]);
            ans ^= v[i];
        }
        if (ans)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
