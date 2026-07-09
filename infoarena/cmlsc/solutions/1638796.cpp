#include <cstdio>
#include <algorithm>

using namespace std;

pair<int,int> tata[1100][1100];
int d[1100][1100],sol[1100],v1[1100],v2[1100];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n,m,nr=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&v1[i]);
    for(int i=1;i<=m;i++) scanf("%d",&v2[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(d[i-1][j]>d[i][j-1]) {d[i][j]=d[i-1][j];tata[i][j]={i-1,j};}
            else {d[i][j]=d[i][j-1];tata[i][j]={i,j-1};}
            if(v1[i]==v2[j] && d[i-1][j-1]+1>d[i][j]) {d[i][j]=d[i-1][j-1]+1;tata[i][j]={i-1,j-1};}
        }
    int i=n,j=m;
    while(i && j)
    {
        if(tata[i][j].first!=i && tata[i][j].second!=j) sol[++nr]=v1[i];\
        int a=tata[i][j].first,b=tata[i][j].second;
        i=a;j=b;
    }
    printf("%d\n",nr);
    for(int i=nr;i;i--) printf("%d ",sol[i]);
    return 0;
}
