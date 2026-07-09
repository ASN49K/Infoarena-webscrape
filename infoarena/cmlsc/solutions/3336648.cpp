#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int vn[1024],vm[1024],vf[1024];
int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>vn[i];
    }
    for(int i=1;i<=m;i++)
    {
        fin>>vm[i];
    }
    int nr=0,x=1;
    for(int i=1;i<=n;i++)
    {
        for(int ii=1;ii<=m;ii++)
        {
            if(vn[i]==vm[ii])
            {
                nr++;
                vf[x]=vn[i];
                x++;
            }
        }
    }
    fout << nr<<endl;
    for(int i=1;i<x;i++)
    {
        fout<<vf[i]<<" ";
    }
    return 0;
}
