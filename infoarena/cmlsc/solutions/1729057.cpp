#include <cstdio>

using namespace std;

int v[1050],v1[1050],v3[1050];
int d[1050][1050],v2[1050][1050];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,a,b,r=0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&v1[i]);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            if(v[i]==v1[j]) {d[i][j]=d[i-1][j-1]+1;v2[i][j]=1;}
            if(d[i][j-1]>d[i][j]) {d[i][j]=d[i][j-1];v2[i][j]=2;}
            if(d[i-1][j]>d[i][j]) {d[i][j]=d[i-1][j];v2[i][j]=3;}
        }
    printf("%d\n",d[m][n]);
    a=m;
    b=n;
    while(a>0 && b>0)
    {
        if(v2[a][b]==1) {r++;v3[r]=v[a];a--;b--;}
        else if(v2[a][b]==2) b--;
        else if(v2[a][b]==3) a--;
    }
    for(int i=r;i>=1;i--)
        printf("%d ",v3[i]);
    return 0;
}
