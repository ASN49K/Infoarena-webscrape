#include <cstdio>
#include <algorithm>

using namespace std;

int v1[1030],v2[1030],d[1030][1030],sol[1030];
pair<int,int> tata[1030][1030];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&v1[i]);
    for(int i=1;i<=m;i++) scanf("%d",&v2[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            d[i][j]=d[i-1][j];
            tata[i][j]={i-1,j};
            if(d[i][j-1]>d[i][j])
            {
                d[i][j]=d[i][j-1];
                tata[i][j]={i,j-1};
            }
            int c=0;
            if(v1[i]==v2[j]) c=1;
            if(d[i-1][j-1]+c>d[i][j])
            {
                d[i][j]=d[i-1][j-1]+c;
                tata[i][j]={i-1,j-1};
            }
        }
    printf("%d\n",d[n][m]);
    int l=0;
    while(n!=0 && m!=0)
    {
        if(v1[n]==v2[m]) sol[++l]=v1[n];
        int a=tata[n][m].first,b=tata[n][m].second;
        n=a;m=b;
    }
    for(int i=l;i>=1;i--) printf("%d ",sol[i]);
    return 0;
}
