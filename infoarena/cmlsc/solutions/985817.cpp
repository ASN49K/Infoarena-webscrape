#include <cstdio>

using namespace std;

int n,m,aux,i,a[1100],b[1100],d[1024][1024],j,sol[2000],k;

int maxim(int x,int y)
{
    if(x>y)
    return x;
    return y;
}


int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d ",&a[i]);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d ",&b[i]);
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            d[i][j]=maxim(d[i-1][j],d[i][j-1]);

        }
    }
    printf("%d\n",d[n][m]);
    k=0;
    while(i && j)
    {
        if(a[i]==b[j])
        {
               k++;
            sol[k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i][j-1]>d[i-1][j])
            {
                j--;
            }
            else i--;
        }
    }

    for(i=k;i>1;i--)
    {
        printf("%d ",sol[i]);
    }

}
