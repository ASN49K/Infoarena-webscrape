#include <fstream>

using namespace std;

int d[1030][1030];

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n, m;
    int v[1030], w[1030];

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
    int sir[1030];
    int c = 0;
    while(i && j)
    {
        if(v[i] == w[j])
        {
            c++;
            sir[c] = v[i];
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


    g<<d[n][m]<<endl;
    for(i = c; i>=1; i--)
    {
        g<<sir[i]<<" ";
    }
    return 0;
}
