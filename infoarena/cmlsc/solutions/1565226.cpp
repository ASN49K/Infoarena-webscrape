#include<cstdio>
#include<algorithm>
using namespace std;
struct eu{int x,y,nr;};
eu a[1025][1025];
int v[1025],vc[1025],i,j,n,m,k,vec[1025];
int main ()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d%d",&n,&m);
for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
for(i=1;i<=m;i++)
    scanf("%d",&vc[i]);
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        {
        if(v[i]!=vc[j])
            {
            if(a[i-1][j].nr>a[i][j-1].nr)
                {
                a[i][j].nr=a[i-1][j].nr;
                a[i][j].x=i-1;
                a[i][j].y=j;
                }
            else
                {
                a[i][j].nr=a[i][j-1].nr;
                a[i][j].x=i;
                a[i][j].y=j-1;
                }
            }
        else
            {
            if(a[i-1][j-1].nr+1>a[i-1][j].nr&&a[i-1][j-1].nr+1>a[i][j-1].nr)
                {
                a[i][j].nr=a[i-1][j-1].nr+1;
                a[i][j].x=i-1;
                a[i][j].y=j-1;
                }
            else
                if(a[i-1][j].nr>a[i][j-1].nr)
                    {
                    a[i][j].nr=a[i-1][j].nr;
                    a[i][j].x=i-1;
                    a[i][j].y=j;
                    }
                else
                    {
                    a[i][j].nr=a[i][j-1].nr;
                    a[i][j].x=i;
                    a[i][j].y=j-1;
                    }
            }
        }
printf("%d\n",a[n][m].nr);
int cate=0;
while(a[n][m].x!=0&&a[n][m].y!=0&&a[n][m].nr!=0)
    {
    if(a[n][m].nr-a[a[n][m].x][a[n][m].y].nr==1)
        vec[++cate]=v[n];
    int n1=n;
    n=a[n][m].x;
    m=a[n1][m].y;
    }
if(a[n][m].nr-a[a[n][m].x][a[n][m].y].nr==1)
    vec[++cate]=v[n];
for(i=cate;i>=1;i--)
    printf("%d ",vec[i]);
return 0;
}
