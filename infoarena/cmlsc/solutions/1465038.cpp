#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nmax= 1024;

int a[nmax+1], b[nmax+1];
int sol[nmax+1], d[nmax+1][nmax+1];

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
            if ( a[i]==b[j] ) {
                d[i][j]= d[i-1][j-1]+1;
            } else {
                d[i][j]= max(d[i-1][j], d[i][j-1]);
            }
        }
    }

    for ( int i= n, j= m, cnt= 0; i>=1 && j>=1; ) {
        if ( a[i]==b[j] ) {
            sol[++cnt]= a[i];
            --i;
            --j;
        } else {
            if ( d[i-1][j]>d[i][j-1] ) {
                --i;
            } else {
                --j;
            }
        }
    }

    fout<<d[n][m]<<"\n";
    for ( int i= d[n][m]; i>=1; --i ) {
        fout<<sol[i]<<" ";
    }
    fout<<"\n";

    return 0;
}
