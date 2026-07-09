#include <fstream>
#include <algorithm>
using namespace std;
int n,m,a[1025],b[1025],i,j,d[1025][1025],s[1025],t;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for (i=1;i<=n;i++) fin>>a[i];
    for (i=1;i<=m;i++) fin>>b[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    i=n; j=m;
    while (i&&j)
    {
        if (a[i]==b[j])
        {
            s[++t]=a[i];
            i--; j--;
        }
        else if (d[i][j-1]>d[i-1][j]) j--;
        else i--;
    }
    fout<<t<<'\n';
    for (i=t;i>=1;i--) fout<<s[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}
