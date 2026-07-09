#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int sir1[1030];
int sir2[1030];
int mat[1030][1030];
vector<int> sol;

void citire()
{
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &sir1[i]);
    }

    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &sir2[i]);
    }
}

void solve()
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
    int x = n;
    int y = m;

    while(x > 0 && y > 0)
    {
        if(sir1[x] == sir2[y])
        {
            sol.push_back(sir1[x]);
            x--;
            y--;
        }
        else
        {
            if(mat[x][y - 1] > mat[x - 1][y])
            {
                y--;
            }
            else
            {
                x--;
            }
        }
    }

    sort(sol.begin(), sol.end());

    for(int i = 0; i < sol.size(); i++)
    {
        printf("%d ", sol[i]);
    }
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    citire();
    solve();
    afisare();

    return 0;
}
