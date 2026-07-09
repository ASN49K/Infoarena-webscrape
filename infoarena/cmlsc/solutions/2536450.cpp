#include <iostream>
#include <fstream>
#define DIM 1030

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m;
int a[DIM], b[DIM], d[DIM][DIM];

void drum(int i, int j) {
     if(i > 0 && j > 0) {
          if(a[i] == b[j]){
               drum(i-1, j-1);
               fout<<a[i]<<" ";
          }else{
               if (d[i][j-1] > d[i-1][j])
                    drum(i, j-1);
               else
                    drum(i-1, j);
          }
     }
}

int main(){
     fin>>n>>m;
     for(int i=1; i<=n; i++) fin>>a[i];
     for(int i=1; i<=m; i++) fin>>b[i];

     for(int i=1; i<=n; i++)
          for(int j=1; j<=m; j++)
               if(a[i] == b[j])
                    d[i][j]=1 + d[i-1][j-1];
               else d[i][j]=max(d[i-1][j], d[i][j-1]);


     fout<<d[n][m]<<"\n";
     drum(n,m);
     return 0;
}
