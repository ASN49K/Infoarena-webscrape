// By Zamfi
#include <fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int a[1050], b[1050],c[1050][1050],v[1050],n,m,i,j,k;
int main()
{
    f >> n >> m;
    for (i = 1; i <= n; i++ )
        f >> a[i];
    for (j = 1; j <= m; j++ )
        f >> b[j];
    for (i = 1; i <= n; i++ )
    for (j = 1; j <= m; j++ )
    {
        if ( a[i] == b[j] )
            c[i][j] = c[i - 1][j - 1] + 1;
        else
            if ( c[i - 1][j] >= c[i][j - 1] )
                c[i][j] = c[i - 1][j];
            else
                c[i][j] = c[i][j - 1];
    }
    i = n;
    j = m;
    g << c[n][m] << "\n";
    while ( i != 0 )
    {
         if ( a[i] == b[j] )
         {
             k++;
             v[k] = b[j];
             i--;
             j--;
         }
         else
            if ( c[i - 1][j] > c[i][j - 1])
                i--;
            else
                j--;
    }
    for ( i = 1; i <= k; i ++ )
        g << v[i] << " ";
    return 0;
}
