#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


int d[1025][1025], n, m, k, N, M;
int a[1025], b[1025];
vector <int> sol;

int main()
{
    f >> n >> m;
    for(int i=1; i<=n; i++)
        f >> a[i];

    for(int i=1; i<=m; i++)
        f >> b[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];

            else d[i][j] = max( d[i-1][j], d[i][j-1]);
        }

    g << d[n][m] << '\n';

    int i=n, j=m;
    while(i && j)
    {
        if(a[i] == b[j])
        {
            sol.push_back(a[i]);
            i--,j--;
        }
        else if(d[i-1][j] > d[i][j-1]) i--;
        else j--;
    }
    reverse(sol.begin(), sol.end());
    int z =  d[n][m];
    for(int i=0; i < z; i++)
    {
        g << sol[i] << ' ';
    }
    return 0;
}
