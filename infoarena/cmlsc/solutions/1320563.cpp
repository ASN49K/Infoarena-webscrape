#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int DIM = 1030;
int n, m, a[DIM], b[DIM];
int c[DIM][DIM];
void Read();
void Write(int i, int j);

int main()
{
    Read();
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            if ( a[i] == b[j] )
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
    fout << c[n][m] <<'\n';
    Write(n, m);

    fin.close();
    fout.close();
    return 0;
}

void Write(int i, int j)
{
    if ( j == 0 || i == 0 ) return;
    if ( a[i] == b[j] )
    {
        Write(i - 1, j - 1);
        fout << a[i] << ' ';
    }
    else
        if ( c[i][j - 1] > c[i - 1][j] )
            Write(i, j - 1);
        else
            Write(i - 1, j);
}
void Read()
{
    fin >> n >> m;
    for ( int i = 1; i <= n; i++ )
        fin >> a[i];
    for ( int i = 1; i <= m; i++ )
        fin >> b[i];
}
