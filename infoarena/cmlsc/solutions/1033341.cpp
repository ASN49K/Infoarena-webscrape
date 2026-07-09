#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nmax= 1024;

int a[nmax+1], b[nmax+1], sol[nmax+1], d[nmax+1][nmax+1];

int main(  ) {
    int n, m;
    fin>>n>>m;
    for ( int i= 1; i<=n; ++i ) {
        fin>>a[i];
    }
    for ( int i= 1; i<=m; ++i ) {
        fin>>b[i];
    }

    for ( int i= 1; i<=n; ++i ) {
        for ( int j= 1; j<=m; ++j ) {
            d[i][j]= d[i-1][j];
            if ( a[i]==b[j] ) {
                d[i][j]= d[i-1][j-1]+1;
            } else if ( d[i][j-1]>d[i-1][j] ) {
                d[i][j]= d[i][j-1];
            }
        }
    }

    int k= 0;
    int i= n, j= m;
    while ( i>0 && j>0 ) {
        if ( a[i]== b[j] ) {
            ++k;
            sol[k]= a[i];
            --i, --j;
        } else if ( d[i-1][j]>d[i][j-1] ) {
            --i;
        } else {
            --j;
        }
    }

    fout<<k<<"\n";
    for ( int i= k; i>=1; --i ) {
        fout<<sol[i]<<" ";
    }
    fout<<"\n";
    
    return 0;
}

