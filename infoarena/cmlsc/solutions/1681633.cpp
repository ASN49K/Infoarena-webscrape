#include <iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,d[1030][1030],a[1030],b[1030],i,j;
void afis(int i, int j){
if(i==0||j==0)return;
if(a[i]==b[j]){
    afis(i-1,j-1);
    g<<a[i]<<" ";
    return;}
    if(d[i-1][j]>d[i][j-1])
        afis(i-1,j);
    else
        afis(i,j-1);
}

int main()
{f>>n>>m;
  for(i=1;i<=n;i++)f>>a[i];
  for(i=1;i<=m;i++)f>>b[i];

  for(i=1;i<=n;i++)
  for(j=1;j<=m;j++){
    if(a[i]==b[j])d[i][j]=1+d[i-1][j-1];
    else d[i][j]=max(d[i-1][j],d[i][j-1]);
  }
  g<<d[n][m]<<"\n";
  afis(n,m);
    return 0;
}
