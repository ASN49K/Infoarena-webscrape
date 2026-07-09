#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int x[1030][1030],a[1030],b[1030],f[1030];
int main()
{
    int n,m,i,j,pozi,pozj;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
            fin>>a[i];
            x[i][0]=0;
    }
    for(i=1;i<=m;i++)
    {
            fin>>b[i];
            x[0][i]=0;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j])
        {
            x[i][j]=x[i-1][j-1]+1;
        }
        else
            x[i][j]=max(x[i-1][j],x[i][j-1]);
    i=n;j=m;
    int k=0;
    while(i!=0 && j!=0)
    {
        if(a[i]==b[j])
        {
            f[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(x[i][j-1]>x[i-1][j])
                j--;
            else
                i--;

        }
    }
    fout<<x[n][m]<<'\n';
    for(i=k;i>=1;i--)
        fout<<f[i]<<" ";
    return 0;
}
