#include <cstdio>
#define MAX(a,b) a>b?a:b
#define lim 1025
using namespace std;

int n, m;
int s1[lim];
int s2[lim];
int mat[lim][lim];
void citire()
{
    scanf("%d %d",&n,&m);
    for(int i =1 ; i <= n ; i++)
        scanf("%d",&s1[i]);
    for(int j =1 ; j <= m; j++)
        scanf("%d",&s2[j]);
}

void solve()
{
    for(int i =1 ;i <= n; i++)
        for(int j=1; j<=m;j++)
        {
            if(s1[i] == s2[j])
            {
                mat[i][j] = 1 + mat[i-1][j-1];
            }
            else
                mat[i][j] = MAX(mat[i-1][j],mat[i][j-1]);
        }
}

void afisare(int i, int j)
{
    if(i == 0 || j == 0)
        return;

    if(s1[i] == s2[j])
    {
        afisare(i-1,j-1);
        printf("%d ",s1[i]);
        return;
    }

    if(mat[i-1][j] > mat[i][j-1])
        afisare(i-1,j);
    else
        afisare(i,j-1);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    citire();
    solve();
    printf("%d\n",mat[n][m]);
    afisare(n,m);
    return 0;
}
