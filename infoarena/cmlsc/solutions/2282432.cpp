#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int N = 1030;
int n,m,a[N],b[N],v[N][N],i,j;
void afisare(int,int);

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            v[i][j]=a[i]==b[j]?1+v[i-1][j-1]:max(v[i-1][j],v[i][j-1]);
    fout<<v[n][m]<<'\n';
    afisare(n,m);
    return 0;
}
void afisare(int i,int j)
{
    if(!v[i][j])return;
    if(a[i]==b[j]){afisare(i-1,j-1);fout<<a[i]<<' ';return;}
    if(v[i-1][j]>=v[i][j-1])afisare(i-1,j);
    else afisare(i,j-1);
}
