#include <cstdio>
#define nmax 1025
#define max(a,b) (a>=b?a:b)

int n,m,x[nmax],y[nmax],sol[nmax][nmax];

void smax()
{   int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)if(x[i]==y[j])sol[i][j]=1+sol[i-1][j-1];else
    sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
    return;
}
void makesolution(int k,int h)
{   if(sol[k][h]>0)
    if(x[k]==y[h]){makesolution(k-1,h-1);printf("%d ",x[k]);} else
    {   if(sol[k][h]==sol[k-1][h])makesolution(k-1,h); else
        if(sol[k][h]==sol[k][h-1])makesolution(k,h-1); }
}

int main()
{   int i;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&x[i]);
    for(i=1;i<=m;i++)scanf("%d",&y[i]);
    smax();
    printf("%d\n",sol[n][m]);
    makesolution(n,m);printf("\n");
    return 0;
}
