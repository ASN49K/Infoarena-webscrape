#include<fstream>
#include<iostream>
#define Nmax 100
using namespace std;
int a[Nmax],b[Nmax],c[Nmax][Nmax],d[Nmax],n,m,k;
void citeste()
{
    int i;
    ifstream f("cmlsc.in");
    f>>n>>m;
    for(i=1;i<=n;i++)
    f>>a[i];
    for(i=1;i<=m;i++)
    f>>b[i];
}
void rezolva()
{
    int i,j;
    ofstream g("cmlsc.out");
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j])
    {
        c[i][j]=c[i-1][j-1]+1;
        d[++k]=a[i];
    }
    else
    c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<c[n][m]<<'\n';
    for(i=1;i<=k;i++)
    g<<d[i]<<" ";
    g<<endl;
}
int main()
{
    citeste();
    rezolva();
return 0;
}
