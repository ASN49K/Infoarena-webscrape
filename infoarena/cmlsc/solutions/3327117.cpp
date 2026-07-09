/*
https://infoarena.ro/problema/cmlsc
*/
#include <fstream>

using namespace std;

const int N = 1024;

int a[N+1], b[N+1];
int lung[N+1][N+1];

void refac_subsirul(ofstream &out, int l, int c)
{
    if (l == 0 || c == 0)
    {
        return;
    }
    if (a[l] == b[c])
    {
        refac_subsirul(out, l - 1, c - 1);
        out << a[l] << " ";
    }
    else
    {
        if (lung[l-1][c] > lung[l][c-1])
        {
            refac_subsirul(out, l - 1, c);
        }
        else
        {
            refac_subsirul(out, l, c - 1);
        }
    }
}

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int m, n;
    in >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        in >> a[i];
    }
    for (int j = 1; j <= n; j++)
    {
        in >> b[j];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
            {
                lung[i][j] = 1 + lung[i-1][j-1];
            }
            else
            {
                lung[i][j] = max(lung[i-1][j], lung[i][j-1]);
            }
        }
    }
    out << lung[m][n] << "\n";
    refac_subsirul(out, m, n);
    out << "\n";
    in.close();
    out.close();
    return 0;
}
