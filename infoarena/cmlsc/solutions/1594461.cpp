#include <iostream>
#include <cstdio>

using namespace std;

int max(int a, int b)
{
    if(a>b) return a;
    return b;
}

short a[1025], b[1025], O[1025][1025], sir[1025], n, m, nr;
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    for(int i=1; i<=m; i++)
        scanf("%d", &b[i]);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j]) O[i][j]=1+O[i-1][j-1];
            else O[i][j]=max(O[i-1][j], O[i][j-1]);
    int i=n, j=m;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            sir[++nr] = a[i];
            i--;
            j--;
        }
        else if(O[i-1][j] < O[i][j-1])
            j--;
        else
            i--;
    }
    printf("%d\n", nr);
    for(int i=nr; i>0; i--)
        printf("%d ", sir[i]);
    return 0;
}
