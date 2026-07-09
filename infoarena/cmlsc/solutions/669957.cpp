#include<iostream>
#include<fstream>
#include<cstring>
#define lmax 1030
using namespace std;
ifstream f("cmlsc.in",fstream::in);
ofstream g("cmlsc.out",fstream::out);
short int a[lmax],b[lmax],c[lmax][lmax],n,sol[lmax],m;
int maxim(short int a,short int b)
{
    if(a>b)
    return a;
    else
    return b;
}
void read()
{
    short int i;
    f>>n>>m;
    for(i=1;i<=n;i++)
    f>>a[i];
    for(i=1;i<=m;i++)
    f>>b[i];
}
void solve()
{
    short int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
     if(a[i]==b[j])
      c[i][j]=c[i-1][j-1]+1;
      else
      c[i][j]=maxim(c[i-1][j],c[i][j-1]);
}
void show_m()
{
    short int i,j;
    for(i=1;i<=n;i++)
     {
         for(j=1;j<=m;j++)
         cout<<c[i][j]<<" ";
         cout<<"\n";
     }
     cout<<"\n\n";
}
void make_sol()
{
    short int i,j;
    i=n,j=m;
    for(;i&&j;)
    if(a[i]==b[j])
    sol[++sol[0]]=a[i],i--,j--;
    else
    if(c[i-1][j]>c[i][j-1])
    i--;
    else
    j--;
}
void show_sol()
{
    for(short int i=sol[0];i>=1;i--)
    g<<sol[i]<<" ";
}
int main()
{
    read();
    solve();
    g<<c[n][m]<<"\n";
    make_sol();
    show_sol();
    f.close();
    g.close();
    return 0;
}
