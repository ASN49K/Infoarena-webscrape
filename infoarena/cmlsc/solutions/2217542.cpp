#include <fstream>
#define NMAX 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[NMAX],B[NMAX],sir[NMAX],D[NMAX][NMAX];
int n,m,i,j,k;
int maxim(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>A[i];
    for(i=1;i<=m;i++)
        fin>>B[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(A[i]==B[j])
                D[i][j]=1+D[i-1][j-1];
            else D[i][j]=maxim(D[i][j-1],D[i-1][j]);
        }
    }
    fout<<D[--i][--j]<<'\n';
    while(i)
    {
        if(A[i]==B[j])
        {
            sir[k++]=A[i];i--;j--;
        } else if(D[i][j-1]>D[i-1][j])
                j--;
                else i--;
    }
    for(k=k-1;k>=0;k--)
        fout<<sir[k]<<' ';
    return 0;
}
