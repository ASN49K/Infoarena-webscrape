#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,i,v1[1025],v2[1025],a[1026][1026],m,j,rez[1025],k;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;++i)
        fin>>v1[i];
    for(i=1;i<=m;++i)
        fin>>v2[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(v1[i]!=v2[j])
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            else
                a[i][j]=a[i-1][j-1]+1;
    fout<<a[n][m]<<'\n';
    i=n;j=m;
    while(a[i][j]!=0)
        if(v1[i]==v2[j])
            {
                rez[++k]=v1[i];
                i--;
                j--;
            }
        else
        {
        if(a[i-1][j]==a[i][j])
            i--;
            else
            j--;
        }
    for(i=k;i>=1;--i)
    fout<<rez[i]<<" ";
    return 0;
}
