#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.out");
ofstream fout ("cmlsc.out");
int vn[1024],vm[1024],pn[1024],pm[1024],x[1024];
int main()
{
    int n,m,nr=0;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>vn[i];
    }
    for(int i=1;i<=m;i++)
    {
        fin>>vm[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int ii=1;ii<=m;ii++)
        {
            if(vn[i]==vm[ii] && pn[i]==0 && pm[ii]==0)
            {
                nr++;
                pn[i]=1;
                pm[ii]=1;
                ii+m;
                x[nr]=vn[i];
            }
        }
    }
    fout <<nr<<endl;
    for(int i=1;i<=nr;i++)
    {
        fout<<x[i]<<" ";
    }
    return 0;
}
