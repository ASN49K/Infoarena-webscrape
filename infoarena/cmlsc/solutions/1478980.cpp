// Galatan Tudor - Ion Luca High School
// Husi, Romania, Su, August 30, 2015

#include <fstream>
 
using namespace std;
 
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
 
int mx[1024][1024];
int a[1024], b[1024], sub[1024];
int n, m, i, j, x=0;
 
int main ()
{
    in >> n >> m;
    for (i=1; i<=n; i++)
        in >> a[i];
    for (i=1; i<=m; i++)
        in >> b[i];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            if (a[i] == b[j])
                mx[i][j] = mx[i-1][j-1]+1;
            else
                mx[i][j] = max (mx[i-1][j], mx[i][j-1]);
        }
    i = n;
    j = m;
    while (mx[i][j])
    {
        while (mx[i][j] == mx[i-1][j])
            i--;
        while (mx[i][j] == mx[i][j-1])
            j--;
        x++;
        sub[x] = a[i];
        i--, j--;
    }
    out << mx[n][m] << "\n";
    for (i=x; i>=1; i--)
        out << sub[i] << " ";
    return 0;
}