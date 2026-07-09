#include <fstream>
#define N 1030
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int t[N][N];
int a[N],b[N],ans[3000];
int main()
{
    int i,j,n,m,cnt=0;
    fin>>n>>m;
    for(i=1;i<=n;++i)
    {
        fin>>a[i];
    }
    for(j=1;j<=m;++j)
    {
        fin>>b[j];
    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            if(a[i]==b[j])
            {
                t[i][j]=t[i-1][j-1]+1;
            }
            else
                t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    fout<<t[n][m]<<'\n';
    i=n;
    j=m;
    while(i>0 || j>0)
    {
        if(a[i]==b[j])
        {
            ans[cnt++]=a[i];
            i--;
            j--;
        }
        else
        {
            if(t[i-1][j]>t[i][j-1] && i>1)
            {
                --i;
            }
            else if(t[i-1][j]<=t[i][j-1] && j>1)
                --j;
            else
            {
                if(i>1)
                    --i;
                else if(j>1)
                    --j;
                else
                    break;
            }
        }
    }
    for(i=cnt-1;i>=0;--i)
        fout<<ans[i]<<' ';
    return 0;
}
