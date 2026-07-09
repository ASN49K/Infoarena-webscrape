#include <fstream>
#define dim 1030
using namespace std;
int a[dim];
int b[dim];
int c[dim][dim];
int sol[dim];
int i,j,n,m,u;

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
    for (i=0;i<=n;i++) {
        for (j=0;j<=m;j++) {
            if (i==0||j==0) c[i][j]=0;
            else if (a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    fout<<c[n][m]<<"\n";
    i=n;
    j=m;
    while (i!=0&&j!=0) {
        if (a[i]==b[j]) {
            sol[++u]=a[i];
            i--;
            j--;
        }
        else if (c[i-1][j]>c[i][j-1]) {
            i--;
        }
        else j--;
    }
    for (i=u;i>=1;i--) fout<<sol[i]<<" ";
    return 0;
}
