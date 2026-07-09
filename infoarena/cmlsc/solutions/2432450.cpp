#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
/*int maxim(int &x, int &y)
{
    if(x>y)
        return x;
    else
        return y;
}*/
int main()
{  int n,m,i,j,L[101][101],a[101],b[101],e[1025][1025];
    in>>m>>n;
    for(i=1;i<=m;i++)
        in>>a[i];
    for(i=1;i<=n;i++)
        in>>b[i];
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
          if(a[i]==b[j])
          {
              L[i][j]=1+L[i-1][j-1];
              e[i][j]=1;

          }
          else
          {
              L[i][j]=max(L[i-1][j],L[i][j-1]);
              e[i][j]=0;

          }
    }

    out<<L[m][n]<<endl;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(e[i][j])
        out<<a[i]<<" ";

    in.close();
    out.close();
    return 0;
}
