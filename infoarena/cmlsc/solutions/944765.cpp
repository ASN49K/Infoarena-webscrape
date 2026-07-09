#include<stdio.h>
#include<algorithm>
using namespace std;
int s[1025][1025],v1[1025],v2[1025],sol[1025];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,i,j,nr;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&v1[i]);
    for(j=1;j<=m;j++)
        scanf("%d",&v2[j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
                s[i][j]=s[i-1][j-1]+1;
            else
                s[i][j]=max(s[i-1][j],s[i][j-1]);
        }
    i=n;j=m;
    nr=s[n][m];
    printf("%d\n",nr);
    while(i>=1&&j>=1)
    {
        if(v1[i]==v2[j])
        {
            sol[--nr]=v1[i];
            i--;j--;
        }
        else
        {
            if(s[i-1][j]>s[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(i=0;i<s[n][m];i++)
        printf("%d ",sol[i]);
    return 0;
}
