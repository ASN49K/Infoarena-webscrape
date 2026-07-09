#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
const long long LLINF = 1LL << 62;
const int mod = 1000000007;

int T, n, sum, x;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        sum = 0;
        while(n--)
        {
            scanf("%d", &x);
            sum ^= x;
        }
        if(sum == 0)
            printf("NU\n");
        else
            printf("DA\n");
    }

    return 0;
}
