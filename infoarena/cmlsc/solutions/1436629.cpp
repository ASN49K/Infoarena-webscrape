#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,b[1030][1030],a[1030];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i][0];
    for(j=1;j<=n;j++)
        if(b[1][j-1]==1||b[1][0]==a[j])
            b[1][j]=1;
        else
            b[1][j]=0;
    for(i=2;i<=m;i++)
    {
        if(b[i][0]==a[1])
            b[i][1]=1;
        else
        {
            b[i][j]=max(b[i-1][1],0);
        }
        for(j=2;j<=n;j++)
        if(b[i][0]==a[j])
            b[i][j]=b[i-1][j-1]+1;
        else
        {
            b[i][j]=max(b[i-1][j],b[i-1][j-1]);
            b[i][j]=max(b[i][j],b[i][j-1]);
        }
    }
    fout<<b[m][n]<<'\n';
    i=m;
    j=n;
    while(b[i][j]!=0&&j>0)
    {
        if(b[i][j-1]==b[i][j])
            j--;
        else
        if(b[i-1][j]==b[i][j])
            i--;
        else
        if(b[i-1][j-1]==b[i][j])
        {
            i--;
            j--;
        }
        else
        if(b[i-1][j-1]==b[i][j]-1)
        {
            a[b[i][j]]=b[i][0];
            i--;
            j--;
        }
    }
    for(i=1;i<=b[m][n];i++)
        fout<<a[i]<<" ";
    return 0;
}
