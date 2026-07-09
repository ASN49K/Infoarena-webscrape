#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,i,j,k,a[1030],b[1030],af[1030],d[1030][1030];

int main()
{
    fin >> n >> m;
    for (i=1;i<=n;i++) fin >> a[i];
    for (j=1;j<=m;j++) fin >> b[j];
    for (i=1;i<=n;i++) for (j=1;j<=m;j++)
    {
        if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
        else d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    fout << d[n][m] << "\n";
    i=n;
    j=m;
    k=d[n][m];
    while (d[i][j]!=0)
    {
        if (a[i]==b[j])
        {
            af[k]=a[i];
            k--;
            i--;
            j--;
        }
        else
        {
            if (d[i-1][j]>d[i][j-1]) i--;
            else j--;
        }
    }
    for (i=1;i<=d[n][m];i++) fout << af[i] << " ";

    return 0;
}
