#include <fstream>

using namespace std;

#define DIM 1025

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int A[DIM], B[DIM], n, m, x, y;
int a[DIM][DIM];
bool s = 0;


void Din();
void Write(int i, int j);
int main()
{
    f >> n >> m;
    for ( int i = 1; i <= n; i++ )
        f >> A[i];
    for ( int j = 1; j <= m; j++ )
        f >> B[j];

    Din();
    g << a[n][m] << '\n';
    Write( n, m);
    return 0;
}
void Din()
{
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            if ( A[i] == B[j] )
                a[i][j] = a[i-1][j-1] + 1;
            if ( A[i] != B[j] )
                a[i][j] = max ( a[i-1][j], a[i][j-1] );
            if ( a[i][j] == 1 && s == 0)
                {
                    x = i, y = j, s = 1;
                }

        }

}
void Write(int i, int j)
{
    if ( !a[i][j] ) return;
    if ( A[i] == B[j] )
    {
        Write(i -1, j - 1);
        g << A[i] << ' ';
    }
    else
        if ( a[i - 1][j] > a[i][j - 1] )
            Write(i - 1, j);
        else
            Write(i, j - 1);
}
