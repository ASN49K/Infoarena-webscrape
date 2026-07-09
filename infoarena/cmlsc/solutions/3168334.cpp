#include <fstream>
#include <cstring>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,D[1027][1027],i,j,a[1027],b[1027];
void drum(int i,int j,int l)
{
    if(l>0)
    {
        if(a[i]==b[j])
        {
            drum(i-1,j-1,l-1);
            fout<<a[i]<<" ";
        }
        else
            if(D[i-1][j]>D[i][j-1])
                drum(i-1,j,l);
            else
                drum(i,j-1,l);
    }
}


int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);
        }
    }
    fout<<D[n][m]<<"\n";
    drum(n,m,D[n][m]);
    return 0;
}
