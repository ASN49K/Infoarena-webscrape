#include <fstream>
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

void Read();
void Dinamica();
void Print();

int n, m, a[1025], b[1025], d[1025][1025], imax, jmax;

int main()
{
    Read();
    Dinamica();
    Print();
    is.close();
    os.close();
    return 0;
}
void Read()
{
    is >> n >> m;
    for ( int i = 1; i <= n; ++i )
        is >> a[i];
    for ( int i = 1; i <= m; ++i )
        is >> b[i];
}
void Dinamica()
{
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
            if ( a[i] == b[j] )
            {
                d[i][j] = d[i-1][j-1] + 1;
                if ( d[i][j] > d[imax][jmax] )
                {
                    imax = i;
                    jmax = j;
                }
            }
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);
}
void Print()
{
    int s[1025];
    int nr = 0;
    os << d[imax][jmax] << '\n';
    while ( d[imax][jmax] != 0 )
    {
        if ( a[imax] == b[jmax] )
        {
            s[++nr] = a[imax];
            imax--;
            jmax--;
        }
        else
        {
            if ( d[imax-1][jmax] > d[imax][jmax-1] )
                imax--;
            else
                jmax--;
        }
    }
    for ( int i = nr; i > 0; --i )
        os << s[i] << ' ';
}
