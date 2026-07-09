#include <fstream>
#define dim 1030
using namespace std;
int n, m, a[dim], b[dim], d[dim][dim], i, j, sol[dim], k;
int main ()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin>>n>>m;
    for (i=1; i<=n; i++) fin>>a[i];
    for (i=1; i<=m; i++) fin>>b[i];
    ///D[i][j]=cel mai lung subsir comun cu elemente din a pana la i si din b pana la j
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
    fout<<d[n][m]<<"\n";
    i=n; j=m; k=0;
    while (k<d[n][m])
    {
        if (a[i]==b[j])
        {
            sol[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if (d[i-1][j]>d[i][j-1])
                i--;
            else
                j--;
        }
    }
    for (i=k; i>=1; i--)
        fout<<sol[i]<<" ";
}
