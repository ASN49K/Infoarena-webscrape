#include<iostream>
#include<fstream>
using namespace std;
int l[1025][1025],a[1025],b[1025],i,j,m,n;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
void rezolva()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j]) l[i][j]=l[i-1][j-1]+1;
    else if(l[i-1][j]>l[i][j-1]) l[i][j]=l[i-1][j];
    else l[i][j]=l[i][j-1];
}

void afiseaza(int i,int j)
{if(l[i][j])
    if(a[i]==b[j]) {afiseaza(i-1,j-1); g<<a[i]<<" ";}
    else if(l[i-1][j]==l[i][j]) afiseaza(i-1,j);
    else if(l[i][j]==l[i][j-1]) afiseaza(i,j-1);

}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    rezolva();
    g<<l[n][m]<<'\n';
    afiseaza(n,m);
}
