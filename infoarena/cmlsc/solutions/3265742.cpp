#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int lcs[1025][1025] = {0}, t[1025][1025] = {0}, a[1025], b[1025];

void backtrack(int i, int j, ofstream& out)
{
    if (i == 0 || j == 0)
        return;
    int i2 = i, j2 = j;
    if (t[i][j] == 3)
        --j2;
    else if (t[i][j] == 2)
        --i2;
    else if (t[i][j] == 1) {
        --i2;
        --j2;
    }
    backtrack(i2, j2, out);
    if (a[i] == b[j])
        out << a[i] << ' ';
}

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int m, n, i, j;
    in >> m >> n;
    for (i = 1; i <= m; ++i)
        in >> a[i];
    for (i = 1; i <= n; ++i)
        in >> b[i];

    for (i = 1; i <= m; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (a[i] == b[j]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
                t[i][j] = 1;
            }
            else{
                if (lcs[i-1][j] >= lcs[i][j-1]) {
                    t[i][j] = 2;
                    lcs[i][j] = lcs[i-1][j];
                }
                else
                {
                    t[i][j] = 3;
                    lcs[i][j] = lcs[i][j-1];
                }
            }
        }
    }

    out << lcs[m][n] << '\n';

    backtrack(m, n, out);

    in.close();
    out.close();
    return 0;
}