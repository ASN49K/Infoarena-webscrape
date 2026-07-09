#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025][1025];

void read_array(int v[], int & n, int u[], int & m)
{
    fin>>n>>m;
    for(int i = 0; i < n; i++)
        fin>>v[i];
    for(int i = 0; i < m; i++)
        fin>>u[i];
}

void path(int u[], int x, int y)
{
    while(x > 0 && y >= 0)
    {
        if(y == 0)
        {
            if(a[x][y] == a[x - 1][y]) x--;
            else
            {
                fout<<u[y]<<' ';
                return;
            }
        }
        else
        {
            if(a[x][y] == a[x][y - 1]) y--;
            else if(a[x][y] == a[x - 1][y]) x--;
            else if(a[x][y] > a[x - 1][y - 1])
            {
                path(u, x - 1, y - 1);
                fout<<u[y]<<' ';
                return;
            }
        }
    }
}

int LCS(int v[], int n, int u[], int m)
{
    for(int i = 0; i < n; i++)
    {
        if(v[i] == u[0]) a[i + 1][0] = 1;
        else a[i + 1][0] = a[i][0];
        for(int j = 1; j < m; j++)
        {
            if(v[i] == u[j])
                a[i + 1][j] = a[i][j - 1] + 1;
            else
                {
                    a[i + 1][j] = max(a[i + 1][j - 1], a[i][j]);
                }
        }
    }

    path(u, n, m - 1);

    return a[n][m - 1];
}

int main()
{
    int v[1024], u[1024], n, m, lcs;

    read_array(v, n, u, m);
    lcs = LCS(v, n, u, m);

    return 0;
}
