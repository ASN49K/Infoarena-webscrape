#include <fstream>

using namespace std;

int n,m,a[1030],b[1030],mat[1030][1030],maxim,sir[1030],i,j,nr;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for (i=1;i<=n;i++)
    f>>a[i];
    for (i=1;i<=m;i++)
    f>>b[i];
    maxim=0;

    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        if (a[i]==b[j])
            mat[i][j]=1+ mat[i-1][j-1];
            else {
                if (mat[i-1][j]>=mat[i][j-1]) maxim=mat[i-1][j];
                else
                maxim=mat[i][j-1];
                mat[i][j]=maxim;
            }

    g<<mat[n][m]<<'\n';

    maxim=mat[n][m];
    nr=maxim;
    while (maxim>0) {
        if (a[n]==b[m]) {
            sir[maxim]=a[n];
            --maxim;
            --n;
            --m;
        }
        else
        {
            if (mat[n][m-1]>mat[n-1][m]) --m;
            else
            --n;

        }
    }

    for (i=1;i<=nr;i++)
    g<<sir[i]<<' ';
    f.close();
    g.close();
    return 0;
}
