#include <cstdio>

using namespace std;
int n, m, i, j, q, x1, y1, v[1030], x[1030], y[1030], a[1030][1030], b[1030][1030];
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(i=1;i<=n;i++)
        scanf("%d", &x[i]);
    for(i=1;i<=m;i++)
        scanf("%d", &y[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(x[i]==y[j])
            {
                a[i][j]=a[i-1][j-1]+1;
                b[i][j]=x[i];
            }
            else if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j];
            else a[i][j]=a[i][j-1];
    printf("%d\n", a[n][m]);
    q=0;
    x1=n;
    y1=m;
    while(q<a[n][m])
    {
        if(b[x1][y1]!=0)
        {
            v[++q]=b[x1][y1];
            x1--;
            y1--;
        }
        else if(a[x1][y1-1]>a[x1-1][y1]) y1--;
        else x1--;
    }
    for(i=q;i>=1;i--)
        printf("%d ", v[i]);
    return 0;
}
