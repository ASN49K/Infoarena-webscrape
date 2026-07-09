#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int b[257][257], c[257][257];
int main()
{   int n, m, v1[257],v2[257], b[257], t = 0;
    f>>n;
    f>>m;
    for (int i = 0; i < n; i++)
        f>>v1[i];
    for (int i = 0; i < m; i++)
        f>>v2[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(v1[i] == v2[j])
            {
                c[i][j] += c[i-1][j-1] + 1;
                b[t++] = v1[i];
            }
            else
            {
                if (c[i-1][j] > c[i][j-1])
                    c[i][j] = c[i-1][j];
                else
                    c[i][j] = c[i][j-1];
            }
        }
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        if (c[i][j] > maxi)
            maxi = c[i][j];
    }
    g<<maxi<<"\n";
    for (int i = 0; i < t; i++)
        g<<b[i]<<" ";

    return 0;
}
