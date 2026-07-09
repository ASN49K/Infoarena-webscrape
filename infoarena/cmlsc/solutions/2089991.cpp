#include <iostream>
#include <stdio.h>
using namespace std;

int a[1025], b[1025], d[260][260];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
        scanf("%d ", &a[i]);

    for(int i=1; i<=m; i++)
        scanf("%d ", &b[i]);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }

    cout<<d[n][m]<<endl;

    int i, j, c=d[n][m], r[1025];
    i=n;
    j=m;
    while(i>=1 && j>=1 && c>0)
    {
        if(a[i]==b[j])
        {
            r[c--]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j]>d[i][j-1])
                i--;
            else
                j--;
        }

    }

    for(i=1; i<=d[n][m]; i++)
        printf("%d ",r[i]);


    return 0;
}
