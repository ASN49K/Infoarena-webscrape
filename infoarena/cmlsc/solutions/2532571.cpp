#include <iostream>
#include <fstream>

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m;
int d[1005][1005], v[1005], w[1005];

void afis(int i, int j, int k){
      if(k != 0){
            if(v[i] == w[j]){
                  afis(i-1, j-1, k-1);
                  fout<<v[i]<<" ";
            }else{
                  if(d[i-1][j] > d[i][j-1])
                        afis(i-1, j, k);
                  else  afis(i, j-1, k);
            }
      }
}

int main (){

      fin>>n>>m;
      for(int i=1; i<=n; i++) fin>>v[i];
      for(int i=1; i<=m; i++) fin>>w[i];

      for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                  if(v[i] == w[j])
                        d[i][j]=d[i-1][j-1]+1;
                  else  d[i][j]=max(d[i-1][j], d[i][j-1]);


      fout<<d[n][m]<<"\n";
      afis(n, m, d[n][m]);

      return 0;
}
