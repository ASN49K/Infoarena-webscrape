#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, a[1025], b[1025], d[1025][1025], i, j, l, af[1025];

int main()
{
    f >> m >> n;
    for(i = 1; i <= m; i++) f >> a[i];
    for(i = 1; i <= n; i++) f >> b[i];

    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            if(a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);


    l = d[m][n];

    g << d[m][n] << '\n';


    while(i || j)
        {
            if(a[i] == b[j])
                af[l--] = a[i], i--, j--;
            else if(d[i - 1][j] < d[i][j - 1])
                j--;
            else
                i--;
        }


    for(i = 0; i < d[m][n]; i++)
        g << af[i] << " ";
    return 0;
}
