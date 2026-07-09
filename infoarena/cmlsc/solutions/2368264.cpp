#include <stdio.h>
#include <iostream>

using namespace std;

#define N 1025


int x1[N],x2[N],a[N][N],n,m,sol[N],poz;


int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&n,&m);
    int i,j;
    for(i=1;i<=n;i++)
        scanf("%d",&x1[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&x2[i]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(x1[i]==x2[j])
            {
                a[i][j]=1+a[i-1][j-1];
            }
            else
            {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    for(i=n,j=m;a[i][j];)
    {
        if (x1[i] == x2[j])
            {
                ++poz;
                sol[poz]= x1[i];
                --i;--j;
            }
        else
            if (a[i-1][j] < a[i][j-1])
                --j;
            else
                --i;
    }
    printf("%d\n",poz);
    for(i=poz;i>0;--i)
        printf("%d ",sol[i]);
    return 0;
}
