#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],n,m,c[1025][1025];
void tipar(int i,int j)
{
    if(i>=1 && j>=1)
    {
        if(a[i]!=b[j])
        {
            if(c[i][j-1]>c[i-1][j])tipar(i,j-1);
            else tipar(i-1,j);
        }
        else {
            tipar(i-1,j-1);
            g<<a[i]<<" ";
        }
    }
}
void solve()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j])c[i][j]=1+c[i-1][j-1];
        else
        {
            c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    g<<c[n][m]<<endl;
    tipar(n,m);
}

int main()
{
   f>>n>>m;
   for(int i=1;i<=n;i++)f>>a[i];
   for(int i=1;i<=m;i++)f>>b[i];
   solve();
    return 0;
}
