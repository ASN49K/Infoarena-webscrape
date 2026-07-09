#include <iostream>
#include <fstream>
using namespace std;

#define NMAX 1026

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int matrix[NMAX][NMAX];
int sir1[NMAX],n;
int sir2[NMAX],m;
int result[NMAX],k=0;

int maximum(int a, int b){
   return a>b?a:b;
}

void citire(int sir1[],int sir2[],int& n,int& m){
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>sir1[i];
    for(int i=1;i<=m;i++)
        f>>sir2[i];
}

void recursion(int i, int j){
   if(matrix[i][j]==0)
      return;
   if(matrix[i][j] > matrix[i-1][j] &&
      matrix[i][j] > matrix[i][j-1]){
          result[++k]=sir1[i];
          recursion(i-1,j-1);
   }
   else if(matrix[i][j-1] > matrix[i-1][j]){
    recursion(i,j-1);
   }
   else
    recursion(i-1,j);
}

int longest_common_subsequence(int matrix[NMAX][NMAX],int result[],int sir1[],
                                int sir2[],int n, int m, int& k){
    sir1[0]=sir2[0]=0;
    for(int i=1; i<=n; i++)
      for(int j=1;j<=m;j++){
        if( sir1[i] == sir2[j] ){
            matrix[i][j] = matrix[i-1][j-1] + 1;
          }
        else
            matrix[i][j] = maximum(matrix[i][j-1],matrix[i-1][j]);
    }
    return matrix[n][m];
}

int main()
{
   citire(sir1,sir2,n,m);
   g<<longest_common_subsequence(matrix,result,sir1,sir2,n,m,k)<<"\n";
   recursion(n,m);
   for(int i=k;i>=1;i--)
    g<<result[i]<<" ";

}
