#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int R[1300][1301],b[1301],a[1301],c[13001];
int k,n,m,i,j;
void constructie(int i,int j)
{
    if(R[i][j]>0)
    {
        if(a[i]==b[j])
        {
           constructie(i-1,j-1);
            k++;
            c[k]=a[i];
        }else
        {
            if(R[i-1][j]>R[i][j-1])constructie(i-1,j);
            else constructie(i,j-1);
        }
    }
}

int main()
{
  fin>>n>>m;
  for(i=1;i<=n;i++)fin>>a[i];
  for(i=1;i<=m;i++)fin>>b[i];

  for(i=1;i<=n;i++)
  {
      for(j=1;j<=m;j++)
      {
          if(a[i]==b[j])R[i][j]=R[i-1][j-1]+1;
          else R[i][j]=max(R[i][j-1],R[i-1][j]);
      }
  }
  constructie(n,m);
fout<<R[n][m];
  for(i=1;i<=k;i++)fout<<c[i]<<' ';
    return 0;
}
