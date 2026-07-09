#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[102][102];
int x[102];
int y[102];

void afis(int ln,int co)
{
    if(a[ln][co]!=0)
    {
        if(y[ln]==x[co])
        {
            afis(ln-1,co-1);
            fout<<x[co]<<" ";
        }
        else
        {
            if(a[ln-1][co]>a[ln][co-1])
            {
                afis(ln-1,co);
            }
            else
            {
                afis(ln,co-1);
            }
        }
    }
}

int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>x[i];
    }
    for(int i=1;i<=m;i++)
    {
        fin>>y[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(y[i]==x[j])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else
            {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    fout<<a[m][n]<<"\n";
    int ln=m;
    int co=n;
    afis(ln,co);
    return 0;
}
