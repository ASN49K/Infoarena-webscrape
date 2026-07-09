#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,k,i,j,a[1030],b[1030],v[1030][1030],x[1030],y[1030],val[1030],s,fix,nr,maxim,sol[1030],nr1;

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i]==b[j])
                {
                    for(k=0;k<=nr;k++)
                    {
                        if(x[k]<i && y[k]<j)
                        {
                        nr++;
                        x[nr]=i;
                        y[nr]=j;
                        val[nr]=val[k]+1;
                        v[i][j]=val[k]+1;
                        fix=1;
                        }
                    }
                    if(fix==0)
                        v[i][j]=1;
                }
            }
        }
    }
    fout<<nr-1<<endl;
    nr1=nr-1;
    nr=nr-1;
    for(i=n;i>=1;i--)
        for(j=m;j>=1;j--)
    {
        if(v[i][j]==nr)
        {
            sol[nr]=a[i];
            nr--;
        }
    }
    for(i=1;i<=nr1;i++)
        fout<<sol[i]<<" ";
}
