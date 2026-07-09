#include <fstream>
#define N 1030

using namespace std;

ifstream inf("cmlsc.in");
ofstream outf("cmlsc.out");

int n, m, a[N], b[N], s[N], d[N][N], k;

int main()
{
    inf >> n >> m;
    for(int i=1; i<=n; i++)inf >> a[i];
    for(int i=1; i<=m; i++)inf >> b[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i] == b[j])
            {
                d[i][j] = d[i-1][j-1] + 1;
                continue;
            }

            d[i][j] = max(d[i-1][j], d[i][j-1]);
        }

    for(;d[n][m];)
    {
        if(a[n] == b[m])
        {
            s[++k] = a[n--];
            m--;
            continue;
        }

        if(d[n][m-1]>d[n-1][m])
            m--;
        else
            n--;
    }

    outf << k << "\n";

    for(;k;k--)
        outf << s[k] << " ";

    inf.close();
    outf.close();

    return 0;
}
