#include <fstream>
#define DIM 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[DIM],b[DIM],d[DIM][DIM];

void reconst(int i,int j) {
    if (i!=0 && j!=0) {
        if (a[i]==b[j]) {
            reconst(i-1,j-1);
            fout<<a[i]<<" ";
        }
        else
            if (d[i-1][j]>d[i][j-1])
                reconst(i-1,j);
            else
                reconst(i,j-1);
    }
}

int main() {
    fin>>n>>m;
    for (int i=1;i<=n;i++)
        fin>>a[i];
    for (int i=1;i<=m;i++)
        fin>>b[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    fout<<d[n][m]<<"\n";
    reconst(n,m);
    return 0;
}
