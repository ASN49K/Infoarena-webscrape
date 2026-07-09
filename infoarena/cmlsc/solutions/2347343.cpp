#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[1100],b[1100],v[1100][1100],i;
void citire()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>a[i];
    for(i=1;i<=n;i++) f>>b[i];
}
void dinamica()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j])
        v[i][j]=v[i-1][j-1]+1;
    else
        v[i][j]=max(v[i-1][j],v[i][j-1]);
}
void afisare(int i,int j)
{
    if(v[i][j])
        if(a[i]==b[j])
        afisare(i-1,j-1),g<<a[i]<<" ";
    else
        if(v[i][j]==v[i-1][j])
        afisare(i-1,j);
    else
        afisare(i,j-1);
}
int main()
{
    citire();
    dinamica();
    g<<v[n][m]<<endl;
    afisare(n,m);

	return 0;
}
