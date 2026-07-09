#include <cstdio>
using namespace std;
int s1[1025],s2[1025],a[1025][1025],pr[1025];
int mx(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int m,n,i,j,cnt=0,p1,p2;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&s1[i]);
    for(j=1;j<=m;j++)
        scanf("%d",&s2[j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(s1[i]==s2[j])
                a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=mx(a[i-1][j],a[i][j-1]);
        }
    printf("%d\n",a[n][m]);
    p1=n,p2=m;
    while(cnt<a[n][m])
    {
        if(s1[p1]==s2[p2])
            cnt++,pr[cnt]=s1[p1],p1--,p2--;
        else
        {
            if(a[p1-1][p2]>a[p1][p2-1])
                p1--;
            else p2--;
        }
    }
    for(i=cnt;i>=1;i--)
        printf("%d ",pr[i]);
    return 0;
}
