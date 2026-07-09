#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int MAX=1030;
int N , M , A[MAX] , B[MAX] , mat[MAX][MAX];
int main()
{ fin >> N >> M;
  for(int i=1;i<=N;i++)
   fin >> A[i];
  for(int i=1;i<=M;i++)
   fin >> B[i];
  for(int i=1;i<=M;i++)
    for(int j=1;j<=N;j++)
      mat[i][j]=max(mat[i-1][j],mat[i][j-1])+(A[j]==B[i]);
  fout << mat[M][N] << '\n';
  /*for(int i=1;i<=M;i++)
  { for(int j=1;j<=N;j++)
      fout << mat[i][j] << ' ';
    fout << '\n';
  }*/
  int i=M,j=N,x=mat[M][N]+1;
  while(i>0&&j>0)
  { while(mat[i][j]==mat[i][j-1]&&j>0)
     j--;
    if(mat[i][j]>0)
      B[--x]=A[j];
    if(j==0)
     i--,j=N;
    else i--,j--;
  }
  for(int i=1;i<=mat[M][N];i++)
    fout << B[i] << ' ';
    return 0;
}
