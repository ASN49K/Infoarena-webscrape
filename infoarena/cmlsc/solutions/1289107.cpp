#include <iostream>
#include <cstdio>
#include <algorithm>
#define nmax 1030

using namespace std;

int n, m, a1[nmax], a2[nmax], b[nmax][nmax];

void citire()
{
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++)
        scanf("%d ", &a1[i]);
    for (int i=1; i<=m; i++)
        scanf("%d ", &a2[i]);
}

void drum(int i, int j)
{
    if (i<=0 && j<=0)
        return;
    if (a1[i]==a2[j])
    {
        drum(i-1, j-1);
        printf("%d ", a1[i]);
        return;
    }
    if (b[i][j-1]>=b[i-1][j])
        drum(i, j-1);
    else
        drum(i-1, j);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    citire();
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            b[i][j]=max(b[i-1][j], b[i][j-1]);
            if (a1[i]==a2[j])
                b[i][j]=max(b[i-1][j], b[i][j-1])+1;
        }
    printf("%d\n", b[n][m]);
    drum(n, m);

    return 0;
}
