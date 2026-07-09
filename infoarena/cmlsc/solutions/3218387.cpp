#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("cmslc.in");
ofstream fout("cmslc.in");
int ma[1030][1030], v[1025], v2[1025], gasit[1025];
int main()
{

    int n, m, z = 0;
    fin >> n >> m;
    for(int i = 1; i<=n; i++)
    {
        fin >> v[i];
    }
    for(int j = 1; j<=m; j++)
    {
        fin >> v2[j];
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j<=m; j++)
        {
            if(v2[j] == v[i])
            {
                gasit[++z] = v2[j];
                ma[i][j] = ma[i-1][j-1] + 1;
            }
            else
            {
                ma[i][j] = max(ma[i-1][j], ma[i][j-1]);
            }
        }
    fout << ma[n][m] << '\n';
    for(int i = 1; i<=z; i++) fout << gasit[i] << ' ';
    return 0;
}
