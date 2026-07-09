#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int valid(int &x, int &y,int k)
{for(int i=1;i<=k;i++)
        if(x==y)
            return 0;
            return 1;

        }
int main()
{
    int a[1025],b[1025],n,m,L[1025][1025],i,j,e[1025],k=1;
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(i=1;i<=m;i++)
        in>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
          if(a[i]==b[j])
    {L[i][j]=L[i-1][j-1]+1;
    if(valid(e[k],a[i],k))
     { e[k]=a[i]; k++;} }
          else
          L[i][j]=max(L[i-1][j],L[i][j-1]);
        out<<L[n][m]<<"\n";
        for(i=1;i<=k-1;i++)
          out<<e[i]<<" ";

        }
