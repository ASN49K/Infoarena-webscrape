#include <fstream>
using namespace std;
const int NMAX = 1024;
int a[NMAX + 1][NMAX + 1];
int drum[NMAX + 1];
int A[NMAX + 1];
int B[NMAX + 1];
ifstream fin( "cmlsc.in" );
ofstream fout( "cmlsc.out" );
int main() {
    int n, m, i, j, len;
    fin >> n >> m;
    for ( i = 1; i <= n; i++ )
        fin >> A[i];
    for ( i = 1; i <= m; i++ )
        fin >> B[i];
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= m; j++ )
            if ( A[i] == B[j] )
                a[i][j] = a[i - 1][j - 1] + 1;
            else
                a[i][j] = ( a[i][j - 1] > a[i - 1][j] ? a[i][j - 1] : a[i - 1][j] );
    i = n; j = m;
    len = a[n][m];
    while ( len > 0 ){
        if ( a[i][j - 1] == len )
            j--;
        else if ( a[i - 1][j] == len )
            i--;
        else
            drum[len--] = A[i--] = B[j--];
    }
    fout << a[n][m] << '\n';
    for( i = 1; i <= a[n][m]; ++i )
        fout << drum[i] << " ";

    return 0;
}
