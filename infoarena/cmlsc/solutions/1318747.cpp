#include <fstream>
#define NMax 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, v1[NMax], v2[NMax], i, j, d[NMax][NMax], sol[NMax], len;
int main()
{
    f>>n>>m;
    for (i=1; i<=n; i++)
        f>>v1[i];
    for (i=1; i<=m; i++)
        f>>v2[i];
    for (i=1; i<=n; i++) {
        for (j=1; j<=m; j++) {
            if (v1[i]==v2[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
        }
    }
    g<<d[n][m]<<"\n";
    i=n; j=m;
    len=d[i][j];
    while (i!=0 && j!=0) {
        if (v1[i] == v2[j]) {
            sol[len]=v1[i];
            len--;
            i--;
            j--;
        }
        else {
            if (d[i-1][j] > d[i][j-1])
                i--;
            else
                j--;
        }
    }
    for (i=1; i<=d[n][m]; i++)
        g<<sol[i]<<" ";
    return 0;
}
