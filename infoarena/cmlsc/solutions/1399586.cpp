#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[1025][1025],m,n,i,j,vM[1025],vN[1025],sol[1025];
int main()
{
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>vM[i];
    for(i=1;i<=n;i++)
        fin>>vN[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(vN[i]==vM[j])
            {
                sol[++sol[0]]=vN[i];
                A[i][j]=A[i-1][j-1]+1;
            }
            else
                A[i][j]=max(A[i][j-1],A[i-1][j]);
        }
    }
    fout<<sol[0]<<'\n';
    for(i=1;i<=sol[0];i++)
        fout<<sol[i]<<' ';
    return 0;
}
