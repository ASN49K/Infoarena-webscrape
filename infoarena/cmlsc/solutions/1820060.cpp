#include <stdio.h>
#define nr 1024
using namespace std;
int n, m, v[nr+1], w[nr+1], a[nr+1][nr+1], sol[nr+1], k1;
int max(int a, int b)
{
    if(a<b) return b;
    return a;
}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d", &v[i]);
    for(int i=1; i<=m; i++)
        scanf("%d", &w[i]);
    a[0][0]=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            {
                if(v[i]==w[j])
                    a[i][j]=a[i-1][j-1]+1;
                else
                    a[i][j]=max(a[i][j-1], a[i-1][j]);
            }
    printf("%d\n", a[n][m]);
    int k=n, l=m;
    while(k>0 and l>0)
    {
        if(v[k]==w[l])
            {
                ++k1;
                sol[k1]=w[l];
                --k;
                --l;
            }
        else
        {
            if(a[k-1][l]>a[k][l-1])
                k--;
            else
                l--;
        }
    }
    for(int i=k1; i>=1; i--)
        printf("%d ", sol[i]);
    printf("\n");
    return 0;
}
