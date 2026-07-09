#include <fstream>
#include <cmath>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,a[1030],b[1030],d[1030][1030],sir[1030],k;

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
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    for(i=n,j=m;i;)
    {
        if(a[i]==b[j])
        {
            sir[++k]=a[i];
            i--;j--;
        }
        else
        {
            if(d[i-1][j]>=d[i][j-1])
                i--;
            else j--;
        }
    }
    fout<<k<<'\n';
    for(i=k;i>=1;i--){
        fout<<sir[i];
        if(i!=1)
            fout<<' ';
    }
    return 0;
}
