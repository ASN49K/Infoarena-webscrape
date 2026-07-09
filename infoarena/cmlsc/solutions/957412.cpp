#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n,m,i,j,k,a[1030],b[1030],d[1030][1030],s[1030];
int main () {
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
                if (d[i-1][j]>d[i][j-1])
                    d[i][j]=d[i-1][j];
                else
                    d[i][j]=d[i][j-1];

    fout<<d[n][m]<<"\n";
    for (i=n,j=m;i>=1;) {
        if (a[i]==b[j]) {
            s[++k]=a[i];
            i--;j--;
        }
        else
            if (d[i-1][j]>d[i][j-1])
                i--;
            else
                j--;
    }
    for (i=k;i>=1;i--)
        fout<<s[i]<<" ";



    return 0;
}

