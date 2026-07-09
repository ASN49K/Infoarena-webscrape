#include<stdio.h>
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
int a[1030][1030],n,m,i,j,s1[1030],s2[1030],sol[1030],k;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&s1[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&s2[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(s1[i]==s2[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=MAX(a[i-1][j],a[i][j-1]);
    printf("%d\n",a[n][m]);
    for(i=n , j=m; i && j ; )
        if(s1[i]==s2[j])
        {
            sol[k++]=s1[i];
            i--;
            j--;
        }
        else
            if(a[i][j-1]>a[i-1][j])
                j--;
            else
                i--;
    for(i=k-1; i>=0; i--)
        printf("%d ",sol[i]);
    return 0;
}
