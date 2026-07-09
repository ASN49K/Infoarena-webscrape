#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v[1030];
int w[1030];
int d[1030][1030];
int sir[1030];
int ind = 0;
int n, m;

int main()
{
    f>>n>>m;
    for(int i = 1; i<=n; i++)
    {
        f>>v[i];
    }
    for(int i = 1; i<=m; i++)
    {
        f>>w[i];
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(v[i] == w[j])
            {
                d[i][j] = d[i-1][j-1] + 1;
            }
            else
            {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }

    int i = n;
    int j = m;
    while(i != 0 && j != 0)
    {
        if(v[i] == w[j])
        {
            ind++;
            sir[ind] = v[i];
            i--;
            j--;
        }
        else if(d[i-1][j] < d[i][j-1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }

    g<<d[n][m]<<'\n';
    for(int i = ind; i>=1; i--)
    {
        g<<sir[i]<<" ";
    }
    return 0;
}
