#include <cstdio>
#include <algorithm>

using namespace std;

int m, n, a[1050], b[1050], mat[1050][1050], rez[1050];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d",&n,&m);
    int i,j,q;
    for(i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    for(i = 1; i <= m; i++)
        scanf("%d",&b[i]);

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);

    printf("%d\n",mat[n][m]);
    i=n;j=m;q=mat[n][m];
    while(q)
    {
        if(a[i]==b[j])
        {
            rez[--q]=a[i];
        }
        if(mat[i][j-1]>mat[i-1][j])
            j--;
        else
            i--;
    }

    for(i=0;i<mat[n][m];i++)
        printf("%d ",rez[i]);

    return 0;
}
