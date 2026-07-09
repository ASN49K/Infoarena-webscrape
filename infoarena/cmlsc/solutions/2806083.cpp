#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int i,j,n,m,v[1025][1025],l,a[1025],b[1025],sol[1025];
int main()
{
fin>>n;fin>>m;
for(i=1;i<=n;i++)fin>>a[i];
for(i=1;i<=m;i++)fin>>b[i];
for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
        if(a[i]==b[j])v[i][j]=1+v[i-1][j-1];
        else v[i][j]=max(v[i-1][j],v[i][j-1]);

fout<<v[n][m]<<'\n';
 l=v[n][m];
 i=n;j=m;
 while(l){
    if(a[i]==b[j])
    {
        sol[l]=a[i];
        l--;i--;j--;
    }
    else if(v[i-1][j]<v[i][j-1])
        j--;
    else i--;
 }
 for(i=1;i<=v[n][m];i++)fout<<sol[i]<<" ";
    return 0;
}
