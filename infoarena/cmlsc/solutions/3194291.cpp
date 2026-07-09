#include <fstream>

using namespace std;

const int N = 1024;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int lmax[N + 1][N + 1], a[N + 1], b[N + 1];

void refac_subsir(int i, int j)
{
    if(i == 0 || j == 0)
        return;
    
    if(a[i] == b[j])
    {
        refac_subsir(i - 1, j - 1);
        out << a[i] << ' ';
    }
    else
        if(lmax[i - 1][j] > lmax[i][j - 1])
            refac_subsir(i - 1, j);
        else
            refac_subsir(i, j - 1);
}
int main()
{
    int n, m;

    in >> m >> n;

    for(int i = 1; i <= m; i++)
        in >> a[i];
    
    for(int j = 1; j <= n; j++)
        in >> b[j];

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(a[i] == b[j])
                lmax[i][j] = 1 + lmax[i - 1][j - 1];
            else
                lmax[i][j] = max(lmax[i - 1][j], lmax[i][j - 1]);

    out << lmax[m][n] << '\n';
    refac_subsir(m, n);
}