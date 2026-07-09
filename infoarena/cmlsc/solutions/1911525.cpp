#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int sir1[1030];
int sir2[1030];
int mat[1030][1030];
int sol[1030];

void citire()
{
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &sir1[i + 1]);
    }

    for(int i = 0; i < m; i++)
    {
        scanf("%d", &sir2[i + 1]);
    }
}

void cmlsc()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(sir1[i] == sir2[j])
            {
                mat[i][j] = mat[i - 1][j - 1] + 1;
            }
            else
            {
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            }
        }
    }

    printf("%d\n", mat[n][m]);

    int l = n;
    int c = m;
    int nr = mat[n][m];
    int nrx = 0;

    while(nr > 0)
    {
        if(sir1[l] == sir2[c])
        {
            sol[nrx] = sir1[l];
            nrx++;
            l--;
            c--;
            nr--;
        }
        else
        {
            if(mat[l - 1][c] == nr && l > 0)
            {
                l--;
            }
            else if(mat[l][c - 1] == nr && c > 0)
            {
                c--;
            }
        }
    }

    for(int i = nrx - 1; i >= 0; i--)
    {
        printf("%d ", sol[i]);
    }
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    citire();
    cmlsc();

    return 0;
}
