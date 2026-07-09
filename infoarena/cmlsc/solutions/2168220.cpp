#include <fstream>
#include <vector>
#define nmax 1025
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int a[nmax], b[nmax], n, m, ma[nmax][nmax];
vector < int > sol;

void constr (int i, int j)
{
    while (i && j)
    {
        if (a[i] == b[j])
            {
                sol.push_back (a[i]);
                i--, j--;
            }
        else
        {
            if (ma[i - 1][j] > ma[i][j - 1]) i--;
            else j--;
        }
    }
}

int main ()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++) fin >> a[i];
    for (int i = 1; i <= n; i++) fin >> b[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                ma[i][j] = ma[i - 1][j - 1] + 1;
            else
                ma[i][j] = max (ma[i - 1][j], ma[i][j - 1]);
        }
    }
    fout << ma[n][m] << '\n';
    constr (n, m);
    for (int i = sol.size () - 1; i >= 0; i--)
        fout << sol[i] << " ";

    return 0;
}

