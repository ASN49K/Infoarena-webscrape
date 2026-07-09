#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream f("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX=1025;

int n, m, mat[NMAX][NMAX], soll=1, a[NMAX], b[NMAX], sol[NMAX];





int main()
{
   f>>n>>m;
   int z;
    for(int i=1;i<=n;++i)
        f>>a[i];
    for(int i=1;i<=m;++i)
        f>>b[i];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i]==b[j])
                mat[i][j]=1+mat[i-1][j-1];
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);

    fout<<mat[n][m]<<'\n';

    int i=n,j=m;
    int k=0;
    while(i>=1)
        if(a[i]==b[j])
        {
            sol[++k]=a[i];
            --i;
            --j;
        }
        else if(mat[i-1][j]<mat[i][j-1])
            --j;
        else
            --i;
    for (int i =1; i<=k; ++i)
        fout<<sol[i]<<" ";
    return 0;
}
