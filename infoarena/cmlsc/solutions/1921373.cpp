#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m, a[1030], b[1030],mat[1030][1030],i,j,cntr=1;
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
    for(i=1;i<=m;i++)
        {
        for(j=1;j<=n;j++)
         if(mat[i][j]==cntr && b[i]==a[j])
            fout<<b[i]<<' ',cntr++;
        }

    return 0;
}
