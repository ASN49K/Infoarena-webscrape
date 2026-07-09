#include <fstream>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void refac_subsirul(vector < vector<int>> &l_s, vector <int> &a, vector <int> &b, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (a[i] != b[j])
    {
        if (l_s[i-1][j] >= l_s[i][j-1])
        {
            refac_subsirul(l_s, a, b, i - 1, j);
        }
        else
        {
            refac_subsirul(l_s, a, b, i, j - 1);
        }
    }
    else
    {
        refac_subsirul(l_s, a, b, i - 1, j - 1);
        out << a[i] << " ";
    }
}

int main()
{
    int m, n;
    in >> m >> n;
    vector <int> a(m + 1);
    for (int i = 1; i <= m; i++)
    {
        in >> a[i];
    }
    vector <int> b(n + 1);
    for (int j = 1; j <= n; j++)
    {
        in >> b[j];
    }
    vector < vector <int>> l_s(m + 1);
    for (int i = 0; i <= m; i++)
    {
        vector <int> aux(n + 1, 0);
        l_s[i] = aux;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] != b[j])
            {
                l_s[i][j] = max(l_s[i-1][j], l_s[i][j-1]);
            }
            else
            {
                l_s[i][j] = 1 + l_s[i-1][j-1];
            }
        }
    }
    out << l_s[m][n] << "\n";
    refac_subsirul(l_s, a, b, m, n);
    in.close();
    out.close();
    return 0;
}
