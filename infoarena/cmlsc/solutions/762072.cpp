#include <iostream>
#include <fstream>
#include <vector>

std::vector< std::vector<int> > matrix;
std::vector<int> a, b;

void cmlsc()
{
    matrix.resize( a.size() + 1 );
    matrix[0].resize( b.size() + 1 );
    for( int i = 1; i < a.size() + 1; i++ )
    {
        matrix[i].resize( b.size() + 1 );
        for( int j = 1; j < b.size() + 1; j++ )
        {
            if( a[i-1] == b[j-1] )
            {
                matrix[i][j] = 1 + matrix[i-1][j-1];
            }
            else
            {
                matrix[i][j] = ( matrix[i-1][j] > matrix [i][j-1] ) ? matrix[i-1][j] : matrix[i][j-1];
            }
        }
    }

}

void read( std::ifstream &f, int n, int m )
{
    a.resize( n );
    b.resize( m );
    for( int i = 0; i < n; i++ )
    {
        f >> a[i];
    }

    for( int i = 0; i < m; i++ )
    {
        f >> b[i];
    }
}

void write( std::ofstream &out, int n, int m )
{
    if( matrix[n][m] == 0 )
        return;
    if( a[n-1] == b[m-1] )
    {
        write( out, n - 1, m - 1 );
        out << a[n-1] << ' ';
        return;
    }
    else
    {
        if( matrix[n-1][m] > matrix[n][m-1] )
            write( out, n - 1, m );
        else
            write( out, n, m - 1 );
    }
}

int main()
{
    std::ifstream in ( "cmlsc.in" );
    std::ofstream out ( "cmlsc.out" );
    int na, nb;
    in >> na >> nb;
    read( in, na, nb );
    cmlsc();
    out << matrix[a.size()][b.size()] << '\n';
    write( out, a.size(), b.size() );
    in.close();
    out.close();
    return 0;
}
