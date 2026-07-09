#include<cstdio>
using namespace std;
inline int max(int a,int b)
{
    return (a>b ?a:b);
}
int s1[1025],s2[1025],val[1025];
int d[1025][1025];
int main()
{
    int n,m,i,l,j,k=0;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&s1[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&s2[i]);

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(s1[i]==s2[j])
            {
                d[i][j]=d[i-1][j-1]+1;
                val[k++]=s1[i];
            }
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);

    printf("%d\n",d[n][m]);
    for(i=0;i<k;i++)
       printf("%d ",val[i]);
    return 0;
}
