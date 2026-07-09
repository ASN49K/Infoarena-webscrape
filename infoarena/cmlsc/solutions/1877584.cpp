#include <fstream>

#define Ndim 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short int SOL[Ndim],A[Ndim],B[Ndim],D[Ndim][Ndim];
void reconstit(int i,int j)
{
    if(i>1 || j>1)
    {
        if(A[i] == B[j])
        {
            SOL[++SOL[0]] = A[i];
            reconstit(i-1,j-1);
        }
        else
        {
            if(D[i-1][j]> D[i][j-1])
                reconstit(i-1,j);
            else
                reconstit(i,j-1);
        }
    }
}
int main()
{
    int n,m,i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>A[i];
    for(i=1;i<=m;i++)
        fin>>B[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(A[i] == B[j])
                D[i][j] = D[i-1][j-1]+1;
            else
                D[i][j] = max(D[i-1][j],D[i][j-1]);
        }
    }
    reconstit(n,m);
    fout<<D[n][m]<<'\n';
    for(i=SOL[0];i>=1;i--)
        fout<<SOL[i]<<' ';
    return 0;
}
