#include <fstream>
#define DIM 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,a[DIM],b[DIM],d[DIM][DIM];

void reconst(int i,int j) {
    if (i!=0 && j!=0) {
        if (a[i]==b[j]) {
            reconst(i-1,j-1);
            fout<<a[i]<<" ";
        }
        else
            if (d[i][j-1]>d[i-1][j])
                reconst(i,j-1);
            else
                reconst(i-1,j);
    }
}

int main() {
    fin>>n>>m;
    for (i=1;i<=n;i++)
        fin>>a[i];
    for (i=1;i<=m;i++)
        fin>>b[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
    fout<<d[n][m]<<"\n";
    reconst(n,m);
    return 0;
}
