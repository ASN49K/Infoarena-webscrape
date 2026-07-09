#include <fstream>
#define ll int
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

ll n, pd[1029][1029], a[1029], b[1029] ,m, sol[1029],cat;
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> a[i];
    for(int j = 1; j <= m; ++j)
        f >> b[j];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                pd[i][j] = pd[i - 1][j - 1] + 1;
            else
                pd[i][j] = max(pd[i - 1][j], pd[i][j - 1]);
        }
    int i = n, j = m;
    while(i >= 1 && j >= 1)
    {
        if(a[i] == b[j])
        {
            sol[++cat] = a[i];
            i--;
            j--;
        }
        else if(pd[i][j-1] > pd[i-1][j])
            j--;
        else
            i--;
    }
    g << pd[n][m] << '\n';
    for(int q = pd[n][m]; q >= 1 ; --q)
        g << sol[q] << ' ';
    f.close();
    g.close();
    return 0;
}
