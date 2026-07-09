#include <fstream>
#include <vector>

int n, m, i, j;
std::vector<int> x, y;
std::vector< std::vector<int> > opt;
std::ifstream in ("cmlsc.in");
std::ofstream out("cmlsc.out");

int solve ()
{
    for (i=0; i<n; i++) opt[i][0] = (x[i] == y[0]);
    for (i=0; i<m; i++) opt[0][i] = (y[i] == x[0]);
    for (i=1; i<n; i++)
    {
        for (j=1; j<m; j++)
        {
            if (x[i] == y[j])
                opt[i][j] = opt[i-1][j-1] + 1;
            else if (opt[i-1][j] > opt[i][j-1])
                opt[i][j] = opt[i-1][j];
            else
                opt[i][j] = opt[i][j-1];
        }
    }
    return opt[n-1][m-1];
}

void write_sol(int i, int j)
{
    if (i == -1 or j == -1) return;
    if (opt[i-1][j] > opt[i][j-1]) write_sol (i-1, j);
    else                           write_sol (i, j-1);
    if (x[i] == y[j]) out << x[i] << " ";
}

int main()
{
    in >> n >> m;
    x.resize (n);
    y.resize (m);
    opt.resize (n, std::vector<int>(m, -1));
    for (i=0; i<n; i++) in >> x[i];
    for (i=0; i<n; i++) in >> y[i];

    out << solve () << "\n";

    write_sol (n-1, m-1);
}
