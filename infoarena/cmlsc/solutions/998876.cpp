#include <fstream>
#include <iostream>
using namespace std;
ifstream ifs("cmlsc.in"); ofstream ofs("cmlsc.out");
int SI[1025],SII[1025],MX[1025][1025],cmlsc[1025],M,N,t;

int main() {
  ifs>>M>>N;
  for(int i=1;i<=M;i++)
    ifs>>SI[i];
  for(int i=1;i<=N;i++)
    ifs>>SII[i];
  for(int i=1;i<=M;i++)
    for(int j=1;j<=N;j++)
      if(SI[i]==SII[j]) {
        MX[i][j]=MX[i-1][j-1]+1;
        cmlsc[t]=SI[i]; t++;
      }
      else
        MX[i][j]=max(MX[i-1][j],MX[i][j-1]);
  ofs<<MX[M][N]<<'\n';
  for (int i=0;i<t;i++)
    ofs<<cmlsc[i]<<" ";
}
