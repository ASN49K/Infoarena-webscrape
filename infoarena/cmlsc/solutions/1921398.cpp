#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m, a[1030], b[1030],mat[1030][1030],i,j,cntr=0,sol[1025*1025];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(j=1;j<=m;j++)
        fin>>b[j];
    if(a[1]==b[1])
        mat[1][1]=1;
    for(i=1;i<=m;i++)
    {
        if(i==1) j=2;
        else j=1;
        for(;j<=n;j++)
            {
            if(b[i]==a[j])
              mat[i][j]=1+mat[i-1][j-1];
            else
               mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }

    }
    fout<<mat[m][n]<<'\n';
    i=m; j=n;
    while(i>=1 && j>=1)
    {
    if(b[i]==a[j])
     sol[++cntr]=b[i], i--, j--;
     else
        if(mat[i-1][j]>=mat[i][j-1])
        i--;
        else
            j--;
    }
    for(i=cntr;i>=1;i--)
        fout<<sol[i]<<' ';
    return 0;
}
