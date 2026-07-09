#include <fstream>
#include <iostream>
using namespace std;
ifstream ifs("cmlsc.in"); ofstream ofs("cmlsc.out");
int si[1025],sii[1025],mx[1025][1025],cmlsc[1025],m,n,t,s1,s2;

int main() {
  ifs>>m>>n;
  for(int i=1;i<=m;i++)
    ifs>>si[i];
  for(int i=1;i<=n;i++)
    ifs>>sii[i];
  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
      if(si[i]==sii[j]) {
        mx[i][j]=mx[i-1][j-1]+1;
        if(s1<i&&s2<j) {
          cmlsc[t]=si[i]; t++; s1=i; s2=j;
        }
      }
      else
        mx[i][j]=max(mx[i-1][j],mx[i][j-1]);
  ofs<<mx[m][n]<<'\n';
  for (int i=0;i<t;i++)
    ofs<<cmlsc[i]<<" ";
}
