#include <fstream>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nmax = 1024;
int a[nmax + 5], b[nmax + 5], dp[nmax + 5][nmax + 4];


int main()
{
    int n, m;
    fin >> n >> m;
    int i, j;
    for ( i = 1; i <= n; ++i )
        fin >> a[i];

    for ( j = 1; j <= m; ++j )
        fin >> b[j];

    return 0;
}
