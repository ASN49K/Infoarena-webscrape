#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1028],b[1028],v[1028][1028];
void afis(int i, int j)
{
    if (!(i*j)) return;
    if (a[i]==b[j])
        {
            afis(i-1,j-1);
            fout<<a[i]<<' ';
        }
    else
        {
            if (v[i-1][j]>v[i][j-1]) afis(i-1,j);
            else afis(i,j-1);
        }
}
int main()
{
    int i,j;
    fin>>n>>m;
    for (i=1;i<=n;++i)
        fin>>a[i];
    for (i=1;i<=m;++i)
        fin>>b[i];
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j)
            if (a[i]==b[j]) v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=max(v[i-1][j],v[i][j-1]);
    fout<<v[n][m]<<'\n';
    afis(n,m);
    fout<<'\n';
    return 0;
}
