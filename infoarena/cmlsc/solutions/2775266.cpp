#include <vector>
#include <fstream>
using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int v1[1030], v2[1030];
int a[1100][1100];
int main ()
{
    int n, m;
    in >> n >> m;
    for (int i = 1;i<=n;++i)
        in >> v1[i];
    for (int i = 1;i<=m;++i)
        in >> v2[i];
    for (int i = 1;i<=n;++i)
        for (int j = 1;j<=m;++j)
        {
            if (v1[i] == v2[j])
                a[i][j] = a[i - 1][j - 1] + 1;
            else
                a[i][j] = max (a[i-1][j], a[i][j-1]);
        }
    out << a[n][m] << '\n';
    int i = n, j = m;
    vector <int> v;
    while (i != 0 && j != 0)
    {
        if (v1[i] == v2[j])
        {
            v.push_back(v1[i]);
            --i;
            --j;
        }
        else if (a[i-1][j] > a[i][j-1])
            --i;
        else
            --j;
    }
    for (int i = v.size() - 1; i>=0;--i)
        out << v[i] << ' ';
    return 0;
}
