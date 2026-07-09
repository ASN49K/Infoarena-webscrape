#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

const short nmax=1030;

int n, m;
int dinamica[nmax][nmax];
int u[nmax];
int v[nmax];
int raspunsuri[nmax];
int k=1;

void lcs()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(u[i]==v[j])
                dinamica[i][j]=dinamica[i-1][j-1]+1;
            else
                dinamica[i][j]=max(dinamica[i-1][j], dinamica[i][j-1]);
}
void create_rasp(int nr)
{
    bool gasit=false;
    int n_cautat, m_cautat;
    n_cautat=0;
    m_cautat=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(dinamica[i][j]==nr)
            {
                n_cautat=i;
                m_cautat=j;
                gasit=true;
                break;
            }
        }
        if(gasit==true)
            break;
    }
    raspunsuri[k++]=v[m_cautat];
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)
        scanf("%d", &u[i]);
    for(int i=1;i<=m;i++)
        scanf("%d", &v[i]);
    lcs();
    printf("%d\n", dinamica[n][m]);

    if(dinamica[n][m]==0)
        return 0;
    int nr=dinamica[n][m];
    while(nr)
    {
        create_rasp(nr);
        nr--;
    }
    for(int i=k-1;i>=1;i--)
        printf("%d ", raspunsuri[i]);
    printf("\n");

    return 0;
}
