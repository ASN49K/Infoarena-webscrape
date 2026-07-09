#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,i,j,l[100001],k,a[1025][1025],b[100001];
long v[100001],m;
int main()
{
    k=1;
    fin>>n>>m;
    a[1][1]=0;
    for(i=1;i<=n;i++)
        fin>>v[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(v[j]==b[i])
        {a[i][j]+=k;k++;}
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(a[i][j]!=0)
            fout<<b[i]<<" ";


    return 0;
}
