#include <fstream>
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

int n, m;
int a[1025], b[1025];
int c[1025][1025];
int contor, C[1025];

void Solve(int i, int j);

int main()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
    {
        is >> a[i];
    }
    for ( int j = 1; j <= m; ++j )
        is >> b[j];
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            if ( a[i] == b[j] )
            {
                c[i][j] = 1 + c[i - 1][j - 1];
            }
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            if ( c[i][j] != contor )
            {
                ++contor;
            }
        }
    os << c[n][m] << "\n";
    Solve(n, m);
    is.close();
    os.close();
    return 0;
}

void Solve(int i, int j)
{
    if ( !c[i][j] )
        return;
    if ( a[i] == b[j] )
    {
        Solve(i - 1, j - 1);
        os << a[i] << " ";
    }
    else
    {
        if ( c[i][j - 1] > c[i - 1][j] && i > 1 && j > 1 )
            Solve(i, j - 1);
        else
            Solve(i - 1, j);
    }
}
