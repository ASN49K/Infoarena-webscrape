#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,lmax,a[1025],b[1025],c[1025],mat[1025][1025];

int main()
{
    int i,j;
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];

    for(i=1; i<=m; i++)
        fin>>b[i];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])mat[i][j]=1+mat[i-1][j-1];
            else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);

    i=n; j=m;
    while(i>0)
    {
        if(a[i]==b[j])
        {
            lmax++;
            c[lmax]=a[i];
            i--; j--;
        }
        else if(mat[i-1][j] < mat[i][j-1])j--;
        else i--;
    }
    fout<<lmax<<'\n';
    for(i=lmax; i>0; i--)fout<<c[i]<<" ";
    return 0;

}
