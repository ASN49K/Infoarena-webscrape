#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1027][1027],v[1027],x[1027];
int main()
{
    int i,j,n,m,k=1;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>v[i];
    for(i=1;i<=m;i++)
        fin>>x[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(v[j]==x[i])
        a[i][j]=a[i-1][j-1]+1;
    else
        a[i][j]=max(a[i-1][j],a[i][j-1]);
        fout<<a[m][n]<<'\n';
    for(i=0;i<=m;i++)
        for(j=0;j<=n;j++)
            if(a[i][j]==k)
        {
            fout<<x[i]<<" ";
            k++;
        }

}
