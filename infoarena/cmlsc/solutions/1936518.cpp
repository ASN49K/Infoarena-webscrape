#include <fstream>
using namespace std;
int m,n,a[1025],mat[1025][1025],b[1025],v[1025];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    f>>m>>n;
    for(int i=1; i<=m; i++)
    {
        f>>a[i];
        mat[i][0]=0;
    }
    for(int j=1; j<=n; j++)
    {
        f>>b[j];
        mat[0][j]=0;
    }
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    g<<mat[m][n]<<'\n';
    int k=mat[m][n],i=m,j=n;
    while(i && j)
        if(a[i]==b[j])
        {
            v[k--]=b[j];
            i--;
            j--;
        }
        else if(mat[i-1][j]>=mat[i][j-1]) i--;
        else j--;
    for(int i=1; i<=mat[m][n]; i++) g<<v[i]<<' ';
    return 0;
}
