#include <stdio.h>
#include <algorithm>
using namespace std;
#define Max 100005

int v[Max], n, ant[Max], dp[Max], L[Max];


void read()
{
    int i;

    scanf("%d",&n);

    for(i = 1; i <= n; i++)
        scanf("%d",&v[i]);
}


void afis(int poz)
{

    if(poz == 0)
        return;

    afis(ant[poz]);

    printf("%d ", v[poz]);
}


int findb(int st, int dr, int i)
{
    int mid;

    if(st > dr)
        return 0;

    mid = (st + dr)/2;

    if(v[L[mid]] < v[i])

        return max(mid, findb(mid+1, dr, i));
    else
        return findb(st, mid-1, i);
}


void solve()
{
    int i, j, jmax, x, maxd = 0, imd;

    v[0] = 2000000000;
    dp[1] = 1;
    L[1] = 1;

    for(i = 2; i <= n; i++)
    {
        x = findb(1, n, i);
        dp[i] = x + 1;

        if(x != 0)
         ant[i] = L[x];

        if(v[L[dp[i]]] > v[i])
            L[dp[i]] = i;

        if(maxd < dp[i])
        {
            maxd = dp[i];
            imd = i;
        }
    }

    printf("%d\n",maxd);

    afis(imd);

}


int main()
{
    freopen("scmax.in","r",stdin);
    freopen("scmax.out","w",stdout);

    read();

    solve();

    return 0;
}

