#include <fstream>

using namespace std;

int n,m;
int a[1024];
int b[1024];
short q[1024][1024];

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void solutie(int l, int c)
{
  if(l==0 or c==0)
    return;
  if(a[l]==b[c])
  {
    solutie(l-1,c-1);
    g<<a[l]<<" ";
  }
  else
    if(q[l-1][c]<=q[l][c-1])
      solutie(l,c-1);
    else
      solutie(l-1,c);
}

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
      f>>a[i];
    for(int j=1;j<=m;j++)
      f>>b[j];
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        if(a[i]==b[j])
          q[i][j]=1+q[i-1][j-1];
        else
          q[i][j]=max(q[i-1][j],q[i][j-1]);
    g<<q[n][m]<<'\n';
    solutie(n,m);
    f.close();
    g.close();
    return 0;
}
