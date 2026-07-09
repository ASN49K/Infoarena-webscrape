#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int d[1026][1026],a[1026],b[1026],n,m;
void rec(int i,int j,int k)
{
    if(k!=0)
    {
        if(a[i]==b[j])
        {
            rec(i-1,j-1,k-1);
            fout<<a[i]<<" ";
        }
        else
        {
            if(d[i][j-1]>d[i-1][j])
                rec(i,j-1,k);
            else
                rec(i-1,j,k);
        }
    }
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int j=1;j<=m;j++)
        fin>>b[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    fout<<d[n][m]<<"\n";
    rec(n,m,d[n][m]);
    return 0;
}
