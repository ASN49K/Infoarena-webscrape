#include <fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n,m,k,a[1026],b[1026],p[1026][1026],sol[1026];
void citire ()
{
    f >> n >> m;
    for (int i = 1; i <= n; ++i) f >> a[i];
    for (int i = 1; i <= m; ++i) f >> b[i];
}
void cond1 ()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j]) p[i][j] = 1 + p[i-1][j-1];
            else             p[i][j] = max(p[i-1][j],p[i][j-1]);
}
void cond2 ()
{
    g << p[n][m] << '\n';
    int i = n,j = m;
    while (p[i][j])
    {
        if (a[i] == b[j]) { sol[++k] = a[i];
             i--;j--;
        }
        else
        {
            if (p[i-1][j] > p[i][j-1]) --i;
            else --j;
        }
    }
    for (; k >= 1; --k) g << sol[k] << ' ';
}
int main ()
{
    citire ();
    cond1 ();
    cond2();
    g.close ();
    return 0;
}
