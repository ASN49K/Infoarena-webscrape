#include <fstream>
#define DIM 1030
using namespace std;
int n,m,i,j,k,a[DIM],b[DIM],d[DIM][DIM],sol[DIM];
int main (){

    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");

    fin>>n>>m;
    for (i=1;i<=n;i++)
        fin>>a[i];
    for (i=1;i<=m;i++)
        fin>>b[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max (d[i-1][j],d[i][j-1]);
    i = n;
    j = m;
    for (;i>=1&&j>=1;){
        if (a[i] == b[j]){
            sol[++k] = a[i];
            i--;
            j--;
        }
        else
            if (d[i-1][j] > d[i][j-1])
                i--;
            else
                j--;
    }
    fout<<k<<"\n";
    for (i=k;i>=1;i--)
        fout<<sol[i]<<" ";

    return 0;
}
