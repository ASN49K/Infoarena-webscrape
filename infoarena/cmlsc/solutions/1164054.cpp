#include <cstdio>


int m,n,a[1024],b[1024],d[1024][1024],sir[1024],numar;


int maxim(int x, int y)
{
    if(x>y)
        return x;
    return y;
}



int main(void)
{

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=1+d[i-1][j-1];
            }
            else
            {
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);
            }
        }
    }
    for(int i=m,j=n;i;)
    {
        if (a[i]==b[j])
        {
            numar++;
            sir[numar]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
        }
    }
    printf("%d\n",numar);
    for(int i=numar;i>=1;i--)
    {
        printf("%d ",sir[i]);
    }
    return 0;
}
