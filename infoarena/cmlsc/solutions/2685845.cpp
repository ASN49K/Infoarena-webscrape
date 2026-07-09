#include <iostream>
#include <fstream>
#define Nmax 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short LCS[Nmax][Nmax];
int main()
{
    short n,m,a[Nmax],b[Nmax],i,j;
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        fin>>a[i];
    for(i=1; i<=m; ++i)
        fin>>b[i];
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            if(a[i]==b[j])LCS[i][j]=1+LCS[i-1][j-1];
            else LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
        }
    fout<<LCS[n][m]<<'\n';
    i=n;
    j=m;
    short k=0,final[Nmax];
    while(i!=1 && j!=1)
    {
        short val = LCS[i][j]-1;
        if(LCS[i-1][j-1]==val)
        {
            final[LCS[n][m]-k]=a[i];
            ++k;
            --i;
            --j;
        }
        else
        {
            if(LCS[i][j]==LCS[i][j-1])--j;
            else --i;
        }
    }
    ++k;
    while(i!=1)
    {
        if(LCS[i-1][j]==0){final[1]=a[i];break;}
        --i;
    }
    while(j!=1)
    {
        if(LCS[i][j-1]==0){final[1]=b[j];break;}
        --j;
    }
    for(i=1; i<=k; ++i)
    {
        fout<<final[i]<<" ";
    }
    fout<<'\n';
    return 0;
}
