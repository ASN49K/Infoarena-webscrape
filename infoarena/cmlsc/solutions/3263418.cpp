#include <fstream>
using namespace std;
int d[1024][1024], a[1024], b[1024], s[1025];
int main(){
  ifstream fin("cmlsc.in");
  ofstream fout("cmlsc.out");
  int n, m;
  fin>>n>>m;
  for(int i=1; i<=n; i++)
    fin>>a[i];
  for(int i=1; i<=m; i++)
    fin>>b[i];
  for(int i=1;i<=n;i++){
    for(int j=1; j<=m; j++){
      d[i][j]=max(d[i-1][j-1]+(a[i]==b[j]), d[i][j]);
      d[i][j]=max(d[i][j], d[i][j-1]);
      d[i][j]=max(d[i][j], d[i-1][j]);
    }
  }
  fout<<d[n][m]<<endl;
  int i=n, j=m, cnt=0;
  while(i>=1&&j>=1){
    if(a[i]==b[j]){
      s[++cnt]=a[i];
      i--, j--;
    }
    else{
      if(d[i][j]==d[i-1][j])
        i--;
      else j--;
    }
}
for(int k=cnt; k>=1; k--)
  fout<<s[k]<<" ";
  return 0;
}
