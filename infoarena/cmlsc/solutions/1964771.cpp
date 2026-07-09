#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int Max,D[1025][1025],A[1025],B[1025],x,SOL[1025];
int main()
{
    int n,m,i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>A[i];
    for(i=1;i<=m;i++)
    {
        fin>>B[i];
        for(j=1;j<=n;j++)
        {
            D[i][j] = max(D[i-1][j],D[i][j-1]);
            if(B[i]==A[j])
            {
                D[i][j] = max(D[i][j],D[i-1][j-1]+1);
                Max = max(Max,D[i][j]);
            }
        }
    }
    fout<<Max<<'\n';
    i=m,j=n;
    int nr=0;
    while(i)
    {
        if(A[j]==B[i])
        {
            SOL[++nr] = A[j];
            i--;j--;
        }
        else if(D[i-1][j]>D[i][j-1])
            i--;
        else
            j--;
    }
    for(i=Max;i>=1;i--)
        fout<<SOL[i]<<' ';
    return 0;
}
