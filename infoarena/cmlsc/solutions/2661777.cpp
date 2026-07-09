#include <fstream>
using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int a[1200][1200];
int v1[1200],v2[1200];
int main ()
{
    int n,m;
    in>>n>>m;
    for (int i = 1;i<=n;++i)
        in>>v1[i];
    for (int i = 1;i<=m;++i)
        in>>v2[i];
    for (int i = 1;i<=n;++i)
        for (int j = 1;j<=m;++j)
            if (v1[i]==v2[j])
                a[i][j] = a[i-1][j-1] + 1;
            else
                a[i][j] = max(a[i-1][j],a[i][j-1]);
    out<<a[n][m]<<'\n';
    int i = n, j = m;
    int rasp[2000], index = 1;
    while (i && j)
    {
        if (v1[i]==v2[j])
        {
            rasp[index++] = v1[i];
            --i;
            --j;
        }
        else if (a[i-1][j] > a[i][j-1])
            i--;
        else
            j--;
    }
    for (int i = index - 1;i>=1;--i)
        out<<rasp[i]<<' ';
    return 0;
}
