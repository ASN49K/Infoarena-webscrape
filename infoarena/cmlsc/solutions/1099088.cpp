#include <iostream>
#include <stdio.h>

using namespace std;

FILE *f1=freopen("cmlsc.in", "r", stdin);
FILE *f2=freopen("cmlsc.out", "w", stdout);
int n, m, a[1025], b[1025], l[1025][1025], dr[1025];

void cit()
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for (int j=0; j<m; j++)
        scanf("%d", &b[j]);
}

int lmax()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            int q=0;
            if (a[i-1]==b[j-1])
                q=1;
            l[i][j]=max(max(l[i-1][j], l[i][j-1]), l[i-1][j-1]+q);
        }
    return l[n][m];
}

void drum()
{
    int i=n, j=m;
    while (i && j)
    {
        if (a[i-1]==b[j-1])
        {
            dr[++dr[0]]=a[i-1];
            i--;
            j--;
        }
        else if (l[i-1][j]>l[i][j-1])
            i--;
        else
            j--;
    }
    for (int i=dr[0]; i>=1; i--)
        printf("%d ", dr[i]);
}

void sol()
{
    printf("%d\n", lmax());
    drum();
}

int main()
{
    cit();
    sol();
    return 0;
}
