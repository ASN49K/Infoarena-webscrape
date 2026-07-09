#include<fstream>
#include<cstring>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,i,j,x[1110][1110],a[1110],b[1110];


void afis(int i, int j)
{
    if(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            afis(i-1,j-1);
            fout<<a[i]<<' ';
        }
        else
            if(x[i-1][j]>x[i][j-1] && i>1)
                afis(i-1,j);
            else
                afis(i,j-1);
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
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                x[i][j]=x[i-1][j-1]+1;
            else
                x[i][j]=max(x[i-1][j],x[i][j-1]);
        }
    fout<<x[n][m]<<'\n';
    afis(n,m);
    return 0;
}
