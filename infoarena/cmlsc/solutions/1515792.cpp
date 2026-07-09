#include <cstdio>

using namespace std;

int mat[1030][1030],v1[1030],v2[1030],sol[1030];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int n,m,i,j,maxx;

    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++) scanf("%d",&v1[i]);
    for(i=1;i<=m;i++) scanf("%d",&v2[i]);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j]) mat[i][j]=mat[i-1][j-1]+1;
            else
            {
                if(mat[i-1][j]>mat[i][j-1]) maxx=mat[i-1][j];
                else maxx=mat[i][j-1];

                mat[i][j]=maxx;
            }
        }
    }

    i=n;
    j=m;

    int cnt=0;

    while(mat[i][j]!=0)
    {
        if(v1[i]==v2[j])
        {
            cnt++;
            sol[cnt]=v1[i];
            i--;
            j--;
        }
        else
        {
            if(mat[i-1][j]==mat[i][j]) i--;
            else j--;
        }
    }

    printf("%d\n",cnt);

    for(i=cnt;i>=1;i--) printf("%d ",sol[i]);

    return 0;
}
