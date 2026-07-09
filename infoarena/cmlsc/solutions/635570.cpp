#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX_N 1025
using namespace std;
short a[MAX_N],b[MAX_N],n,m,d[MAX_N][MAX_N];

void citire();

int main()
{
    int sir[MAX_N],i,j,bst=0;
    citire();
    for(i=1;i<=m;++i)
        for(j=1;j<=n;++j)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
    for (i = m, j = n; i; )
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
    ofstream fout("cmlsc.out");
    fout<<bst<<'\n';
    for (i=bst;i;--i)
        fout<<sir[i]<<" ";
    fout.close();
    return 0;
}

void citire()
{
    ifstream fin("cmlsc.in");
    fin>>m>>n;
    for(int i=1;i<=m;++i)
        fin>>a[i];
    for(int i=1;i<=n;++i)
        fin>>b[i];
    fin.close();
}
