#include <bits/stdc++.h>
using namespace std;
int n,m,a[1031],b[1031],d[1031][1031],k,rez[1031];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int j=1;j<=m;j++)
        scanf("%d",&b[j]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = max(d[i-1][j],d[i][j-1]);

    //int i=n,j=m;
    for(int i=n,j=m;i;)
    {
        if(a[i]==b[j])
        {
            rez[++k]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j] < d[i][j-1]) j--;
        else i--;
    }
    printf("%d\n",k);
    for(int i=k;i>=1;i--)
        printf("%d ",rez[i]);
    return 0;

}
