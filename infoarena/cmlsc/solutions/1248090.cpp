#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX = 1030;
int a[MAX], b[MAX], s[MAX];
int N, M;
int x[MAX][MAX];

void Write( int i, int j );

int main()
{
    int i, j;

    fin >> N >> M;
    for ( i = 1; i <= N; i++ )
        fin >> a[i];
    for ( j = 1; j <= M; j++ )
        fin >> b[j];

    for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= M; j++ )
            if ( a[i] == b[j] )
                x[i][j] = 1 + x[i - 1][j - 1];
            else
                x[i][j] = max( x[i - 1][j], x[i][j - 1] );

    fout << x[N][M] << '\n';
    Write( N, M );

    fin.close();
    fout.close();
    return 0;
}

void Write( int i, int j )
{
    if ( i == 0 || j == 0 )
        return;

    if ( a[i] == b[j] )
    {
        Write( i - 1, j - 1 );
        if ( s[a[i]] == 0 )
        {
            fout << a[i] << ' ';
            s[a[i]] = 1;
        }
    }
    else
    if (x[i-1][j]  > x[i-1][j] )
        Write( i - 1, j );

     else
        if(x[i-1][j]  < x[i-1][j])
            Write( i, j - 1 );
        else
            {
                Write( i - 1, j );
                Write( i, j - 1 );

            }
}
