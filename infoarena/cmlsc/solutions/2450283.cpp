#include <fstream>
#define NMax 1024

using namespace std;
int m, n, a[NMax], b[NMax], r[NMax][NMax], cmlsc[NMax], x;

int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin >> m >> n;
    for (int i = 1; i <= m; ++i)
        fin >> a[i];
    for (int j = 1; j <= n; ++j)
        fin >> b[j];

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        r[i][j] = (a[i] == b[j]) ? 1 + (r[i-1][j-1]) : max(r[i-1][j], r[i][j-1]);

    for (int i = m, j = n; i;)
        if (a[i] == b[j]) cmlsc[++x] = a[i], --i, --j;
    else
        (r[i-1][j] > r[j-1][i]) ? --i : --j;

    fout << x << "\n";
    for (int i = x; i; --i)
        fout << cmlsc[i] << " ";
    return 0;
}
