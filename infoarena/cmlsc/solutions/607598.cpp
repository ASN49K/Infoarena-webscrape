#include<stdio.h>
int a[1030],b[1030],d[1030],s[1030][1030];
inline int din(int i,int j)
{
    if(a[i]==b[j])
        return(s[i-1][j-1]+1);
    return (s[i][j-1]>s[i-1][j]?s[i][j-1]:s[i-1][j]);
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int m,n,i,j,t;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            s[i][j]=din(i,j);
    printf("%d\n",s[m][n]);
    t=s[m][n]+1;
    for(i=m,j=n;i;)
        if(a[i]==b[j])
        {
            d[--t]=a[i];
            i--;
            j--;
        }
        else
        if(s[i-1][j]>s[i][j-1])
            i--;
        else
        j--;
    for(i=1;i<=s[m][n];i++)
    printf("%d ",d[i]);
    return 0;
}
