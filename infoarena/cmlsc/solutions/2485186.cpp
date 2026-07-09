#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int v1[1025],v2[1025],v[1025],n,m,i,j,a=1,b=1,z;
int main()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>v1[i];
    for(j=1; j<=m; j++)
        fin>>v2[j];
    for(i=a; i<=n; i++)
        for(j=b; j<=m; j++)
          if(v1[i]==v2[j])
          {
              z++;
              v[z]=v1[i];
              a=i+1;
              b=j+1;
          }
    fout<<z<<'\n';
    for(i=1; i<=z; i++)
        fout<<v[i]<<" ";
}
