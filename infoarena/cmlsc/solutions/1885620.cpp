#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int Nmax=1000+30;
int a[Nmax],b[Nmax];
int DP[Nmax][Nmax];
int sir[Nmax];
int l;
int n,m;
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;++i)fin>>a[i];
    for(int i=1;i<=m;++i)fin>>b[i];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        if(a[i]==b[j])DP[i][j]=DP[i-1][j-1]+1;
        else DP[i][j]=max(DP[i][j-1],DP[i-1][j]);
    for(int i=n,j=m;i;)
    {
        if(a[i]==b[j])
        {
            sir[++l]=a[i];
            --i;--j;
        }
        else if(DP[i-1][j]>DP[i][j-1])
        i--;
        else j--;
    }
    fout<<l<<'\n';
    for(int i=l;i>=1;i--)
        fout<<sir[i]<<" ";
    return 0;
}
