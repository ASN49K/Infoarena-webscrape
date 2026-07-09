#include <fstream>
#include <vector>
using namespace std;

const string fis = "fis";
ifstream is(fis + ".in");
ofstream os(fis + ".out");

using VI = vector<int>;
using VVI = vector<VI>;

int n, m, lmax;
VI a, b, t;
VVI c;

void write(int i, int j);

int main()
{
    is >> n >> m;
    a = VI(n + 1);
    b = VI(m + 1);
    for ( int i = 1; i <= n; ++i )
        is >> a[i];
    for ( int i = 1; i <= m; ++i )
        is >> b[i];
    c = VVI(n + 1, VI(m + 1));
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( a[i] == b[j] )
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                lmax = max(lmax, c[i][j]);
            }
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
    os << lmax << "\n";
    write(n, m);
    is.close();
    os.close();
    return 0;
}

void write(int i, int j)
{
    if ( !i )
        return;
    if ( a[i] == b[j] )
    {
        write(i - 1, j - 1);
        os << a[i] << " ";
    }
    else
        if ( c[i][j - 1] > c[i - 1][j] )
            write(i, j - 1);
        else
            write(i - 1, j);
}
