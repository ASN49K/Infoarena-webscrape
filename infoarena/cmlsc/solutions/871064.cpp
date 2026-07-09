#include <fstream>
#define maxim(a,b) (a>=b)?a:b
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],d[1025][1025],r[1025];
int n,m,i,j,bun;

int main() {
    f >> n >> m;
    for (i=1;i<=n;i++) f >> a[i];
    for (j=1;j<=m;j++) f >> b[j];
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            if (a[i] == b[j]) d[i][j] = d[i-1][j-1] +1;
            else d[i][j] = maxim(d[i-1][j],d[i][j-1]);
        }
    }
    for (i=n,j=m;i;) {
        if (a[i] == b[j]) {
            r[bun++] = a[i];
            j--;
            i--;
        } else if (d[i-1][j] > d[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    g << bun-1 << '\n';
    for (i=bun-1;i>=0;i--) g << r[i]<< ' ';
}
