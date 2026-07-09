#include<fstream>
#include<iostream>
#define Nmax 1024
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[Nmax],b[Nmax],c[Nmax][Nmax],d[Nmax],n,m,k;
void citeste()
{
    int i;
    f>>n>>m;
    for(i=1;i<=n;i++)
    f>>a[i];
    for(i=1;i<=m;i++)
    f>>b[i];
}
void rezolva()
{
    int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j])
    c[i][j]=c[i-1][j-1]+1;
    else
    c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<c[n][m]<<'\n';
}
void afisare(int i,int j)
{
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            d[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(c[i-1][j]<c[i][j-1])
            j--;
            else
            i--;
        }
    }
    for(i=k;i>=1;i--)
    g<<d[i]<<" ";
}
int main()
{
    citeste();
    rezolva();
    afisare(n,m);
return 0;
}
