#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("palindron.in");
ofstream fout("palindrom.out");

const int DIM = 5005;
char a[DIM], b[DIM];
int x[2][DIM];
int N;
int lc, lp;

int main()
{
    int i, j = 0;

    fin >> N;
    fin.get();
    fin.getline( a, DIM );
    for ( i = N - 1; i >= 0; i-- )
        b[j++] = a[i];

 //   fout << a << '\n' << b << '\n';

    lc = 1, lp = 0;
    for ( i = 1; i <= N; i++, lp = !lp, lc = !lc )
        for ( j = 1; j <= N; j++ )
            if ( a[i - 1] == b[j - 1] )
                x[lc][j] = x[lp][j - 1] + 1;
            else
                x[lc][j] = max( x[lc][j - 1], x[lp][j] );

    fout << N - x[lp][N];

    fin.close();
    fout.close();
    return 0;
}
