#include <fstream>
#define dim 1030
using namespace std;
int a[dim];
int b[dim];
int d[dim][dim];
int i,j,n,m;

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for (i=1;i<=n;i++) {
        fin>>a[i];
    }
    for (i=1;i<=m;i++) {
        fin>>b[i];
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            if (a[i]==b[j]) {
                d[i][j]=d[i-1][j-1]+1;
            }
            else {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    fout<<d[n][m]<<"\n";
    for (i=n,j=m;i>=1&&j>=1;) {
        if (a[i]==b[j]) {
            fout<<a[i]<<" ";
            i--;
            j--;
        }
        else {
            if (d[i-1][j]>d[i][j-1]) i--;
            else j--;
        }
    }
    return 0;
}
