#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int n, m;
int sir1[1030];
int sir2[1030];
int mat[1030][1030];

void citire()
{
    scanf("%d %d\n", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &sir1[i]);
    }

    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &sir2[i]);
    }
}

void umplere()
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
}

void afisare()
{
    int nr = mat[n][m];

    deque<int> raspuns;

    for(int i = n; i > 0; i--)
    {
        for(int j = m; j > 0; j--)
        {
            if(sir1[i] == sir2[j])
            {
                if(mat[i][j] == nr)
                {
                    nr--;
                    raspuns.push_back(sir1[i]);
                }
            }
        }
    }

    for(int i = raspuns.size() - 1; i >= 0; i--)
    {
        printf("%d ", raspuns[i]);
    }
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    citire();
    umplere();
    afisare();

    return 0;
}
