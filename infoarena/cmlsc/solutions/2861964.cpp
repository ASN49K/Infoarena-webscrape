#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1025],b[1025],d[1025][1025],s[1025],bst;
int main()
{
    fin>>n>>m;
    for (int i=1; i<=n; i++)
        fin>>a[i];
    for (int j=1; j<=m; j++)
        fin>>b[j];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            if (a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    int i=n,j=m;
    while (i>0)
    {
        if (a[i]==b[j])
        {
            s[++bst]=a[i];
            i--;
            j--;
        }
        else if (d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;
    }
    fout<<bst<<'\n';
    for (int i=bst; i; i--)
        fout<<s[i]<<' ';
    return 0;
}
