#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n,m,vn[1025],vm[1025],sol[1025],poz=0;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>vn[i];
    for(int i=1;i<=m;i++)
        fin>>vm[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(vn[i]==vm[j]){
                poz++;
                sol[poz]=vn[i];
            }
    fout<<poz<<"\n";
    for(int i=1;i<=poz;i++)
        fout<<sol[i]<<" ";
}
