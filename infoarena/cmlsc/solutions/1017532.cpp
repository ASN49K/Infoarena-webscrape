#include <iostream>
#include <fstream>

using namespace std;

int a[1030],b[1030],v[1030][1030],aux[1030];

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int i,j,m,n,nr=0;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            v[i][j]=v[i-1][j-1]+1;
        else
            v[i][j]=max(v[i-1][j],v[i][j-1]);
    }
    i=n;
    j=m;
    while(v[i][j])
    {
        if(a[i]==b[j])
        {
             aux[++nr]=a[i];
             i--;
             j--;
        }
        else
        if(v[i][j]==v[i-1][j])
            i--;
        else
            j--;
    }
    fout<<v[n][m]<<"\n";
    for(i=nr;i>=1;i--)
        fout<<aux[i]<<" ";
    return 0;
}
