#include <cstdio>
#include <algorithm>
using namespace std;

int a[1030];
int b[1030];
int sol[1030][1030];
int n,m;

void read()
{
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for (int i=1; i<=m; i++)
        scanf("%d",&b[i]);
}

void solve()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i] == b[j])
                sol[i][j] = sol[i-1][j-1]+1;
            else
                sol[i][j] = max(sol[i-1][j], sol[i][j-1]);
}

void print(int i, int j)
{
    if (sol[i][j] == 0)
        return;
    if (sol[i][j] == sol[i-1][j-1]+1 && a[i] == b[j])
    {
        print(i-1,j-1);
        printf("%d ",a[i]);
    }
    else
    if (sol[i][j] == sol[i-1][j])
        print(i-1,j);
    else
        print(i,j-1);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    read();
    solve();
    printf("%d\n",sol[n][m]);
    print(n,m);
    return 0;
}
