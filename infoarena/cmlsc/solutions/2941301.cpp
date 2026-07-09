#include <iostream>
#include <fstream>

#define MAX_LIN_COL 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int mat[MAX_LIN_COL][MAX_LIN_COL], v1[MAX_LIN_COL], v2[MAX_LIN_COL], sir[MAX_LIN_COL];

int main()
{
    int n,m,i,j,k;
    fin>>n>>m;
    for(i=1;i<=n;i++){
      fin>>v1[i];
    }
    for(i=1;i<=m;i++){
      fin>>v2[i];
    }
    for(i=1;i<=n;i++){
      for(j=1;j<=m;j++){
        if(v1[i]==v2[j]){
          mat[i][j]=mat[i-1][j-1]+1;
        }
        else{
          if(mat[i-1][j]>mat[i][j-1]){
            mat[i][j]=mat[i-1][j];
          }
          else{
            mat[i][j]=mat[i][j-1];
          }
        }
      }
    }
    fout<<mat[n][m]<<'\n';
    i=n;
    j=m;
    k=0;
    while(mat[i][j]>0){
      if(v1[i]==v2[j]){
        k++;
        sir[k]=v1[i];
        i--;
        j--;
      }
      else{
        if(mat[i-1][j]>mat[i][j-1]){
          i--;
        }
        else{
          j--;
        }
      }
    }
    while(k>0){
      fout<<sir[k]<<" ";
      k--;
    }
    return 0;
}
