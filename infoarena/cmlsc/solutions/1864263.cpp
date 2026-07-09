#include <fstream>
#include <iostream>
#define NM 1050
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, a[NM], b[NM], d[NM][NM];

int main()
{
    int sol = 0, s[NM];
    f >> n >> m;
    for(int i = 1; i <= n; ++i) f >> a[i];
    for(int j = 1; j <= m; ++j) f >> b[j];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j]) d[ i ][ j ] = d[i - 1][j - 1] + 1;
            else d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    }
    int i = n, j = m;
    while(i)
    {
        if(d[i][j] == d[i-1][j-1] + 1)
        {
            s[++sol] = a[i];
            i--;
            j--;
        }
        else if(d[i-1][j] < d[i][j-1]) j--;
        else  i--;
    }
    g << sol << '\n';
    for(int i = sol; i >= 1; --i) g << s[i] << ' ';


}
