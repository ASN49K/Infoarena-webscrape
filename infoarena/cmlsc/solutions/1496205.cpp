#include <iostream>
#include <fstream>
#define nmax 1025
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m;
int a[nmax],b[nmax],v[nmax][nmax];


void solve()
{
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           if(a[i] == b[j])v[i][j]=v[i-1][j-1]+1;
           else v[i][j]=max(v[i-1][j],v[i][j-1]);
       }
   }
}
void write(int i,int j)
{
    if(!v[i][j])return;
    if(a[i] == b[j])
    {
        i--,j--;
        write(i,j);
        g<<a[i+1]<<" ";
    }
    else if(v[i-1][j] > v[i][j-1])write(i-1,j);
    else write(i,j-1);
}
void read()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)f>>a[i];
    for(int i=1;i<=m;i++)f>>b[i];
}
int main()
{
    read();
    solve();
    g<<v[n][m]<<"\n";
    write(n,m);
    return 0;
}
