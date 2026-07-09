#include<fstream.h>
const MAX=1025;
ofstream g("cmlsc.out");
int x[MAX][MAX],a[MAX],b[MAX];

int max(int a,int b)
{
  if(a>b)return a;
  return b;
}

void urma(int i,int j)
{
  if(i && j)
    if(b[i]==a[j]){urma(i-1,j-1);g<<b[i]<<' ';}
    else if(x[i][j-1]>x[i-1][j])urma(i,j-1);
	 else urma(i-1,j);
}

int main()
{
  ifstream f("cmlsc.in");
  int p,q,i,j;
  f>>p>>q;
  for(i=1;i<=p;i++)f>>a[i];
  f>>b[1];
  for(i=1;i<=p;i++)
    if(b[1]==a[i])x[1][i]=1;else x[1][i]=0;
  for(i=2;i<=q;i++)
  {
    f>>b[i];
    if(b[i]==a[1])x[i][1]=1;
    for(j=2;j<=p;j++)
      if(b[i]==a[j])x[i][j]=1+x[i-1][j-1];
      else x[i][j]=max(x[i-1][j],x[i][j-1]);
  }
  g<<x[q][p]<<'\n';
  urma(q,p);
  f.close();g.close();
  return 0;
}