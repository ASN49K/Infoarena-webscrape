#include <iostream>
#include <fstream>
using namespace std;
int n,m,i,j,k;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],v[1025][1025];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(a[i]!=b[j])
            v[i][j]=max(v[i-1][j],v[i][j-1]);
        else
            v[i][j]=v[i-1][j-1]+1;
    }
    cout<<(int)v[n][m]<<'\n';
    i=n;
    j=m;
    while(i+j>0)
    {
        if(a[i]==b[j])
        {
            k++;
            a[k]=b[j];
            i--;j--;
        }
        else
        if(v[i-1][j]<v[i][j-1])
        j--;
        else
        i--;
    }
    for(i=k;i>0;i--)
        cout<<(int)a[i]<<' ';
}
