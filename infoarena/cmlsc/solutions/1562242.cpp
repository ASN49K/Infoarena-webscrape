#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,v[1024][1024],i,j,nr=1,q[1024];

int main()
{
   fin>>n>>m;
   for(i=1;i<=n;i++)
        fin>>v[0][i];

   for(i=1;i<=m;i++)
        fin>>v[i][0];

   for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
          if(v[i][0]==v[0][j])
             {
              v[i][j]=1;
             }

    for(i=1;i<=max(n,m);i++)
        for(j=i;j<=max(n,m);j++)
        {
         if(v[i][j]==1 || v[j][i]==1)
            {
             q[nr]=v[0][j];
             nr++;
             j=max(n,m);
            }
        }
   fout<<nr-1<<'\n';
   for(i=1;i<=nr-1;i++)
        fout<<q[i]<<" ";

    return 0;
}
