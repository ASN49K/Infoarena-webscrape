#include <fstream>
#define DIM 1030

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int a[DIM],b[DIM];
int d[DIM][DIM],tata[DIM][DIM];
int n,m,i,j;
void drum(int i, int j)
{
    if(d[i][j]>0)
    {
        if(a[i]==b[j])
        {
            drum(i-1,j-1);
            fout<<a[i]<<" ";
        }
        else
        {
            if(tata[i][j]==1)
                drum(i,j-1);
            else
                drum(i-1,j);
        }
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
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                if(d[i-1][j]>d[i][j-1])
                {
                    tata[i][j]=-1;
                    d[i][j]=d[i-1][j];
                }
                else
                {
                    tata[i][j]=1;
                    d[i][j]=d[i][j-1];
                }
    fout<<d[n][m]<<'\n';
    drum(n,m);
    return 0;
}
