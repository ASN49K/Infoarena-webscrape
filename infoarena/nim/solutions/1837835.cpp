#include <bits/stdc++.h>
FILE *fin  = freopen("nim.in", "r", stdin);
FILE *fout = freopen("nim.out", "w", stdout);

using namespace std;
int T, N, xorSum;
int main()
{
    int x;
    scanf("%d", &T);
    while(T --)
    {
        xorSum = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; ++ i)
        {
            scanf("%d", &x);
            xorSum ^= x;
        }
        if(xorSum == 0)
            printf("NU\n");
        else printf("DA\n");
    }
    return 0;
}
