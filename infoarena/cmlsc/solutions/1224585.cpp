#include <cstdio>

using namespace std;

int v[1100],v1[1100],sol[1100][1100],rez[1100];
char sol1[1100][1100];
int n,m,i,j,nr;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&v[i]);
    for(i=1;i<=m;i++) scanf("%d",&v1[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(sol[i-1][j]>sol[i][j-1])
            {
                sol[i][j]=sol[i-1][j];
                sol1[i][j]=1;
            }
            else
            {
                sol[i][j]=sol[i][j-1];
                sol1[i][j]=3;
            }
            if(v[i]==v1[j] && sol[i][j]<=sol[i-1][j-1])
            {
                sol[i][j]=sol[i-1][j-1]+1;
                sol1[i][j]=2;
            }
        }
    i=n;j=m;
    while(i && j)
        if(sol1[i][j]==1) i--;
        else if(sol1[i][j]==2)
        {
            rez[++nr]=v[i];
            i--;j--;
        }
        else j--;
    printf("%d\n",nr);
    for(i=nr;i;i--) printf("%d ",rez[i]);
    return 0;
}
