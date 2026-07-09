#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int dp[1030][1030], a[1030], b[1030], c[1030];

void citire()
{
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; ++i)
        scanf("%d", &a[i]);
    for(int j=1; j<=m; ++j)
        scanf("%d", &b[j]);
}

void form_mat()
{
    for(int i=1; i<=m; ++i)
    {
        for(int j=1; j<=n; ++j)
            if(a[j] == b[i])
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
}

void afis()
{
    printf("%d\n", dp[m][n]);
    int nr = dp[m][n];
    int i = m, j = n;

    while(dp[i][j] != 0 && i >= 1 && j >= 1)
    {
        if(a[j] == b[i])
            {c[nr--] = a[j]; i--; j--;}
        else if(i > 1)
            i--;
        else j--;
    }

    for(int k=1; k<=dp[m][n]; ++k)
        printf("%d ", c[k]);
}


int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    citire();
    form_mat();
    afis();


    return 0;
}
