#include<fstream>
using namespace std;
int a[1030][1030], x[1030],y[1030],rez[1030],m,n;

ofstream g("s2.out");
void CMLSC(){
  int i, j;
  //a si b au valori nule
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      if(x[i]==y[j])
	a[i][j]=a[i-1][j-1]+1;
      else
      if(a[i-1][j]>a[i][j-1])
	     a[i][j]=a[i-1][j];
      else
	     a[i][j]=a[i][j-1];

}
int main(){
  int i, j;
  ifstream f("s2.in");
  f>>n>>m;
  for(i=1;i<=n;i++)
    f>>x[i];
  for(j=1;j<=m;j++)
    f>>y[j];
  f.close();
  CMLSC();
  g<<a[n][m]<<'\n';
  int l=a[n][m];
  i=n;
  j=m;
  for(l;l;){
    if(x[i]==y[j]){
      rez[l]= x[i];
      l--;
      i--;
      j--;
    }
    else if(a[i-1][j]>a[i][j-1])  i--;
      else j--;
  }
  for(i=1;i<=a[n][m];i++)
    g<<rez[i]<<' ';
  g<<'\n';
  g.close();
  return 0;
}
