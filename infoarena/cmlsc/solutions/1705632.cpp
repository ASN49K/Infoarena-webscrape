#include <fstream>
#include <vector>
#include <stack>

std::ifstream in ("cmlsc.in");
std::ofstream out("cmlsc.out");

std::vector<int> x, y;
std::vector< std::vector<int> > opt;
std::stack <int> results;
int n, m, i, j;

void sol (int i, int j)
{
    if (i == 0 or j == 0) return;
    if (opt[i][j-1] > opt[i-1][j]) sol (i, j-1);
    else sol (i-1, j);
    if (x[i] == y[j]) out << x[i] << " ";
}

int main()
{
    in >> n >> m;
    x.resize (n+1);
    y.resize (m+1);
    opt.resize (n+1, std::vector<int>(m+1, 0));

    for (i=1; i<=n; i++) in >> x[i];
    for (j=1; j<=m; j++) in >> y[j];

    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if (x[i] == y[j]) opt[i][j] = opt[i-1][j-1] + 1;
            else if (opt[i-1][j] > opt[i][j-1]) opt[i][j] = opt[i-1][j];
            else opt[i][j] = opt[i][j-1];
        }
    }

    out << opt[n][m] << "\n";
    sol (n, m);
}
