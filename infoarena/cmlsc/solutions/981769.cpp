#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025], b[1025], c[1025][1025], i, j, k, n, m, sol[1025];
void cmlsc(int x, int y)
{
    if(x == 0 || y == 0)
        return;
    if(c[i][j] == c[i - 1][j])
    {
        cmlsc(i - 1, j - 1);
        g << a[i] << " ";
    }
    else
        if(c[i][j] != c[i][j - 1])
        {
            cmlsc(i - 1, j);
        }
        else
        {
            cmlsc(i, j - 1);
        }
}
int main ()
{
    f >> m >> n;
    for(i = 1; i <= m; ++ i)
        f >> a[i];
    for(j = 1; j <= n; ++ j)
        f >> b[j];
    for(i = 1; i <= m; ++ i)
        c[i][0] = 0;
    for(j = 0; j <= n; ++ j)
        c[0][j] = 0;
    for(i = 1; i <= m; ++ i)
        for(j = 1; j <= n; ++ j)
        {
            if(a[i] == b[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else
                if(c[i - 1][j] >= c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                }
        }
    i = m;
    j = n;
    k = 0;
    while(i > 0 && j > 0)
    {
        if(c[i][j] == c[i - 1][j] && c[i][j] != 0)
        {
            i--;
        }
        else
            if(c[i][j] != c[i][j - 1])
            {
                k++;
                sol[k] = a[i];
                i--;
                j--;
            }
            else
            {
                j--;
            }
    }
    g << c[m][n] << "\n";
    for(i = k; i > 0; -- i)
        g << sol[i] << " ";
    return 0;
}
