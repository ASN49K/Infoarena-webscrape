#include <bits/stdc++.h>
using namespace std;
int n,m,a[2001],b[2001],v[2001][2001],r,rez[2001];
void mat()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%d ",v[i][j]);
        printf("\n");
    }
}
void date()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
}
int main()
{
    date();
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
            if(a[i] == b[j])
                v[i][j] = v[i-1][j-1]+1;
            else
                v[i][j] = max(v[i-1][j],v[i][j-1]);
    }
    printf("%d\n",v[n][m]);
    int i=n,j=m;

    while(i && j)
    {
        if(a[i] == b[j])
        {
            rez[++r] = a[i];
            i--;
            j--;
        }
        else if(v[i][j-1] < v[i-1][j]) i--;
        else j--;
    }
    for(int i=r;i>=1;i--)
            printf("%d ",rez[i]);


    return 0;
}
