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
    int q[nmax];
    q[0]=0;
    while (i>0 && j>0)
    {
        if (a1[i]==a2[j])
        {
            q[++q[0]]=a1[i];
            i--;
            j--;
        }
        else if (b[i-1][j]>b[i][j-1])
            i--;
        else
            j--;
    }
    for (int k=q[0]; k>=1; k--)
        printf("%d ", q[k]);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    citire();
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            b[i][j]=max(max(b[i-1][j], b[i][j-1]), b[i-1][j-1]+(a1[i]==a2[j]));
    printf("%d\n", b[n][m]);
    drum(n, m);

    return 0;
}
