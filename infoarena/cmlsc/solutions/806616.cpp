#include<stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int n,m,a[1050],b[1050],d[1050][1050],sol[1050],rez;
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int i,j;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    for(i=m,j=n;i>0;)
        if(a[i]==b[j])
            sol[++rez]=a[i],i--,j--;
        else if(d[i-1][j]<d[i][j-1])
				 j--;
			 else
				 i--;
    printf("%d\n",rez);
    for(i=rez;i>=1;i--)
        printf("%d ",sol[i]);
	printf("\n");
    return 0;
}
