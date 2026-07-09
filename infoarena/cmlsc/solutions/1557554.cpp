#include<cstdio>
int a[1050],b[1050],di[1050][1050],ai[1050][1050],aj[1050][1050],sl[1050];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,i,j,l,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
    scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j])
    {
        di[i][j]=di[i-1][j-1]+1;
        ai[i][j]=i-1;
        aj[i][j]=j-1;
    }
    else
    {
        if(di[i-1][j]>di[i][j-1])
        {
            di[i][j]=di[i-1][j];
            ai[i][j]=i-1;
            aj[i][j]=j;
        }
        else
        {
            di[i][j]=di[i][j-1];
            ai[i][j]=i;
            aj[i][j]=j-1;
        }
    }l=0;
    for(i=di[n][m];i>=1;i--)
    {
        while(ai[n][m]==n || aj[n][m]==m)
        {
            x=ai[n][m];
            y=aj[n][m];
            n=x;
            m=y;
        }
       l++;
        sl[l]=a[n];
         x=ai[n][m];
            y=aj[n][m];
            n=x;
            m=y;
    }
    printf("%d\n",l);
    for(i=l;i>=1;i--)
    printf("%d ",sl[i]);
    return 0;
}
