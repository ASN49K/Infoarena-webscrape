#include<stdio.h>
int i,n,m,x[1030],y[1030],d[1030],k,h;
int lcs[1030][1030];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&y[i]);
    for(k=1; k<=n; k++)
        for(h=1; h<=m; h++)
            if(x[k]==y[h])
                lcs[k][h]=1+lcs[k-1][h-1];
            else if(lcs[k-1][h]>lcs[k][h-1])
                lcs[k][h]=lcs[k-1][h];
            else
                lcs[k][h]=lcs[k][h-1];
    printf("%d\n",lcs[n][m]);
    for(i=0,k=n,h=m;lcs[k][h];)
        if(x[k]==y[h])
        {
            d[i++]=x[k]; k--; h--;
        }
        else
            if(lcs[k][h]==lcs[k-1][h])
                k--;
            else
                h--;
    for(k=i-1;k>=0;k--)
        printf("%d ",d[k]);
	return 0;
}
