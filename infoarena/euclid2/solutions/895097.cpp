#include <cstdio>
using namespace std;
int x[5000];
int main()
{
    freopen("culori.in","r",stdin);
    freopen("culori.out","w",stdout);
    int i,j,n,a,b,c,k,nr;
    scanf("%d",&n);
    if(n%2)
    {
        x[1]=4;
        x[2]=1;
        k=n/2;
        nr=2;
    }
    else
    {
        x[1]=8;
        k=n/2;
        nr=1;
    }
    for(j=1;j<=k-1;j++)
    {
        c=0;
        for(i=1;i<=nr;i++)
        {
            a=(x[i]*3+c)%10;
            b=(x[i]*3+c)/10;
            c=b;
            x[i]=a;
        }
        if(c>0){nr++;x[nr]=c;}
    }
    for(i=nr;i>=1;i--)printf("%d",x[i]);
    return 0;
}
