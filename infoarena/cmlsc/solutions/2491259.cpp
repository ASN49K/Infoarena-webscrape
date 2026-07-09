#include <fstream>
#define dim 1025
using namespace std;
int L[dim][dim], n, m, i, j, k, a[dim], b[dim], sir[dim];
int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin>>n>>m;
    for (i=1; i<=n; i++)
        fin>>a[i];
    for (i=1; i<=m; i++)
        fin>>b[i];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            if (a[i]==b[j])
                    L[i][j]=1+L[i-1][j-1];
            else
                L[i][j]=max(L[i][j-1], L[i-1][j]);
        }
    fout<<L[n][m]<<"\n";
    i=n;
    j=m;
    while (i)
    {
        if (a[i]==b[j]) {
            sir[++k]=a[i];
            i--;
            j--;
        }
        else
            if (L[i][j-1]<L[i-1][j])
                i--;
            else
                j--;
    }
    for (i=k; i>=1; i--)
        fout<<sir[i]<<" ";
}
