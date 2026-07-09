#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,v[1030],u[1030],i,j,pd[1030][1030],mx,d[1030],k;
int main()
{ f>>n>>m;
  for(i=1;i<=n;i++)f>>v[i];
  for(i=1;i<=m;i++)f>>u[i];
  for(i=1;i<=n;i++) for(j=1;j<=m;j++) { if(v[i]==u[j])pd[i][j]=1+pd[i-1][j-1];
										else pd[i][j]=max(pd[i-1][j],pd[i][j-1]);
										if(mx<pd[i][j])mx=pd[i][j];
									  }											
  g<<mx<<'\n';
  i=n;j=m;
  while(i&&j) if(v[i]==u[j])d[++k]=v[i],i--,j--;
			  else if(pd[i-1][j]>pd[i][j-1])i--;
				   else j--;
			  
  while(k)g<<d[k--]<<' ';
  f.close();
  g.close();
  return 0;
}