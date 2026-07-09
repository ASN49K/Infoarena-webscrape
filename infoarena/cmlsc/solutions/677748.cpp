/*
    Solutie cu memorie O(N^2).
    Solutia din 23 oct 2011 e cu memorie O(N).
    Vezi si sursa 16 feb 2011.
*/

#include <cstdio>

const int N_MAX = 1030;
const int M_MAX = 1030;

struct pct
{
    int i,j;
};

int v1[N_MAX],v2[M_MAX],n,m;
int d[N_MAX][M_MAX]; //d[i][j] -> lungimea celui mai lung subsir comun dintre primele i din primul vector si j din al doilea

inline int max(int a, int b)
{
    return (a>b)?a:b;
}

void citeste()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; ++i)
        scanf("%d",&v1[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d",&v2[i]);
}

void dinamica()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            d[i][j] = (v1[i] == v2[j])?d[i-1][j-1] + 1:max(d[i-1][j],d[i][j-1]);
}

void scrie_sir(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (v1[i] == v2[j])
    {
        scrie_sir(i-1,j-1);
        printf("%d ",v1[i]);
    }
    else
        if (d[i-1][j] > d[i][j-1])
            scrie_sir(i-1,j);
        else
            scrie_sir(i,j-1);
}

void scrie()
{
    printf("%d\n",d[n][m]);
    scrie_sir(n,m);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citeste();
    dinamica();
    scrie();
    return 0;
}
