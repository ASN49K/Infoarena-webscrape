#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, i, j;
int lcs[1030][1030], l1[1030], l2[1030];

void afisare(int i,int j)
{
    if (i != 0 && j != 0)
   {
        if (lcs[i][j] == lcs[i - 1][j])
            afisare(i - 1, j);
        else if (lcs[i][j] == lcs[i][j - 1])
            afisare(i, j - 1);
        else
        {
            afisare(i - 1, j -1 );
            out << l1[i] << " ";
        }
   }
}

int main()
{
    in >> n >> m;
    for (i = 1; i <= n; ++i)
        in >> l1[i];
    for (i = 1; i <= m; ++i)
        in >> l2[i];
    for (j = 1; j <= m; ++j)
        lcs[0][j] = 0;
    for (i = 1; i <= n; ++i)
        lcs[i][0] = 0;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= m; ++j)
        {
            if (l1[i] == l2[j])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    out << lcs[n][m] << '\n';
    afisare(n, m);
    return 0;
}
