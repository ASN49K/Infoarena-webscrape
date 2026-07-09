#include <iostream>
#include <fstream>

using namespace std;

int v[1025][1025],nr[1024],mr[1024];

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m;
    f>>n>>m;
    int i,j;
    for(i=0;i<n;i++)f>>nr[n-i-1];
    for(i=0;i<m;i++)f>>mr[m-i-1];
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)
    {
        if(nr[i-1]==mr[j-1])v[i][j]=1+v[i-1][j-1];
        else v[i][j]=max(v[i-1][j],v[i][j-1]);
    }
    g<<v[n][m]<<'\n';
    for(i=n,j=m;i!=0&&j!=0;)
    {
        if(nr[i-1]==mr[j-1])
        {
            g<<nr[i-1]<<' ';
            i--;
            j--;
        }
        else if(v[i-1][j]==v[i][j])i--;
        else j--;
    }
}
