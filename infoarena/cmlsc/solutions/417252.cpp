#include<stdio.h>
#define maxim(a,b) (a>b ? a : b)

int n,m,d[1031][1031];
int a[1031],b[1031],sol[1031];

int main ()
{
    int i,j,x,y,k;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
                continue;
            }
            d[i][j]=maxim(d[i-1][j],d[i][j-1]);            
        }
        
    printf("%d\n",d[n][m]);
    x=n; y=m; k=d[n][m];
    while (k)
    {
        if (a[x] == b[y])
            sol[k--] = a[x], x--, y--;
        else
        {
            if (d[x-1][y] < d[x][y-1])
                --y;
            else
                --x;
        }
    }

    for(i=1;i<=d[n][m];i++)
        printf("%d ", sol[i]);
    printf("\n");
    
    return 0;
}



