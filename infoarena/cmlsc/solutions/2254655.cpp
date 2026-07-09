#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int N = 1030;
int n,m,a[N],b[N],d[N][N],i,j;
void afisare(int,int);

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)f>>a[i];
    for(i=1;i<=m;i++)f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            d[i][j]=a[i]==b[j]?1+d[i-1][j-1]:max(d[i-1][j],d[i][j-1]);
    g<<d[n][m]<<'\n';
    afisare(n,m);
    return 0;
}
void afisare(int i,int j)
{
    if(!d[i][j])return;
    if(a[i]==b[j]){afisare(i-1,j-1);g<<a[i]<<' ';}
    if(d[i-1][j]>=d[i][j-1])afisare(i-1,j);
    else afisare(i,j-1);
}
