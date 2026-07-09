#include <fstream>

using namespace std;
int n,m,i,j,f[1030][1030],v[1030],a[1030],b[1030],k;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for(i=1;i<=n;i++)fin>>a[i];
    for(i=1;i<=m;i++)fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])f[i][j]=1+f[i-1][j-1];
        else f[i][j]=max(f[i-1][j],f[i][j-1]);
    }
    for(i=n,j=m; i and j;)
    {
        if(a[i]==b[j])v[++k]=a[i],i--,j--;
        else if(f[i-1][j]<f[i][j-1])j--;
        else i--;
    }
    fout<<k<<"\n";
    for(i=k;i>=1;i--)fout<<v[i]<<" ";
    return 0;
}
